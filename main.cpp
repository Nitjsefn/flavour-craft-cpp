#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>


#include "cpp_components/searchManager/searchmanager.h"



int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);    
    QQmlApplicationEngine engine;

    searchManager search_handler;
    engine.rootContext()->setContextProperty("search_handler",&search_handler);
    //engine.rootContext()->setContextProperty("dishlistmodel", search_handler.getDishListModel());


    const QUrl url(u"qrc:/FlavorCraft/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    app.setWindowIcon(QIcon(":/assets/ui/Assets/OIG.png"));
    return app.exec();
}
