#pragma once

#include <QNetworkReply>
#include <QTextStream>
#include <QString>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include "cpp_components/dish/dish.h"
#include "cpp_components/stringBuilder/stringBuilder.h"

namespace webRecipeScraper
{

	struct foundRecipe
	{
        QString id; //przekazujemy id
		QString name;
		QString cuisine;
	};

	static std::map<std::string, char> unicodeMap = 
	{
		{ "33", '!' },
		{ "34", '"' },
		{ "35", '#' },
		{ "36", '$' },
		{ "37", '%' },
		{ "38", '&' },
		{ "amp", '&' },
		{ "39", '\'' },
		{ "59", ';' }
	};

	int scrapRecipesList(QNetworkReply* webPagePtr, std::vector<foundRecipe>* foundRecipes);
	int scrapRecipe(QNetworkReply* webPage, dishInfo* dishData);
	bool trimStartsWith(std::string &text, std::string pat);
	std::vector<int> boyerMooreStringSearch(std::string text, std::string pattern);
	void stringify(QIODevice* in, std::string &out);
	std::vector<int> naiveStringSearch(std::string text, std::string pattern);
	std::string humanizeSteps(std::string src);
	std::string unicodeToAscii(std::string &src);
};
