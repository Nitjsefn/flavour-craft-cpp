#ifndef DISH_H
#define DISH_H

#include <QObject>
#include <QString>




class Dish: public QObject
{
    Q_OBJECT
    public:
        explicit Dish(QObject *parent = nullptr);

        //Dish();
        Dish(QString dishName,
             QString dishCousine,
             QString dishDescription,
             QString dishIndegrients,
             int dishLevel);

        ~Dish();

    public slots:
        void loadDish(QString dish);
        void httpreq();

    private:
        QString dishName;
        QString dishCousine;
        QString dishDescription;
        QString dishIndegrients;
        int dishLevel;


};

#endif // DISH_H
