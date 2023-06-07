
#ifndef SEARCHMANAGER_H
#define SEARCHMANAGER_H

#include <QObject>
#include <QAbstractListModel>

#include "cpp_components/dish/dish.h"



struct txtFile
{
    QString filePath;
    QString tags;
};



class searchManager: public QAbstractListModel
{
        Q_OBJECT
    public:

        searchManager(QObject *parent = nullptr);
        ~searchManager();

        enum DishesRoles
        {
            dishNameRole = Qt::UserRole + 1,
            dishRecipeSteps,
            dishIndegrientsRole,
            dishPhotoLinkRole,
            dishCountryRole,
            dishIndex
        };
        QHash<int, QByteArray> roleNames() const override;
        int rowCount(const QModelIndex &parent = QModelIndex()) const override;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

        void addDish(const Dish &dish);
        void updateTags();

    public slots:
        void searchLocalDish(QString dishName);
        void searchOnlineDish(QString dishName);
        void loadDish(int index);
        void clearDishes();
        void testFuntion_1();
        void testFuntion_2();
        void testFuntion_3();

    private:
        QList<Dish> dishes;
        QList<txtFile> txtFiles;
        Dish chosenDish;
};

#endif // SEARCHMANAGER_H
