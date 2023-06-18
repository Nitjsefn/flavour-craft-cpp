
#ifndef LOCALSEARCHMANAGER_H
#define LOCALSEARCHMANAGER_H

#include <vector>
#include <QObject>
#include <QAbstractListModel>


#include "cpp_components/dish/dish.h"
#include "cpp_components/webRecipeScraper/webRecipeScraper.h"



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
    void updateDishes(); //funkcja do dodawania/USUWANIA, NOWEGO  przepisu do indexow itp;

signals:
    void loadDishFinished(QString source);
    void getWebDish(Dish* dish);
    void setUpDish(QList<QString> aboutDish);

public slots:
    void searchLocalDish(QString dishName); //do szukania
    void searchOnlineDish(std::vector<webRecipeScraper::foundRecipe> foundRecipes); //do obslugi onlinowego backendu
    void loadDish(int index); //do ladowania jednego konkretnego wybranego lokalsa disha
    void loadOnlineDish(int index); //do ladowania jednego konkretnego wybrnego online disha
    void loadWebDish(Dish* dish);
    void clearDishes(); //czyszczenie dishy w ramie
    void createNewDish(QString dishName, QString dishCountry, QString dishTags, QString dishSteps, QString dishIndegrients, QString dishPhotoLink);
    void deleteDish(int index);
    void addOnlineDish();

private:
    QList<Dish> dishes;
    Dish chosenDish;
};

#endif // LOCALSEARCHMANAGER_H
