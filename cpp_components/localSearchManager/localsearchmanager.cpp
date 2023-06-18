
#include "localsearchmanager.h"
#include "cpp_components/dish/dish.h"
#include "cpp_components/systemManager/systemmanager.h"


#include <QDebug>
#include <QDir>
#include <QFile>




// +===== KONSTRUKTORY/DESTRUKTORY =====+
localSearchManager::localSearchManager(QObject *parent): QAbstractListModel(parent)
{
    //updateDishes();
}

localSearchManager::~localSearchManager()
{

}


// +===== QVariantAbstractList =====+
QHash<int, QByteArray> localSearchManager::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[dishNameRole] = "dishName";
    roles[dishCountryRole] = "dishCountry";
    roles[dishPhotoLinkRole] = "dishPhotoLink";
    roles[dishIndex] = "dishIndex";
    return roles;
}

int localSearchManager::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return dishes.size(); // Assuming 'animals' is a member variable holding the data
}

QVariant localSearchManager::data(const QModelIndex &index, int role) const
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

    case dishCountryRole:
        return dish.getDishCountry();

    case dishPhotoLinkRole:
        return dish.getDishPhotoLink();

    case dishIndex:
        return dish.getDishIndex();

    default:
        break;
    }

    return QVariant();
}


// +===== Methods =====+
void localSearchManager::updateDishes()
{

}

void localSearchManager::addDish(const Dish &dish)
{
    // Assuming 'animals' is a QList<Animal> member variable in AnimalModel
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    dishes.append(dish);
    endInsertRows();
}


// +===== SLOTS =====+
void localSearchManager::searchLocalDish(QString searchedText)
{
    //Czyszczenie na poczet nowego wyszukania
    beginResetModel();
    dishes.clear();
    endResetModel();
    //Mechanika wyszukiwania tutaj wywołana (na potrzeby testu robimy gotowy zestaw danych jakby był już wyszukany)
    qDebug()<< "Searched text: "<< searchedText;
    //updateTags();

    QFile csv(systemManager::getDocumentsPath() + "/FlavourCraft/index.csv");
    if (csv.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while(!csv.atEnd())
        {
            QString data = csv.readLine();
            //qDebug() << data;
            int firstCommaIndex = data.indexOf(",");
            QString dishName = data.left(firstCommaIndex);
            int secondCommaIndex = data.indexOf(",", firstCommaIndex + 1);
            QString dishCountry = data.mid(firstCommaIndex + 1, secondCommaIndex - firstCommaIndex - 1);
            int firstSeparatorIndex = data.indexOf("˘");
            QString tags = data.left(firstSeparatorIndex);
            int secondSeparatorIndex = data.indexOf("˘", firstSeparatorIndex + 1);
            QString dishPhotoLink = data.mid(firstSeparatorIndex + 1, secondSeparatorIndex - firstSeparatorIndex - 1);
            QString dishPath = data.mid(secondSeparatorIndex + 1);
            dishPath.chop(1);
            //qDebug()<< "WAZNE dishName: "<< dishPhotoLink;
            //qDebug()<< "WAZNE dishCountry"<<dishCountry;
            //qDebug()<< "WAZNE dishPath"<<dishPath;
            //qDebug()<< "WAZNE tags"<<tags;
            //qDebug()<< "WAZNE dishPhotoLink"<<dishPhotoLink;

            if(tags.toLower().contains(searchedText.toLower()))
                addDish(Dish(dishName,dishCountry,dishPhotoLink,dishPath));
        }
    }
    else
    {
        qDebug() << "Failed to open csv\n";
    }

    csv.close();
}

void localSearchManager::searchOnlineDish(std::vector<webRecipeScraper::foundRecipe> foundRecipes)
{
    //qDebug()<<foundRecipes.at(0).name;
    beginResetModel();
    dishes.clear();
    endResetModel();

    for(auto recipe : foundRecipes)
    {
        addDish(Dish(recipe.name,recipe.cuisine,recipe.id));
    }
}

void localSearchManager::loadDish(int index)
{
    qDebug()<< "index: "<<index;
    chosenDish = dishes[index];
    clearDishes();
    qDebug()<< "cleared";
    chosenDish.loadUpDish();
    emit loadDishFinished("qrc:/pages/DishPage.qml");
    emit setUpDish({chosenDish.getDishName(),
                    chosenDish.getDishCountry(),
                    chosenDish.getDishRecipeSteps(),
                    chosenDish.getDishIndegrients(),
                    chosenDish.getDishPhotoLink()});
}

void localSearchManager::loadOnlineDish(int index)
{
    qDebug()<< "index: "<<index;
    chosenDish = dishes[index];
    clearDishes();
    qDebug()<< "cleared";
    emit getWebDish(&chosenDish);
}

void localSearchManager::clearDishes()
{
    beginResetModel();
    dishes.clear();
    endResetModel();
}

void localSearchManager::loadWebDish(Dish* dish)
{
    emit setUpDish({chosenDish.getDishName(),
                    chosenDish.getDishCountry(),
                    chosenDish.getDishRecipeSteps(),
                    chosenDish.getDishIndegrients(),
                    chosenDish.getDishPhotoLink()});
}

void localSearchManager::createNewDish(QString dishName, QString dishCountry, QString dishTags, QString dishSteps, QString dishIndegrients, QString dishPhotoLink)
{
    qDebug()<< dishName<< dishCountry<<dishTags<<dishSteps<<dishIndegrients<<dishPhotoLink;
    QString path = systemManager::documentsPath + "/FlavourCraft/data/" + dishName + ".txt"; // Wprowadź ścieżkę do docelowego pliku

    QFile file(path);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);

        // Zapisz dane do pliku w odpowiednim formacie
        stream << dishName << "," << dishCountry << ",";
        stream << dishTags << "˘";
        stream << dishSteps << "˘";
        stream << dishIndegrients << "˘";
        stream << dishPhotoLink;

        file.close();
        qDebug() << "Plik został utworzony: " << path;
        systemManager::createDirectories();
    }
    else
    {
        qDebug() << "Błąd podczas tworzenia pliku: " << file.errorString();
    }
    //place for update cache function
}

void localSearchManager::deleteDish(int index)
{
    qDebug()<< index;
    QString filePath = dishes.at(index).getDishPath();
    QFile file(filePath);
    if (file.remove())
    {
        qDebug() << "Plik został usunięty: " << filePath;
        systemManager::createDirectories();
    }
    else
    {
        qDebug() << "Błąd podczas usuwania pliku: " << file.errorString();
    }

    emit loadDishFinished("qrc:/pages/MainPage.qml");
}

void localSearchManager::addOnlineDish()
{
    //qDebug()<< "grgml";
}
