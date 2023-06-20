#ifndef DISH_H
#define DISH_H

#include <QObject>
#include <QString>



struct dishInfo
{
    QString dishName;
    QString dishDescription;
    QString dishIndegrients;
    QString dishPhotoLink;
    QString dishCountry;
};



class DishXD: public QObject
{
    Q_OBJECT
    public:
    explicit DishXD(QObject *parent = nullptr);
        DishXD(const QString &dishName, const QString &dishDescription, const QString &dishIndegrients, const QString &dishPhotoLink, const QString &dishCountry, QObject *parent = nullptr)
            : QObject(parent), dishInfo{dishName, dishDescription, dishIndegrients, dishPhotoLink, dishCountry}{};
    ~DishXD();

        QString getDishName() const;
        QString getDishDescription() const;
        QString getDishIndegrients() const;
        QString getDishPhotoLink() const;
        QString getDishCountry() const;


    public slots:
        void loadDish(QString dishName, QString dishDescription, QString dishIndegrients, QString dishPhotoLink, QString dishCountry);

        void testFuntion_1();
        void testFuntion_2();
        void testFuntion_3();


    private:
        dishInfo dishInfo;
};

/*
class Dish
{
    public:
    Dish();
    Dish(const QString &dishName, const QString &dishDescription, const QString &dishIndegrients, const QString &dishPhotoLink, const QString &dishCountry)
        :dishInfo{dishName, dishDescription, dishIndegrients, dishPhotoLink, dishCountry}{};
    ~Dish();

    QString getDishName() const;
    QString getDishDescription() const;
    QString getDishIndegrients() const;
    QString getDishPhotoLink() const;
    QString getDishCountry() const;


public slots:
    void loadDish(QString dishName, QString dishDescription, QString dishIndegrients, QString dishPhotoLink, QString dishCountry);

    void testFuntion_1();
    void testFuntion_2();
    void testFuntion_3();


private:
    dishInfo dishInfo;
};
*/

#endif
