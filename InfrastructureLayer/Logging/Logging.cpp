#include <iostream>

#include <QDebug>
#include <QFile>
#include <QDate>

#include "Logging.h"
#include <QCoreApplication>

namespace
{
QString LOG_DIR = "/log/";
QString LOG_NAME = "epsilon-hermes-";
QString LOG_DATE_FORMAT = "yyyy-MM-dd";
QString LOG_EXT = ".log";

QString LOG_DATETIME_FORMAT = "yyyy-MM-dd-hh-mm-ss-zzz-t";
QString DEBUG_MSG_FORMAT = "[%1] (%2, %3:%4) %5\n"; // datetime, file, function, line, msg
QString NON_DEBUG_MSG_FORMAT = "[%1] (%2) %3\n"; // datetime, file, msg
}

void Logging::init(int level)
{
    qInstallMessageHandler(Logging::logMessageHandler);

    switch (level)
    {
    case 4:
        logLevel_ = Logging::DEBUG;
        break;

    case 3:
        logLevel_ = Logging::INFO;
        break;

    case 2:
        logLevel_ = Logging::WARNING;
        break;

    case 1:
        logLevel_ = Logging::CRITICAL;
        break;

    case 0:
        logLevel_ = Logging::FATAL;
        break;

    default:
        logLevel_ = Logging::DEBUG;
        qWarning() << "Configured log level unrecognized. "
                   << "DEBUG=0,INFO=1,WARNING=2,CRITICAL=3,FATAL=4. "
                   << "Defaulting to DEBUG.";
        break;
    }

    // Because Epsilon Hermes is meant for a solar car
    // and competitions do not include night racing
    // It is quite unlikely to for the date to change while the car is running
    // So this assumes the date will not change while Epsilon Hermes is running
    QString todayStr = QDate::currentDate().toString(LOG_DATE_FORMAT);
    QString logName = QCoreApplication::applicationDirPath() + LOG_DIR + LOG_NAME + todayStr + LOG_EXT;
    logFile_.setFileName(logName);

    if (logFile_.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        logStream_.setDevice(&logFile_);
        qInfo() << "Logging Initialized";
    }
    else
    {
        std::cerr << "Logging initalization failed" << std::endl;;
        abort();
    }

}

QTextStream& Logging::logStream()
{
    return logStream_;
}

Logging::LogLevel Logging::logLevel()
{
    return logLevel_;
}

Logging& Logging::instance()
{
    static Logging instance_;
    return instance_;
}

// private

Logging::Logging()
    : logLevel_(LogLevel::INFO)
{
}

Logging::~Logging()
{
    logFile_.close();
}

void Logging::logMessageHandler(
    QtMsgType type,
    const QMessageLogContext& ctx,
    const QString& msg)
{
    // Construct string for current date time in UTC
    QDateTime nowDateTime = QDateTime::currentDateTimeUtc();
    QString nowStr = nowDateTime.toString(LOG_DATETIME_FORMAT);

    // Construct message
    QString logMsg;

    if (instance().logLevel() == LogLevel::DEBUG)
    {
        logMsg = QString(DEBUG_MSG_FORMAT).arg(
                     nowStr,
                     ctx.file,
                     ctx.function,
                     QString::number(ctx.line),
                     msg);
    }
    else
    {
        logMsg = QString(NON_DEBUG_MSG_FORMAT).arg(
                     nowStr,
                     ctx.file,
                     msg);
    }

    // Prepend log level
    switch (type)
    {
    case QtDebugMsg:
        if (instance().logLevel() > LogLevel::DEBUG)
        {
            return;
        }

        logMsg = "DEBUG: " + logMsg;
        break;

    case QtInfoMsg:
        if (instance().logLevel() > LogLevel::INFO)
        {
            return;
        }

        logMsg = "INFO: " + logMsg;
        break;

    case QtWarningMsg:
        if (instance().logLevel() > LogLevel::WARNING)
        {
            return;
        }

        logMsg = "WARNING: " + logMsg;
        break;

    case QtCriticalMsg:
        if (instance().logLevel() > LogLevel::CRITICAL)
        {
            return;
        }

        logMsg = "CRITICAL: " + logMsg;
        break;

    case QtFatalMsg:
        logMsg = "FATAL: " + logMsg;
        break;
    }

    // Finally print to file and also to stderr
    instance().logStream() << logMsg;
    instance().logStream().flush();
    fprintf(stderr, "%s", logMsg.toLocal8Bit().constData());

    // Abort program if FATAL call
    if (type == QtFatalMsg)
    {
        abort();
    }
}
