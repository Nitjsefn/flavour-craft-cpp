
#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include <QDebug>
#include <QStandardPaths>
#include <QSysInfo>



class systemManager
{
public:
    static void checkSystem()
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

    static QString getDocumentsPath()
    {
        return QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    }

private:
    static bool isWindows()
    {
        return QSysInfo::productType().toLower().contains("windows");
    }

    static bool isLinux()
    {
        return QSysInfo::productType().toLower().contains("linux");
    }
};

#endif // SYSTEMMANAGER_H
