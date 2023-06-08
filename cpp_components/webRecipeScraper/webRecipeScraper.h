#pragma once

#include <QNetworkReply>
#include <QTextStream>
#include <QString>
#include <vector>
#include <iostream>
#include <istream>
#include "cpp_components/dish/dish.h"

namespace webRecipeScraper
{

	struct foundRecipe
	{
		QString id;
		QString name;
		QString cuisine;
	};

	int scrapRecipesList(QNetworkReply* webPage, std::vector<foundRecipe>* foundRecipes);
	dishInfo scrapRecipe(QNetworkReply* webPage);
	bool trimStartsWith(std::string &text, std::string pat);
	std::vector<int> boyerMooreStringSearch(std::string text, std::string pattern);
};
