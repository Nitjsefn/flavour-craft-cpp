
#ifndef LOCALSEARCHMANAGER_H
#define LOCALSEARCHMANAGER_H


#include <QObject>
#include <QAbstractListModel>


#include "cpp_components/dish/dish.h"



class localSearchManager: public QAbstractListModel
{
    Q_OBJECT
public:

    localSearchManager(QObject *parent = nullptr);
    ~localSearchManager();

    enum DishesRoles
    {
        dishNameRole = Qt::UserRole + 1, //wyswietlanie nazwy i kraju
        dishCountryRole,
        dishPhotoLinkRole,
        dishIndex                       // do callbacku z frontendu ktory element otworzyc
    };

    QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void addDish(const Dish &dish);
    void updateDishes(); //funkcja do dodawania nowego przepisu do indexow itp;

signals:
    void loadDishFinished(QString source );
    void setUpDish(QList<QString> aboutDish);

public slots:
    void searchLocalDish(QString dishName); //do szukania
    void loadDish(int index); //do ladowania jednego konkretnego wybranego disha
    void clearDishes(); //czyszczenie dishy w ramie

private:
    QList<Dish> dishes;
    Dish chosenDish;
};

#endif // LOCALSEARCHMANAGER_H
