
#include "searchmanager.h"
#include "qdebug.h"


searchManager::searchManager(QObject *parent)
    :QObject{parent}
{

}


DishListModel* searchManager::getDishListModel() const
{
    return const_cast<DishListModel*>(&m_dishListModel);
}

searchManager::~searchManager()
{

}


void searchManager::searchDish(QString dishName)
{
    //m_dishNames.append("twoja mama");
    qDebug() << dishName;

    //DishItem newItem;
    //newItem.dishName = "Kosiniak";
   // newItem.dishCountry = "Kamysz";
   // newItem.dishDescription = "blahblahblah";

    //m_dishListModel.setDishList(QVector<DishItem>() << newItem);

    return;
}


