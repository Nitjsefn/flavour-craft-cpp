#pragma once

#include "cpp_components/recipeRestHandler/recipeRestHandler.h"
#include "cpp_components/webRecipeScraper/webRecipeScraper.h"
#include <QNetworkAccessManager>
#include <QUrl>
#include <QString>
#include <QNetworkReply>
#include <QObject>
#include <QNetworkRequest>
#include <QUrlQuery>
#include <fstream>
#include <qtmetamacros.h>
#include <vector>

class webRecipeSearch : public recipeRestHandler
{
	Q_OBJECT
	protected:
		QString recipeQuery;
		std::vector<webRecipeScraper::foundRecipe> foundRecipes;
	public:
		webRecipeSearch();
		webRecipeSearch(QUrl url);
		void setRecipeQuery(QString query);
		void searchForRecipes();
		void searchForRecipes(QString query);
		std::vector<webRecipeScraper::foundRecipe> getRecipes();
	public slots:
		void onFinish(QNetworkReply* rep);
	signals:
		void finished(std::vector<webRecipeScraper::foundRecipe> e);
};

