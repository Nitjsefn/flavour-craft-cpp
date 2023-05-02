import QtQuick 2.15

import "qrc:/ui/UpperPhoto"
import "qrc:/ui/AboutDish"
import "qrc:/ui/DishIngredients"

Rectangle
{
    color: "#fae3c6"
    width: parent.width
    height: parent.height
    anchors.fill: parent

    UpperPhoto
    {
        id:photoContainer
    }

    AboutDish
    {
        id:descriptionContainer
    }

    DishIngredients
    {
        id:indegrientsContainer
    }
}
