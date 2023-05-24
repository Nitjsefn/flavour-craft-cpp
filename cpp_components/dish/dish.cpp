#include "dish.h"
#include <QDebug>



using namespace std;



Dish::Dish(QObject *parent)
    :QObject{parent}
{
    this->dishName = "dishName";
    this->dishDescription = "dishDescription";
    this->dishIndegrients = "dishIndegrients";
    this->dishPhotoLink = "dishPhotoLink";
}


/*Dish::Dish()
{

}*/


Dish::~Dish()
{

}


void Dish::loadDish(QString dishName, QString dishDescription, QString dishIndegrients, QString dishPhotoLink, QString dishCountry)
{
    this->dishName = dishName;
    this->dishDescription = dishDescription;
    this->dishIndegrients = dishIndegrients;
    this->dishPhotoLink = dishPhotoLink;
    this->dishCountry = dishCountry;
    return;
}




void Dish::testFuntion_1()
{
    qDebug()<< "test";
    return;
}


void Dish::testFuntion_2()
{
    qDebug()<< "test";
    return;
}


void Dish::testFuntion_3()
{
    qDebug()<< "test";
    return;
}
