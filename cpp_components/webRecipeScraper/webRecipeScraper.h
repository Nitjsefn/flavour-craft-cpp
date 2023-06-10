#pragma once

#include <QNetworkReply>
#include <QTextStream>
#include <QString>
#include <vector>
#include <iostream>
#include <sstream>
#include "cpp_components/dish/dish.h"
#include "cpp_components/stringBuilder/stringBuilder.h"

namespace webRecipeScraper
{

	struct foundRecipe
	{
		QString id;
		QString name;
		QString cuisine;
	};

	int scrapRecipesList(QNetworkReply* webPagePtr, std::vector<foundRecipe>* foundRecipes);
	void scrapRecipe(QNetworkReply* webPage, dishInfo* dishData);
	bool trimStartsWith(std::string &text, std::string pat);
	std::vector<int> boyerMooreStringSearch(std::string text, std::string pattern);
	void stringify(QIODevice* in, std::string &out);
};
