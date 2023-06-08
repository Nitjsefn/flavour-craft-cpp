#include "cpp_components/webRecipeScraper/webRecipeScraper.h"
#include <sstream>

int webRecipeScraper::scrapRecipesList(QNetworkReply* webPagePtr, std::vector<foundRecipe>* foundRecipes)
{
	std::string* webPageS = new std::string;
	stringify(webPagePtr, *webPageS);
	std::istringstream webPage(*webPageS);
	delete webPageS;
	std::string line;
    int lineL;
// <tbody>
	std::string pattern = "<tbody>";
    int patternL = pattern.length();
    bool found = false;
    while(std::getline(webPage, line))
    {
        found = trimStartsWith(line, pattern);
        if(found) break;
    }
    if(!found) return foundRecipes->size();

// </tbody>
    pattern = "</tbody>";
    patternL = pattern.length();
    found = false;
    foundRecipe recipe;
    while(std::getline(webPage, line))
    {
        if(found)
        {
            int i = 0;
            while(line[i] == ' ' || line[i] == '\t') i++;
            recipe.name = line.sliced(i);
            foundRecipes->push_back(recipe);
            found = false;
            continue;
        }
        if(trimStartsWith(line, "<a href='/recipedb/search_recipeInfo/"))
		{
			std::vector<int> indxs = boyerMooreStringSearch(line, "search_recipeInfo/");
            int i = indxs.at(0) + 18;
            while(line[i] != '\'') i++;
            recipe.id = line.sliced(indxs.at(0)+18, i - 18 - indxs.at(0));
            found = true;
            continue;
        }
        if(trimStartsWith(line, pattern)) break;
    }
    return foundRecipes->size();
}

bool webRecipeScraper::trimStartsWith(std::string &text, std::string pat)
{
    int patL = pat.length();
    int textL = text.length();
    int i = 0;
    int j = 0;
    while(i < textL && (text[i] == '\t' || text[i] == ' ')) i++;
    while(j < patL && text[i+j] == pat[j]) j++;
    if(j == patL) return true;
    return false;
}

std::vector<int> webRecipeScraper::boyerMooreStringSearch(std::string text, std::string pattern)
{
    std::vector<int> indxs;
    int tL = text.length();
    int patL = pattern.length();
// Creating shift array
    int p[256];
    std::fill(p, p+256, -1);
    for(int i = 0; i < patL; i++) p[(int)pattern[i]] = i;
// Actual searching
    int i = 0;
    while(i <= tL-patL)
    {
        int j = patL - 1;
        while(j > -1 && text[i+j] == pattern[j]) j--;
        if(j == -1)
        {
            indxs.push_back(i);
            i++;
        }
        //max() required in case of: (example) text=abaabaaba, pattern=aba
        else i += std::max(1, j - p[(int)text[i+j]]);
    }
    return indxs;
}

void stringify(QIODevice* in, std::string &out)
{
	stringBuilder sb(out);
	char c;
	while(in->getChar(&c))
		sb.add(c);
	sb.build();
}
