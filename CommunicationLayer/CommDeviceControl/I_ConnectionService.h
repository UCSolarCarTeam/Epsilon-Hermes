#pragma once

#include <QObject>
#include <QString>

class I_ConnectionService : public QObject
{
    Q_OBJECT
public:
    virtual bool connectToDataSource() = 0;
    virtual void disconnectFromDataSource() = 0;
};
