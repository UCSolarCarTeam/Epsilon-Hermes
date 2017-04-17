#include "SchulichEpsilonHermes.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QScopedPointer<SchulichEpsilonHermes> app;
    app.reset(new SchulichEpsilonHermes(argc, argv));
    return app->exec();
}
