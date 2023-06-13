
#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include "qdir.h"
#include <QDebug>
#include <QStandardPaths>
#include <QSysInfo>



class systemManager
{
    public:

        static void checkSystem();
        static QString getDocumentsPath();
        static QString documentsPath;
        static QFile getCsvFile();
        static  QDir getTxtLocation();
        static  void createDirectories();

    private:

        static bool isWindows();
        static bool isLinux();


};

#endif // SYSTEMMANAGER_H
