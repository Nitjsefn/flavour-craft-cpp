#include "cpp_components/webRecipeGetter/webRecipeGetter.h"

void webRecipeGetter::fillDish()
{
	// dishData -> *dishToFill
	*dishToFill = Dish(dishData.dishName, dishData.dishRecipeSteps, dishData.dishIndegrients, dishData.dishPhotoLink, dishData.dishCountry, dishToFill->getDishIndex());
}

bool webRecipeGetter::isDishEmpty()
{
	int sum = 0;
	if("" != dishData.dishCountry) sum++;
	if("" != dishData.dishIndegrients) sum++;
	if("" != dishData.dishName) sum++;
	if("" != dishData.dishPhotoLink) sum++;
	if("" != dishData.dishRecipeSteps) sum++;
	return !sum;
}

webRecipeGetter::webRecipeGetter() {}

webRecipeGetter::webRecipeGetter(Dish* dish)
{
	dishToFill = dish;
}

void webRecipeGetter::setDish(Dish* dish)
{
	dishToFill = dish;
}

Dish* webRecipeGetter::getDish()
{
	return dishToFill;
}

void webRecipeGetter::getWebRecipe()
{
	dishData = {};
	this->sendGetReq();
}

void webRecipeGetter::getWebRecipe(QUrl url)
{
	this->setUrl(url);
	this->getWebRecipe();
}

void webRecipeGetter::onFinish(QNetworkReply* rep)
{
	if(nullptr == rep) 
	{
		emit connError();
		return;
	}
	webRecipeScraper::scrapRecipe(rep, &dishData);
	rep->deleteLater();
	if(this->isDishEmpty())
	{
		emit emptyDishError();
		return;
	}
	this->fillDish();
	emit finished(dishToFill);
}

void webRecipeGetter::getWebRecipeSlot(Dish* dish)
{
    this->setDish(dish);
    this->getWebRecipe(QUrl(DB_URL_PREFIX+dish->getDishPath()));
}
