// DishListModel.cpp

#include "DishListModel.h"

DishListModel::DishListModel(QObject* parent)
    : QAbstractListModel(parent)
{
}

int DishListModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return m_dishList.size();
}

QVariant DishListModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const DishItem& dish = m_dishList[index.row()];

    if (role == DishNameRole)
        return dish.dishName;
    else if (role == DishCountryRole)
        return dish.dishCountry;
    else if (role == DishDescriptionRole)
        return dish.dishDescription;

    return QVariant();
}

QHash<int, QByteArray> DishListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[DishNameRole] = "dishName";
    roles[DishCountryRole] = "dishCountry";
    roles[DishDescriptionRole] = "dishDescription";
    return roles;
}

void DishListModel::setDishList(const QVector<DishItem>& dishList)
{
    beginResetModel();
    m_dishList = dishList;
    endResetModel();
}
