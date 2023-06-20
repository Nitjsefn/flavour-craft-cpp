#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>


#include "cpp_components/localSearchManager/localsearchmanager.h"
#include "cpp_components/systemManager/systemmanager.h"
#include "cpp_components/webRecipeSearch/webRecipeSearch.h"
#include "cpp_components/webRecipeGetter/webRecipeGetter.h"
#include "cpp_components/dish/dish.h"

int main(int argc, char *argv[])
{
    systemManager::checkSystem();
    //qDebug()<< systemManager::getDocumentsPath();
    systemManager::createDirectories();

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    localSearchManager* search_handler = new localSearchManager();
    webRecipeSearch* webSearch_handler = new webRecipeSearch(QUrl("https://cosylab.iiitd.edu.in/recipedb/search_recipe"));
    webRecipeGetter* webSearch_getter = new webRecipeGetter();

    QObject::connect(webSearch_handler,&webRecipeSearch::finished,search_handler,&localSearchManager::searchOnlineDish);
    QObject::connect(search_handler,&localSearchManager::getWebDish,webSearch_getter,&webRecipeGetter::getWebRecipeSlot);
    QObject::connect(webSearch_getter,&webRecipeGetter::finished,search_handler,&localSearchManager::loadWebDish);

    engine.rootContext()->setContextProperty("search_handler",search_handler);
    engine.rootContext()->setContextProperty("webSearch_handler",webSearch_handler);
    engine.rootContext()->setContextProperty("webSearch_getter",webSearch_getter);

    const QUrl url(u"qrc:/FlavorCraft/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    app.setWindowIcon(QIcon(":/assets/ui/Assets/OIG.png"));
    return app.exec();
}
