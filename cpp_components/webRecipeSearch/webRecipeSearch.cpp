#include "webRecipeSearch.h"
#include "cpp_components/recipeRestHandler/recipeRestHandler.h"

webRecipeSearch::webRecipeSearch() {}

webRecipeSearch::webRecipeSearch(QUrl url)
	: recipeRestHandler(url) {}

void webRecipeSearch::setRecipeQuery(QString query)
{
	this->recipeQuery = query;
}

void webRecipeSearch::getRecipes()
{

	foundRecipes.clear();
	//for(int i = 0; i < recipeQuery.length(); i++)
	//{
	//	if(recipeQuery[i] == ' ') recipeQuery[i] = '+';
	//}
	this->sendPostReq(recipeQuery);
}


void webRecipeSearch::getRecipes(QString query)
{
	this->setRecipeQuery(query);
	this->getRecipes();
}

void webRecipeSearch::onFinish(QNetworkReply* rep)
{
	QFile file("test.web.file.html");
	file.open(QIODevice::ReadWrite);
	file.write(rep->readAll());
	file.close();
	if(nullptr == rep) return;
	rep->deleteLater();
}

