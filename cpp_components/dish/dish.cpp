
#include "dish.h"

#include <QDebug>
#include <QFile>


//using namespace std;


Dish::Dish()
{
    this->dishInfo.dishName = "dishName";
    this->dishInfo.dishDescription = "dishDescription";
    this->dishInfo.dishIndegrients = "dishIndegrients";
    this->dishInfo.dishPhotoLink = "dishPhotoLink";
    this->dishInfo.dishCountry = "dishCountry";
}

Dish::Dish(QString path)
{

    QFile file(path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream textStream(&file);

        // Odczytaj dane z pliku i przypisz je do pól obiektu dishInfo
        textStream.readLine(); //pomiń tagi
        this->dishInfo.dishName = textStream.readLine();
        this->dishInfo.dishDescription = textStream.readLine();
        this->dishInfo.dishIndegrients = textStream.readLine();
        this->dishInfo.dishPhotoLink = textStream.readLine();
        this->dishInfo.dishCountry = textStream.readLine();

        qDebug()<<  "dishName: "<<this->dishInfo.dishName;
        qDebug()<<  "dishDescription: "<<this->dishInfo.dishDescription;
        qDebug()<<  "dishIndegrients: "<<this->dishInfo.dishIndegrients;
        qDebug()<<  "dishPhotoLink: "<<this->dishInfo.dishPhotoLink;
        qDebug()<<  "dishCountry: "<<this->dishInfo.dishCountry;

        file.close();
    }
    else
    {
        qDebug() << "Failed to open file:" << path;
    }
}

Dish::~Dish()
{

}


QString Dish::getDishName() const
{
    return dishInfo.dishName;
}

QString Dish::getDishDescription() const
{
    return dishInfo.dishDescription;
}

QString Dish::getDishIndegrients() const
{
    return dishInfo.dishIndegrients;
}

QString Dish::getDishPhotoLink() const
{
    return dishInfo.dishPhotoLink;
}

QString Dish::getDishCountry() const
{
    return dishInfo.dishCountry;
}

int Dish::getDishIndex() const
{
    return index;
}
