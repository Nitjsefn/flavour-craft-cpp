#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>


#include "cpp_components/dish/dish.h"



int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);    
    QQmlApplicationEngine engine;

    Dish *dish_handler = new  Dish;
    engine.rootContext()->setContextProperty("dish_handler",dish_handler);

    const QUrl url(u"qrc:/FlavorCraft/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    app.setWindowIcon(QIcon(":/assets/ui/Assets/OIG.png"));
    return app.exec();
}
