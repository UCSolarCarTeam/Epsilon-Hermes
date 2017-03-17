#pragma once

#include <QApplication>
#include <QScopedPointer>

class InfrastructureContainer;
class CommunicationContainer;
class DataContainer;
class BusinessContainer;
class ViewContainer;

class SchulichDeltaHermes : public QApplication
{
public:
    SchulichDeltaHermes(int& argc, char** argv);
    ~SchulichDeltaHermes();

private:
    QScopedPointer<InfrastructureContainer> infrastructureContainer_;
    QScopedPointer<DataContainer> dataContainer_;
    QScopedPointer<CommunicationContainer> communicationContainer_;
    QScopedPointer<BusinessContainer> businessContainer_;
    QScopedPointer<ViewContainer> viewContainer_;
};
