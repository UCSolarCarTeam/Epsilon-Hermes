#pragma once

#include <QScopedPointer>

class I_Settings;

class InfrastructureContainer
{
public:
    InfrastructureContainer();
    ~InfrastructureContainer();

    I_Settings& settings();

private:
    QScopedPointer<I_Settings> settings_;
};
