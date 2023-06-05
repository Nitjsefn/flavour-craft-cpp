#include "dish.h"
#include <QDebug>


using namespace std;


DishXD::DishXD(QObject *parent):QObject{parent}
{
    this->dishInfo.dishName = "dishName";
    this->dishInfo.dishDescription = "dishDescription";
    this->dishInfo.dishIndegrients = "dishIndegrients";
    this->dishInfo.dishPhotoLink = "dishPhotoLink";
    this->dishInfo.dishCountry = "dishCountry";
}

/*Dish::Dish()
{
    this->dishInfo.dishName = "dishName";
    this->dishInfo.dishDescription = "dishDescription";
    this->dishInfo.dishIndegrients = "dishIndegrients";
    this->dishInfo.dishPhotoLink = "dishPhotoLink";
    this->dishInfo.dishCountry = "dishCountry";
}*/

DishXD::~DishXD()
{

}


void DishXD::loadDish(QString dishName, QString dishDescription, QString dishIndegrients, QString dishPhotoLink, QString dishCountry)
{
    this->dishInfo.dishName = dishName;
    this->dishInfo.dishDescription = dishDescription;
    this->dishInfo.dishIndegrients = dishIndegrients;
    this->dishInfo.dishPhotoLink = dishPhotoLink;
    this->dishInfo.dishCountry = dishCountry;
    return;
}


QString DishXD::getDishName() const
{
    return dishInfo.dishName;
}

QString DishXD::getDishDescription() const
{
    return dishInfo.dishDescription;
}

QString DishXD::getDishIndegrients() const
{
    return dishInfo.dishIndegrients;
}

QString DishXD::getDishPhotoLink() const
{
    return dishInfo.dishPhotoLink;
}

QString DishXD::getDishCountry() const
{
    return dishInfo.dishCountry;
}


// +===DEBUG & TESTING (XD)===+


void DishXD::testFuntion_1()
{
    qDebug()<< "test";
    return;
}


void DishXD::testFuntion_2()
{
    qDebug()<< "test";
    return;
}


void DishXD::testFuntion_3()
{
    qDebug()<< "test";
    return;
}
