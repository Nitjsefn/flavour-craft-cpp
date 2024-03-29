#include "cpp_components/webRecipeScraper/webRecipeScraper.h"

int webRecipeScraper::scrapRecipesList(QNetworkReply* webPagePtr, std::vector<foundRecipe>* foundRecipes)
{
	if(!webPagePtr->bytesAvailable()) return -1;
//	std::string* webPageS = new std::string;
//	stringify(webPagePtr, *webPageS);
//	std::istringstream webPage(*webPageS);
//	delete webPageS;
//	for(char c : webPagePtr->readAll())
//		webPage << c;
	std::stringstream webPage((char*)&(webPagePtr->readAll()[0]));
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
			std::string tempStr = line.substr(i);
            recipe.name = QString::fromStdString(unicodeToAscii(tempStr));
            found = false;
            continue;
        }

        if(trimStartsWith(line, "<a href='/recipedb/search_recipeInfo/"))
		{
			if(recipe.id != "")
            	foundRecipes->push_back(recipe);
			std::vector<int> indxs = boyerMooreStringSearch(line, "search_recipeInfo/");
            int i = indxs.at(0) + 18;
            while(line[i] != '\'') i++;
            recipe.id = QString::fromStdString(line.substr(indxs.at(0)+18, i - 18 - indxs.at(0)));
            found = true;
            continue;
        }

		if(trimStartsWith(line, "<a href='/recipedb/search_subregion/"))
		{
			std::getline(webPage, line);
            int i = 0;
            while(line[i] == ' ' || line[i] == '\t') i++;
            recipe.cuisine = QString::fromStdString(line.substr(i));
            foundRecipes->push_back(recipe);
			recipe = {};
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
	if(0 == textL)
	{
		if(0 == patL) return true;
		return false;
	}
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

void webRecipeScraper::stringify(QIODevice* in, std::string &out)
{
	stringBuilder sb;
	char c;
	while(in->getChar(&c))
		sb.add(c);
	out = sb.build();
}

int webRecipeScraper::scrapRecipe(QNetworkReply *webPagePtr, dishInfo *dishData)
{
	if(!webPagePtr->bytesAvailable()) return -1;
	struct IngredientStruct
	{
		std::string name;
	    std::string quantity;
	    std::string quantityInfo;
	};
	
	struct RecipeStruct
	{
		std::string name;
	    std::string img;
	    std::vector<IngredientStruct> ingredients;
		std::string steps;
	    std::string cuisine;
	};
	
	std::stringstream webPage((char*)&(webPagePtr->readAll()[0]));

    RecipeStruct recipe;
    std::vector<IngredientStruct> ingredients;
    IngredientStruct ingredient;
	std::string line;
    int foundLvl = 0;
    int ingrRowsCounter = 0;
    // Searching for recipe name
    recipe.name = "";
    while(std::getline(webPage, line))
    {
        if(trimStartsWith(line, "<center>"))
        {
            bool start = true;
            int firstChrInLine = 0;
            while(line[firstChrInLine] == ' ' || line[firstChrInLine] == '\t')
                firstChrInLine++;
            for(char c : line.substr(firstChrInLine))
            {
                if(c == '<') start = false;
                else if(c == '>') start = true;
                else if(start) recipe.name += c;
            }
            break;
        }
    }
    // Searching for recipe image
    while(std::getline(webPage, line))
    {
        if(foundLvl == 0 && trimStartsWith(line, "<div class=\"col s12 m5 center\""))
        {
            foundLvl++;
            continue;
        }
        if(foundLvl == 1 && trimStartsWith(line, "<img"))
        {
            int i_start = naiveStringSearch(line, "src=").at(0);
            i_start += 5;
            int i_stop = i_start;
			std::vector<int> i_stop_possible = naiveStringSearch(line, "\" ");
            for(int j : i_stop_possible)
            {
                if(j > i_start) i_stop = j;
            }
            recipe.img = line.substr(i_start, i_stop - i_start);
            foundLvl--;
            break;
        }
    }
    // Searching for cuisine
    while(std::getline(webPage, line))
    {
        if(trimStartsWith(line, "<span cl"))
        {
            if(trimStartsWith(line, "<span class=\"title\"><strong>Cuisine"))
            {
				std::getline(webPage, line);
                int start_indx = 0;
                while(line[start_indx] == ' ' || line[start_indx] == '\t')
                    start_indx++;
                recipe.cuisine = "";
                int tmp = 0;
                while(line[tmp] == ' ' || line[tmp] == '\t') tmp++;
                line = line.substr(tmp);
                for(char c : line)
                {
                    if(foundLvl == 0 && c != '<') recipe.cuisine += c;
                    else if(foundLvl == 0 && c == '<') foundLvl++;
                    else if(foundLvl == 1 && c == '>') foundLvl--;
                }
                break;
            }
        }
    }
    // Searching for steps
    while(std::getline(webPage, line))
    {
        if(foundLvl == 0 && trimStartsWith(line, "<div id=\"st")) foundLvl++;
        else if(foundLvl == 1 && !trimStartsWith(line, "</di"))
        {
            recipe.steps = line;
            foundLvl--;
            break;
        }
    }
    // Searching for ingredients
    while(std::getline(webPage, line))
    {
        if(foundLvl == 0 && trimStartsWith(line, "<div id=\"ingred"))
        {
            foundLvl++;
            continue;
        }
        if(foundLvl == 1 && trimStartsWith(line, "<tbody"))
        {
            foundLvl++;
            continue;
        }
        if(foundLvl == 2 && trimStartsWith(line, "<tr>"))
        {
            ingredient.name = "";
            ingredient.quantity = "";
            ingredient.quantityInfo = "";
            ingrRowsCounter = 0;
            foundLvl++;
            continue;
        }
        if(foundLvl == 3 && trimStartsWith(line, "<td>") && ingrRowsCounter < 3)
        {
            int lineL = line.length();
            for(int i = 0; i < lineL; i++)
            {//Line under is checking if line[i] is first character of ingredient info.
            //Sometimes there is <a href...> tag before the actual info (but after <td>)
                if(foundLvl == 3 && line[i] == '>' && i+1 < lineL && (line[i+1] != '<' || line[i+2] != 'a'))
                {
                    foundLvl++;
                    continue;
                }
                if(foundLvl == 4 && line[i] == '<' && line[i+1] == '/')
                {
                    ingrRowsCounter++;
                    foundLvl--;
                    break;
                }
                if(foundLvl == 4)
                {
                    if(ingrRowsCounter == 0) ingredient.name += line[i];
                    else if(ingrRowsCounter == 1) ingredient.quantity += line[i];
                    else ingredient.quantityInfo += line[i];
                    continue;
                }
            }
            continue;
        }
        if(foundLvl == 3 && trimStartsWith(line, "</tr>"))
        {
            foundLvl--;
            ingredients.push_back(ingredient);
            continue;
        }
        if(foundLvl == 2 && trimStartsWith(line, "</tbody>"))
        {
            foundLvl--;
            recipe.ingredients = ingredients;
            break;
        }
    }
	if(trimStartsWith(recipe.img, "/recipedb/static"))
		recipe.img = "https://cosylab.iiitd.edu.in/recipedb/static/recipe_temp.jpg";
	if(!trimStartsWith(recipe.img, "https://"))
		recipe.img = "";
	dishData->dishName = QString::fromStdString(unicodeToAscii(recipe.name));
	dishData->dishRecipeSteps = QString::fromStdString(humanizeSteps(unicodeToAscii(recipe.steps)));
	dishData->dishCountry = QString::fromStdString(unicodeToAscii(recipe.cuisine));
	dishData->dishPhotoLink = QString::fromStdString(unicodeToAscii(recipe.img));
	for(auto ingredient : recipe.ingredients)
		dishData->dishIndegrients +=\
			QString::fromStdString(unicodeToAscii(ingredient.name)) + ": " +\
			QString::fromStdString(ingredient.quantity) + ' ' +\
			QString::fromStdString(unicodeToAscii(ingredient.quantityInfo)) + '\n';
	return 0;
}

std::vector<int> webRecipeScraper::naiveStringSearch(std::string text, std::string pattern)
{
    std::vector<int> indxs;
    int tL = text.length();
    int patL = pattern.length();
    for(int i = 0; i <= tL-patL; i++)
    {
        int j = 0;
        for(j; text[i+j] == pattern[j] && j < patL; j++);
        if(j == patL) indxs.push_back(i);
    }
    return indxs;
}

std::string webRecipeScraper::humanizeSteps(std::string src)
{
    int srcL = src.length();
    auto sb = stringBuilder();
    int i = 0;
    while(i < srcL && (' ' == src[i] || '\t' == src[i] || '|' == src[i])) i++;
    for(i; i < srcL; i++)
    {
        if(' ' == src[i])
        {
            if(i+1 < srcL && '|' == src[i+1])
            {
                sb.add('\n');
                i++;
                if(i+2 < srcL && ' ' == src[i+1]) i++;
                continue;                
            }
        }
        if('|' == src[i])
        {
            sb.add('\n');
            if(i+1 < srcL && ' ' == src[i+1]) i++;
            continue;
        }
        if('-' == src[i])
        {
            if(i+1 < srcL && '-' == src[i+1])
                if(i+2 < srcL && '-' == src[i+2])
                {
                    break;
                }
                    
        }
        if('\t' == src[i])
        {
            for(int i = 0; i < 4; i++) sb.add(' ');
            continue;
        }
        sb.add(src[i]);
    }
    return sb.build();
}

std::string webRecipeScraper::unicodeToAscii(std::string &src)
{
	stringBuilder sb;
	int srcL = src.length();
	int specialCharLvl = 0;
	std::string specialChar = "";
	for(char c : src)
	{
		if(1 == specialCharLvl)
		{
			if('#' == c)
			{
				specialChar = "";
				specialCharLvl++;
			}
			else if('A' > c || 'z' < c)
			{
				if(webRecipeScraper::unicodeMap.contains(specialChar))
					sb.add(webRecipeScraper::unicodeMap[specialChar]);
				specialCharLvl = 0;
				continue;
			}
			else
			{
				//sb.add('&');
				//sb.add(c);
				//specialCharLvl = 0;
				specialChar += c;
			}
			continue;
		}
		if(2 == specialCharLvl)
		{
			if(';' == c)
			{
				if(webRecipeScraper::unicodeMap.contains(specialChar))
					sb.add(webRecipeScraper::unicodeMap[specialChar]);
				specialCharLvl = 0;
				continue;
			}
			if('0' > c || '9' < c)
			{
				sb.add('&');
				sb.add('#');
				specialCharLvl = 0;
				continue;
			}
			//specialCharNum *= 10;
			//specialCharNum += (c - '0');
			specialChar += c;
			continue;
		}
		if('&' == c)
		{
			specialCharLvl++;
			continue;
		}
		sb.add(c);
	}
	return sb.build();
}

