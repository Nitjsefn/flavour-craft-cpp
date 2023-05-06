#ifndef DISH_H
#define DISH_H

#include <QObject>
#include <QString>




class Dish: public QObject
{
    Q_OBJECT
    public:
        explicit Dish(QObject *parent = nullptr);
        ~Dish();

    public slots:
        void loadDish(QString dishName, QString dishDescription, QString dishIndegrients, QString dishPhotoLink);
        void searchDish(QString dishName);
        void testFuntion_1();
        void testFuntion_2();
        void testFuntion_3();


    private: //kraj, skladniki (dlugi string, new line), kroki z new lineami, nazwa, link do zdjecia
        QString dishName;
        QString dishDescription;
        QString dishIndegrients;
        QString dishPhotoLink;

};

#endif // DISH_H

/*Dish(QString dishName, QString dishDescription, QString dishIndegrients, QString dishPhotoLink):
            dishName(dishName), dishDescription(dishDescription), dishIndegrients(dishIndegrients), dishPhotoLink(dishPhotoLink){};*/

