
#include "systemmanager.h"
#include <QDir>

bool systemManager::isWindows()
{
    return QSysInfo::productType().toLower().contains("windows");
}

bool systemManager::isLinux()
{
    return QSysInfo::productType().toLower().contains("linux");
}

void systemManager::checkSystem()
{
    if (isWindows())
    {
        qDebug() << "Running on Windows";
    }
    else if (isLinux())
    {
        qDebug() << "Running on Linux";
    }
    else
    {
        qDebug() << "Running on an unsupported system";
    }
}

QString systemManager::documentsPath;

QString systemManager::getDocumentsPath()
{
    documentsPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    return documentsPath;
}


void systemManager::createDirectories()
{
    QString dataPath = systemManager::getDocumentsPath() + "/FlavourCraft/data/";
    QDir dir;
    if (!dir.mkpath(dataPath))
        qDebug() << "Failed to create folder.";
    else
        qDebug() << "Folder created successfully.";

    for(int i=1;i<=3;i++)
    {
        QString filePath = dataPath + "dish" + QString::number(i) + ".txt";
        QFile file(filePath);
        if (!file.exists())
        {
            if (file.open(QIODevice::WriteOnly | QIODevice::Text))
            {
                QTextStream textStream(&file);
                QString content;
                switch(i)
                {
                case 1:
                    content += "Kotlet Schabowy (Polish Breaded Pork Chop),Polska,kotlet,mięso"
                              "˘1.	Place pork chops between 2 sheets of heavy plastic on a solid, level surface. Firmly pound with the smooth side of a meat mallet, turning occasionally, until very thin. Season with salt and pepper. | 2.	Pour flour onto a large plate. Whisk egg in a wide, shallow bowl. Place breadcrumbs in a separate shallow bowl. | 3.	Dredge chops with flour. Dip in whisked egg. Coat with bread crumbs on both sides. Shake off excess coating. | 4.	Heat oil in a large skillet over medium-high heat. Add breaded chops; cook until golden brown, about 5 minutes per side."
                              "˘INGREDIENTS:\npork chop: 2 boneless,\nsalt black pepper: to taste\npurpose flour: 1 tablespoon\negg: 1\nbread crumb: 5 tablespoons\nvegetable oil: 2 tablespoons"
                              "˘https://images.media-allrecipes.com/userphotos/560x315/4537037.jpg";
                            //qDebug()<< "dish1 created in path: "<< filePath<< "with content of: \n"<< content;
                    break;
                case 2:
                    content += "Japanese Nabeyaki Udon Soup,Japonia,zupa,mięso"
                              "˘1.	Heat dashi stock, chicken, carrots, soy sauce, mirin, sugar, and salt in a pot over medium heat. Simmer until chicken is no longer pink in the center, 5 to 7 minutes. Add tofu, mushrooms, and bok choy, stirring until vegetables are tender, about 5 minutes more. | 2.	Stir udon noodles into broth and simmer until tender, 3 to 4 minutes. Add leeks and crack eggs into soup; simmer  until eggs are slightly firm, about 5 minutes more."
                              "˘INGREDIENTS:\ndashi stock: 6 cups\nchicken: 1/4 pound\ncarrot: 2\nsoy sauce: 1/3 cup\nmirin: 3 tablespoons\nwhite sugar: 1/2 teaspoon\nsalt: 1/3 teaspoon\ntofu: 2 packages\nshiitake mushroom: 1/3 pound\nrib choy: 5\nudon noodle: 1 packagen\negg: 4\nleek: 2"
                              "˘https://hubertkajdan.com/wp-content/uploads/2019/06/2019-06-20-Jezioro-Lednickie-010-Pano.jpg";
                            //qDebug()<< "dish2 created in path: "<< filePath<< "with content of: \n"<< content;
                    break;
                case 3:
                    content += "Chilli Concarne Winner Edition,Meksyk,ryż,mielone"
                              "˘1.	Heat oil in a large saucepan over medium heat.  Cook green pepper, and onion, until softened. Add the ground beef and cook until browned. Crumble over bouillon cubes, and stir in wine; continue to cook for a few minutes. Stir in chopped tomatoes, garlic, and tomato paste. Season with paprika, chili powder, cayenne pepper, basil, oregano, and parsley. Stir in salt and pepper. | 2.	Bring to a boil over high heat.  Reduce heat to medium low. Cover, and simmer for 90 minutes, stirring occasionally. | 3.	Stir in  kidney beans, and hot pepper sauce. You can add the reserved tomato juice if more liquid is needed. Continue to simmer for an additional 30 minutes. | 4.	In a small bowl, whisk together the flour, corn meal, and water until smooth. Stir into chili, and cook for a further 10 minutes, or until chili has thickened up."
                              "˘INGREDIENTS:\nvegetable oil: 4 tablespoons\ngreen bell pepper: 1 \nyellow onion: 1 \nbeef: 2 1/2 pounds\nbeef bouillon cube: 2 \nred wine: 2/3 cup\ntomato: 2 cans\ngarlic clove:  \ntomato paste: 1 can\npaprika: 1 1/2 teaspoons\nchili powder: 2 1/2 teaspoons\ncayenne pepper: 1 teaspoon\nbasil: 2 1/2 teaspoons\noregano: 1/2 teaspoon\nparsley: 2 tablespoons\nblack pepper: 1/2 teaspoon\nsalt: 1 teaspoon\nkidney bean: 1 can\nflour: 3 tablespoons\ncorn meal: 3 tablespoons\nwater: 1/2 cup"
                              "˘https://www.swiatobrazu.pl/zdjecie/artykuly/517826/zdjecia-krajobrazu00014.jpg";
                            //qDebug()<< "dish3 created in path: "<< filePath<< "with content of: \n"<< content;
                    break;
                }
                textStream << content;
                file.close();
            }
        }
    }

    QFile csv(systemManager::getDocumentsPath() + "/FlavourCraft/index.csv");
    if (csv.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        QTextStream csvStream(&csv);
        QDir directory(dataPath);
        QStringList txtFiles = directory.entryList(QStringList() << "*.txt", QDir::Files);
        foreach (const QString& txtFile, txtFiles)
        {
            QString filePath = directory.filePath(txtFile);
            QFile file(filePath);
            if (file.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QString filePath = directory.filePath(txtFile);
                QTextStream textStream(&file);
                QString data = textStream.readAll();
                file.close();

                int firstSeparatorIndex = data.indexOf("˘");
                int lastSeparatorIndex = data.lastIndexOf("˘");

                QString tags = data.left(firstSeparatorIndex); // Wszystko od początku do pierwszego wystąpienia znaku "˘"
                QString photoLink = data.mid(lastSeparatorIndex + 1); // Wszystko po ostatnim wystąpieniu znaku "˘"

                csvStream<< tags+"˘"+photoLink+"˘"+filePath + "\n";
            }
            else
            {
                qDebug() << "Failed to open" << filePath;
            }
        }
    }
        csv.close();
}


