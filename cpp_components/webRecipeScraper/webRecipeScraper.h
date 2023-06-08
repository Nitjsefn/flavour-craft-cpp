#pragma once

#include <QNetworkReply>
#include <qnetworkreply.h>
#include <vector>
#include "cpp_components/dish/dish.h"

namespace webRecipeScraper
{

	struct foundRecipe
	{
		QString id;
		QString name;
		QString cuisine;
	};

	int scrapRecipesList(QNetworkReply* webPage, std::vector<foundRecipe>);
	dishInfo scrapRecipe(QNetworkReply* webPage);
};
