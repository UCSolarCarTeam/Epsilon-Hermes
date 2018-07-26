#pragma once

#include <QObject>
#include <QByteArray>

class I_MessageForwarder : public QObject
{
public:
    virtual ~I_MessageForwarder() {}
    virtual void forwardData(QByteArray data) = 0;
    virtual void forwardServerData(QByteArray data) = 0;
};
