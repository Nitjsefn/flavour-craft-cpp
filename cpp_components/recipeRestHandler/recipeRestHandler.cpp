#include "recipeRestHandler.h"

recipeRestHandler::recipeRestHandler()
{
	nm = new QNetworkAccessManager();
	QObject::connect(nm, &QNetworkAccessManager::finished\
			, this, &recipeRestHandler::onFinish);
i = 0;
}

recipeRestHandler::recipeRestHandler(QUrl url)
	: url(url)
{i=0;
	nm = new QNetworkAccessManager();
	QObject::connect(nm, &QNetworkAccessManager::finished\
			, this, &recipeRestHandler::onFinish);
}

recipeRestHandler::~recipeRestHandler()
{
	delete nm;
}

void recipeRestHandler::setUrl(QUrl url)
{
	this->url = url;
}

void recipeRestHandler::sendPostReq(QString query)
{
	QNetworkRequest req(url);
	req.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
	QUrlQuery postData;
	postData.addQueryItem("page", "");
	postData.addQueryItem("autocomplete_region", "");
	postData.addQueryItem("autocomplete_cuisine", "");
	postData.addQueryItem("autocomplete_recipe", query);
	nm->post(req, postData.toString().toUtf8());
}

void recipeRestHandler::sendGetReq()
{
	QNetworkRequest req(url);
	nm->get(req);
}

void recipeRestHandler::onFinish(QNetworkReply* rep)
{QString fn = (i == 0) ? "test.web1.html" : "test.web2.html";
	QByteArray header;
	rep->rawHeader(header);;
	QFile file(fn);
	file.open(QIODevice::ReadWrite);
	file.write(rep->readAll());
	file.close();
	if(nullptr == rep) return;
	rep->deleteLater();
	i++;
	qDebug() << "Finished\n";
}

