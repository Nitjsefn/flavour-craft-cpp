#pragma once

#include <QNetworkAccessManager>
#include <QUrl>
#include <QString>
#include <QNetworkReply>
#include <QObject>
#include <QNetworkRequest>
#include <QUrlQuery>
//#include <QFile>
#include <vector>

class webRecipeSearch : public QObject
{
	Q_OBJECT
	private:
		QString recipeQuery;
		QUrl dbUrl;
		std::vector<QString> foundRecipes;
		QNetworkAccessManager* nm;
	public:
		webRecipeSearch();
		webRecipeSearch(QUrl url);
		~webRecipeSearch();
		void setDbUrl(QUrl url);
		void setRecipeQuery(QString query);
		void getRecipes();
	public slots:
		void onFinish(QNetworkReply* rep);
};


