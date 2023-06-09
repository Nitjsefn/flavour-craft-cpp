#include "webRecipeSearch.h"

webRecipeSearch::webRecipeSearch() {}

webRecipeSearch::webRecipeSearch(QUrl url)
	: recipeRestHandler(url) {}

void webRecipeSearch::setRecipeQuery(QString query)
{
	this->recipeQuery = query;
}

void webRecipeSearch::searchForRecipes()
{

	foundRecipes.clear();
	//for(int i = 0; i < recipeQuery.length(); i++)
	//{
	//	if(recipeQuery[i] == ' ') recipeQuery[i] = '+';
	//}
	this->sendPostReq(recipeQuery);
}


void webRecipeSearch::searchForRecipes(QString query)
{
	this->setRecipeQuery(query);
	this->getRecipes();
}

std::vector<webRecipeScraper::foundRecipe> webRecipeSearch::getRecipes()
{
	return foundRecipes;
}

void webRecipeSearch::onFinish(QNetworkReply* rep)
{
	if(nullptr == rep) return;
	webRecipeScraper::scrapRecipesList(rep, &foundRecipes);
	rep->deleteLater();
	emit finished(foundRecipes);
}

