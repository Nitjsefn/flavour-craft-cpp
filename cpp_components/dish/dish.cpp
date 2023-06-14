
#include "dish.h"

#include <QDebug>
#include <QFile>


//using namespace std;


Dish::Dish()
{
    this->dishData.dishName = "dishName";
    this->dishData.dishRecipeSteps = "dishDescription";
    this->dishData.dishIndegrients = "dishIndegrients";
    this->dishData.dishPhotoLink = "dishPhotoLink";
    this->dishData.dishCountry = "dishCountry";
}

Dish::Dish(QString path)
{

    QFile file(path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream textStream(&file);

        // Odczytaj dane z pliku i przypisz je do pól obiektu dishInfo
        textStream.readLine(); //pomiń tagi
        this->dishData.dishName = textStream.readLine();
        this->dishData.dishRecipeSteps = textStream.readLine();
        this->dishData.dishIndegrients = textStream.readLine();
        this->dishData.dishPhotoLink = textStream.readLine();
        this->dishData.dishCountry = textStream.readLine();

        //qDebug()<< "dishName: "<<this->dishData.dishName;
        //qDebug()<< "dishDescription: "<<this->dishData.dishRecipeSteps;
        //qDebug()<< "dishIndegrients: "<<this->dishData.dishIndegrients;
        //qDebug()<< "dishPhotoLink: "<<this->dishData.dishPhotoLink;
        //qDebug()<< "dishCountry: "<<this->dishData.dishCountry;

        file.close();
    }
    else
    {
        qDebug() << "Failed to open file:" << path;
    }
}

Dish::Dish(const QString &dishName, const QString &dishCountry, const QString &dishPhotoLink, const QString &path)
{
    this->dishData.dishName = dishName;
    this->dishData.dishRecipeSteps = "";
    this->dishData.dishIndegrients = "";
    this->dishData.dishPhotoLink = dishPhotoLink;
    this->dishData.dishCountry = dishCountry;
    this->path = path;
    //qDebug() << "z poziomu konstrutora link do zdjecia: "<< dishPhotoLink;
}

Dish::~Dish()
{

}


void Dish::loadUpDish()
{
    qDebug()<<this->path;
    QFile file(this->path);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream textStream(&file);
        QString text = textStream.readAll();
        file.close();
        QStringList parts = text.split("˘");

        if (parts.size() >= 2)
        {
            QString part1 = parts[1];
            QString part2 = parts[2];
            //qDebug() <<part1 <<"\n"<<part2;
            this->dishData.dishRecipeSteps = part1;
            this->dishData.dishIndegrients = part2;
        }
    }
    else qDebug()<< "failed to open";
}

QString Dish::getDishName() const
{
    return dishData.dishName;
}

QString Dish::getDishRecipeSteps() const
{
    return dishData.dishRecipeSteps;
}

QString Dish::getDishIndegrients() const
{
    return dishData.dishIndegrients;
}

QString Dish::getDishPhotoLink() const
{
    return dishData.dishPhotoLink;
}

QString Dish::getDishCountry() const
{
    return dishData.dishCountry;
}

QString Dish::getDishPath() const
{
    return this->path;
}

int Dish::getDishIndex() const
{
    return index;
}
