#pragma once
#define DB_URL_PREFIX "https://cosylab.iiitd.edu.in/recipedb/search_recipeInfo/"

#include "cpp_components/recipeRestHandler/recipeRestHandler.h"
#include "cpp_components/dish/dish.h"
#include "cpp_components/webRecipeScraper/webRecipeScraper.h"
#include <QObject>
#include <QNetworkReply>
#include <QUrl>
#include <qtmetamacros.h>

class webRecipeGetter : public recipeRestHandler
{
	Q_OBJECT

	protected:
		Dish* dishToFill;
		dishInfo dishData;
		void fillDish();
		bool isDishEmpty();
	public slots:
		void onFinish(QNetworkReply* rep);
        void getWebRecipeSlot(Dish* dish);
	public:
		webRecipeGetter();
		webRecipeGetter(Dish* dish);
		void setDish(Dish* dish);
		Dish* getDish();
		void getWebRecipe();
		void getWebRecipe(QUrl url);
	signals:
		void finished(Dish* dish);
		void connError();
		void emptyDishError();
};
