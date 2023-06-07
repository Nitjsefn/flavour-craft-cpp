#include "webRecipeSearch.h"

webRecipeSearch::webRecipeSearch()
{
	nm = new QNetworkAccessManager();
	QObject::connect(nm, &QNetworkAccessManager::finished\
			, this, &webRecipeSearch::onFinish);
}

webRecipeSearch::webRecipeSearch(QUrl url)
	: dbUrl(url)
{
	nm = new QNetworkAccessManager();
	QObject::connect(nm, &QNetworkAccessManager::finished\
			, this, &webRecipeSearch::onFinish);
}

webRecipeSearch::~webRecipeSearch()
{
	delete nm;
}

void webRecipeSearch::setDbUrl(QUrl url)
{
	this->dbUrl = url;
}

void webRecipeSearch::setRecipeQuery(QString query)
{
	this->recipeQuery = query;
	qDebug() << '\n' << recipeQuery << '\n';
}

void webRecipeSearch::getRecipes()
{

	foundRecipes.clear();
	for(int i = 0; i < recipeQuery.length(); i++)
	{
		if(recipeQuery[i] == ' ') recipeQuery[i] = '+';
	}
	QNetworkRequest req(dbUrl);
	req.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
	QUrlQuery postData;
	postData.addQueryItem("page", "");
	postData.addQueryItem("autocomplete_region", "");
	postData.addQueryItem("autocomplete_cuisine", "");
	postData.addQueryItem("autocomplete_recipe",recipeQuery);
	nm->post(req, postData.toString().toUtf8());
}

void webRecipeSearch::onFinish(QNetworkReply* rep)
{
	//QByteArray header;
	//rep->rawHeader(header);;
	//QFile file("test.web.file.html");
	//file.open(QIODevice::ReadWrite);
	//file.write(rep->readAll());
	//file.close();
	if(nullptr == rep) return;
	rep->deleteLater();
}

