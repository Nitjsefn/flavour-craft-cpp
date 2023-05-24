// DishListModel.h

#include <QAbstractListModel>
#include <QVector>



struct DishItem
{
    QString dishName;
    QString dishCountry;
    QString dishDescription;
};



class DishListModel : public QAbstractListModel
{
    Q_OBJECT
    public:
        enum DishRoles
        {
            DishNameRole = Qt::UserRole + 1,
            DishCountryRole,
            DishDescriptionRole
        };

        DishListModel(QObject* parent = nullptr);

        int rowCount(const QModelIndex& parent = QModelIndex()) const override;
        QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
        QHash<int, QByteArray> roleNames() const override;

        void setDishList(const QVector<DishItem>& dishList);

    private:
        QVector<DishItem> m_dishList;
};
