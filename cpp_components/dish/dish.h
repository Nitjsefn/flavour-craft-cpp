
#ifndef DISH_H
#define DISH_H

#include <QString>



struct dishInfo
{
    QString dishName;
    QString dishDescription;
    QString dishIndegrients;
    QString dishPhotoLink;
    QString dishCountry;
};



class Dish
{
    public:

        Dish();
        Dish(QString path);
        Dish(const QString &dishName, const QString &dishDescription, const QString &dishIndegrients, const QString &dishPhotoLink, const QString &dishCountry, int index)
            :dishInfo{dishName, dishDescription, dishIndegrients, dishPhotoLink, dishCountry}, index(index){};
        Dish(const QString &dishName, const QString &dishDescription, const QString &dishIndegrients, const QString &dishPhotoLink, const QString &dishCountry)
            :dishInfo{dishName, dishDescription, dishIndegrients, dishPhotoLink, dishCountry}{};
        ~Dish();

        QString getDishName() const;
        QString getDishDescription() const;
        QString getDishIndegrients() const;
        QString getDishPhotoLink() const;
        QString getDishCountry() const;
        int getDishIndex() const;

    private:
        dishInfo dishInfo;
        int index;
};

#endif // DISH_H
