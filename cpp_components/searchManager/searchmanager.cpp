
#include "searchmanager.h"
#include "cpp_components/dish/dish.h"

#include <QDebug>
#include <QDir>
#include <QFile>



// +===== KONSTRUKTORY/DESTRUKTORY =====+
searchManager::searchManager(QObject *parent): QAbstractListModel(parent)
{
    updateTags();
}

searchManager::~searchManager()
{
    dishes.clear();
    txtFiles.clear();
}


// +===== QVariantAbstractList =====+
QHash<int, QByteArray> searchManager::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[dishNameRole] = "dishName";
    roles[dishDescriptionRole] = "dishDescription";
    roles[dishIndegrientsRole] = "dishIndegrients";
    roles[dishPhotoLinkRole] = "dishPhotoLink";
    roles[dishCountryRole] = "dishCountry";
    roles[dishIndex] = "dishIndex";
    return roles;
}

int searchManager::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return dishes.size(); // Assuming 'animals' is a member variable holding the data
}

QVariant searchManager::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() < 0 || index.row() >= dishes.size())
        return QVariant();

    const Dish &dish = dishes.at(index.row());

    /*
        QString getDishName() const;
        QString getDishDescription() const;
        QString getDishIndegrients() const;
        QString getDishPhotoLink() const;
        QString getDishCountry() const;
    */
    switch(role)
    {
        case dishNameRole:
            return dish.getDishName();

        case dishDescriptionRole:
            return dish.getDishDescription();

        case dishIndegrientsRole:
            return dish.getDishIndegrients();

        case dishPhotoLinkRole:
            return dish.getDishPhotoLink();

        case dishCountryRole:
            return dish.getDishCountry();

        case dishIndex:
            return dish.getDishIndex();

        default:
            break;
    }

    return QVariant();
}


// +===== Methods =====+
void searchManager::updateTags()
{
    this->txtFiles.clear();
    QString folderPath = ":/localdata";
    QDir directory(folderPath);
    QStringList txtFiles = directory.entryList(QStringList() << "*.txt", QDir::Files);
    foreach (const QString& txtFile, txtFiles)
    {
        QString filePath = directory.filePath(txtFile);
        QFile file(filePath);

        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream textStream(&file);
            QString tags = textStream.readLine();
            this->txtFiles.append({filePath,tags});
            file.close();
            qDebug() << "Content of" << filePath << ":" << tags;
        }
        else
        {
            qDebug() << "Failed to open" << filePath;
        }
    }
}

void searchManager::addDish(const Dish &dish)
{
    // Assuming 'animals' is a QList<Animal> member variable in AnimalModel
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    dishes.append(dish);
    endInsertRows();
}


// +===== SLOTS =====+
void searchManager::searchLocalDish(QString searchedText)
{
    //Czyszczenie na poczet nowego wyszukania
    beginResetModel();
    dishes.clear();
    endResetModel();
    //Mechanika wyszukiwania tutaj wywołana (na potrzeby testu robimy gotowy zestaw danych jakby był już wyszukany)
    qDebug()<< "Searched text: "<< searchedText;
    updateTags();
    for(int i=0;i<txtFiles.count();i++)
    {
        if(txtFiles[i].tags.contains(searchedText.toLower()))
        {
            //Tablice wyszukanych Dish'ow zaapenduj do dishes;
            //qDebug()<< "WARNING! found tags!:"<< txtFiles[i].filePath<< "\n";
            addDish(Dish(txtFiles[i].filePath));
        }
    }
    /*for(int i=0;i<this->txtFiles.count();i++)
    {
            qDebug()<< "Path: "<< txtFiles[i].filePath<< " Tags: "<< txtFiles[i].tags<< "\n";
    }*/
}

void searchManager::searchOnlineDish(QString dishName)
{

}

void searchManager::loadDish(int index)
{
    qDebug()<< "index: "<<index;
    chosenDish = dishes[index];
    clearDishes();
    qDebug()<< "cleared";
}

void searchManager::clearDishes()
{
    beginResetModel();
    dishes.clear();
    endResetModel();
}


// +===== TEST/DEBUG =====+
void searchManager::testFuntion_1()
{
    qDebug()<< "test1";
    return;
}

void searchManager::testFuntion_2()
{
    qDebug()<< "test2";
    return;
}

void searchManager::testFuntion_3()
{
    qDebug()<< "test3";
    return;
}
