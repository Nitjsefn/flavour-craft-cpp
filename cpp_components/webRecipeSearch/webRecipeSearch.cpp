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
	this->searchForRecipes();
}

std::vector<webRecipeScraper::foundRecipe> webRecipeSearch::getRecipes()
{
	return foundRecipes;
}

void webRecipeSearch::onFinish(QNetworkReply* rep)
{
	if(nullptr == rep) 
	{
		emit connError();
		return;
	}
	webRecipeScraper::scrapRecipesList(rep, &foundRecipes);
	rep->deleteLater();
	if(0 == foundRecipes.size())
	{
		emit noRecipesFound();
		return;
	}
	emit finished(foundRecipes);
	//for(auto l : foundRecipes)
	//	qDebug() << l.name << ' ' << l.cuisine << ' ' << l.id << '\n';
}

