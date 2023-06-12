import QtQuick
import QtQuick.Window
import QtQuick.Controls 2.15


import "qrc:/ui/UpperPhoto"
import "qrc:/ui/AboutDish"
import "qrc:/ui/DishIngredients"
import "qrc:/ui/CustomButton"
import "qrc:/ui/Values"
import "qrc:/pages"


Window
{
    id: mainWindow
    width: 1260
    height: 840


    minimumWidth: 1260
    minimumHeight: 840

    visible: true
    title: qsTr("FlavourCraft")

    property int navigationButtons: 0



    Loader
    {
        id: mainLoader
        anchors.fill: parent
        source: "qrc:/pages/MainPage.qml"
        onLoaded:
        {
            // Załadowano plik Child.qml
            //var childItem = mainLoader.item;
            //console.log(childItem.childProperty); // Wyświetli właściwość childProperty z Child.qml
        }
    }

    Connections
    {
        target: search_handler
        function onLoadDishFinished(source)
        {
            //console.log(source)
            mainLoader.source = source;
        }
    }

    Values
    {
        id: values
    } 

    CustomButton
    {
        id: backButton
        x: parent.width - width - menuButton.width - 24 - 24
        y: parent.height - height - 24
        visible: navigationButtons ? true : false
        Text
        {
            color: values.buttonTextColor
            text: "Back"
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.centerIn: parent
            font.pointSize: 16
        }
    }

    CustomButton
    {
        id: menuButton
        x: parent.width - width - 24
        y: parent.height - height - 24
        visible: navigationButtons ? true : false
        Text
        {
            color: values.buttonTextColor
            text: "Menu"
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.centerIn: parent
            font.pointSize: 16
        }
        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                mainLoader.source = "qrc:/pages/MainPage.qml"
                mainWindow.navigationButtons = 0
            }
        }
    }

    CustomButton
    {
        id: testButton
        x: parent.width - width - menuButton.width - backButton.width - 24 - 24 - 24
        y: parent.height - height - 24
        property int sourceId: 0
        Text
        {
            color: values.buttonTextColor
            text: "Test"
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.centerIn: parent
            font.pointSize: 16
        }
        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                if(testButton.sourceId == 0)
                {
                    mainLoader.source = "qrc:/pages/DishPage.qml"
                    testButton.sourceId = 1
                }
                else
                {
                    mainLoader.source = "qrc:/pages/MainPage.qml"
                    testButton.sourceId = 0
                }
            }
        }
    }

}
