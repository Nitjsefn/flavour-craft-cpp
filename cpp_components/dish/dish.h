
#ifndef DISH_H
#define DISH_H

#include <QString>



struct dishInfo
{
    QString dishName;
    QString dishRecipeSteps;
    QString dishIndegrients;
    QString dishPhotoLink;
    QString dishCountry;
};



class Dish
{
    public:

        Dish();
        Dish(QString path);
        Dish(const QString &dishName, const QString &dishRecipeSteps, const QString &dishIndegrients, const QString &dishPhotoLink, const QString &dishCountry, int index)
            :dishData{dishName, dishRecipeSteps, dishIndegrients, dishPhotoLink, dishCountry}, index(index){};
        Dish(const QString &dishName, const QString &dishRecipeSteps, const QString &dishIndegrients, const QString &dishPhotoLink, const QString &dishCountry)
            :dishData{dishName, dishRecipeSteps, dishIndegrients, dishPhotoLink, dishCountry}{};
        Dish(const QString &dishName, const QString &dishCountry, const QString &dishPhotoLink, const QString &path);
            //:dishData{dishName, "dishRecipeSteps", "dishIndegrients", dishPhotoLink, dishCountry}, path(path){};

        ~Dish();

        QString getDishName() const;
        QString getDishRecipeSteps() const;
        QString getDishIndegrients() const;
        QString getDishPhotoLink() const;
        QString getDishCountry() const;
        int getDishIndex() const;
        void loadUpDish();

    private:
        dishInfo dishData;
        QString path;
        int index;
};

#endif // DISH_H
