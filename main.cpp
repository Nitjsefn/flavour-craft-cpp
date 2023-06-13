#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>


#include "cpp_components/localSearchManager/localsearchmanager.h"
#include "cpp_components/systemManager/systemmanager.h"

int main(int argc, char *argv[])
{
    systemManager::checkSystem();
    qDebug()<< systemManager::getDocumentsPath();
    systemManager::createDirectories();

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    localSearchManager search_handler;
    engine.rootContext()->setContextProperty("search_handler",&search_handler);

    const QUrl url(u"qrc:/FlavorCraft/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    app.setWindowIcon(QIcon(":/assets/ui/Assets/OIG.png"));
    return app.exec();
}
