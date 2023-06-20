#pragma once

#include <QNetworkAccessManager>
#include <QUrl>
#include <QString>
#include <QNetworkReply>
#include <QObject>
#include <QNetworkRequest>
#include <QUrlQuery>
#include <QFile>
#include <vector>

class recipeRestHandler : public QObject
{
	Q_OBJECT
	protected:
		QUrl url;
		QNetworkAccessManager* nm;
	public:
		recipeRestHandler();
		recipeRestHandler(QUrl url);
		~recipeRestHandler();
		void setUrl(QUrl url);
		void sendPostReq(QString query);
		void sendGetReq();
	public slots:
		virtual void onFinish(QNetworkReply* rep);
};

