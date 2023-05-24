
#ifndef SEARCHMANAGER_H
#define SEARCHMANAGER_H


#include <QObject>


#include "cpp_components/DishListModel/dishlistmodel.h"



class searchManager: public QObject
{
        Q_OBJECT
    public:
        explicit searchManager(QObject *parent = nullptr);
        ~searchManager();

        DishListModel* getDishListModel() const;


    public slots:
        void searchDish(QString dishName);

    private:
         DishListModel m_dishListModel;
};

#endif // SEARCHMANAGER_H
