import QtQuick
import QtQuick.Window
import QtQuick.Controls 2.15


import "qrc:/ui/UpperPhoto"
import "qrc:/ui/AboutDish"
import "qrc:/ui/DishIngredients"
import "qrc:/pages"


Window
{
    id: mainWindow
    width: 1280
    height: 860
    minimumWidth: 860
    minimumHeight: 640
    visible: true
    title: qsTr("FlavourCraft")

    Loader
    {
        id: mainLoader
        anchors.fill: parent
        source: "qrc:/pages/MainPage.qml"
    }

    Button
    {
        z:1
        x: parent.width - 100
        y: parent.height - 100
        width: 50
        height: 50
        property int sourceId: 0
        background: Rectangle
        {
            color:"red"
            radius: 6
            Text
            {

                text: "1111111"
            }
        }
        onClicked:
        {
            if(sourceId == 0)
            {
                mainLoader.source = "qrc:/pages/TestPage.qml"
                sourceId = 1
            }
            else
            {
                mainLoader.source = "qrc:/pages/MainPage.qml"
                sourceId = 0
            }
        }
    }

}
