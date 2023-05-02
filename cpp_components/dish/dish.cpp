#include "dish.h"
#include "qdebug.h"




Dish::Dish(QObject *parent)
    :QObject{parent}
{

}

//RunesImporter::RunesImporter(QObject *parent)
//    : QObject{parent}


Dish::Dish(QString dishName,
           QString dishCousine,
           QString dishDescription,
           QString dishIndegrients,
           int dishLevel)
{
    this->dishName = dishName;
    this->dishCousine  = dishCousine;
    this->dishDescription = dishDescription;
    this->dishIndegrients = dishIndegrients;
    this->dishLevel = dishLevel;
}


Dish::~Dish()
{

}


void Dish::loadDish(QString dishName)
{
    qDebug()<< dishName;
    return;
}


void Dish::httpreq()
{
    qDebug()<< "test";
}
