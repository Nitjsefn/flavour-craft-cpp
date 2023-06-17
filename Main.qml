import QtQuick
import QtQuick.Window
import QtQuick.Controls 2.15

import "qrc:/ui/CustomButton"
import "qrc:/ui/Values"
import "qrc:/pages"


Window
{
    id: mainWindow
    width: 1260
    height: 840

    Component.onCompleted:
    {
        showMaximized();
    }

    minimumWidth: 1260
    minimumHeight: 840

    visible: true
    title: qsTr("FlavourCraft")

    property int navigationButtons: 0
    property string previousSource: "qrc:/pages/MainPage.qml"
    property string currentSource: "qrc:/pages/MainPage.qml"

    Loader
    {
        id: mainLoader
        anchors.fill: parent
        source: "qrc:/pages/MainPage.qml"
    }

    // Funkcja do wywołania po zmianie zawartości Loadera
    function onLoaderContentChanged()
    {
        mainWindow.previousSource = mainWindow.currentSource
        mainWindow.currentSource = mainLoader.source
        if(mainWindow.currentSource === "qrc:/pages/MainPage.qml")
            navigationButtons = 0
        if(mainWindow.previousSource === "qrc:/pages/DishPage.qml")
            mainWindow.previousSource = "qrc:/pages/MainPage.qml"
    }

    Connections
    {
        target: mainLoader
        function onLoaded()
        {
            onLoaderContentChanged()
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

    Connections
        {
            target: webSearch_getter
            function onFinished(source)
            {
                mainLoader.source = "qrc:/pages/DishPage.qml";
            }
        }

    Values
    {
        id: values
    } 

    CustomButton
    {
        id: backButton;
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
        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                mainLoader.source = mainWindow.previousSource
                if(mainLoader.source === "qrc:/pages/MainPage.qml")
                {
                    //console.log("logical value does not depend")
                    mainWindow.navigationButtons = 0;
                }
            }
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

//    CustomButton
//    {
//        id: testButton
//        x: parent.width - width - menuButton.width - backButton.width - 24 - 24 - 24
//        y: parent.height - height - 24
//        property int sourceId: 0
//        Text
//        {
//            color: values.buttonTextColor
//            text: "Test"
//            font.bold: true
//            verticalAlignment: Text.AlignVCenter
//            horizontalAlignment: Text.AlignHCenter
//            anchors.centerIn: parent
//            font.pointSize: 16
//        }
//        MouseArea
//        {
//            anchors.fill: parent
//            onClicked:
//            {
//                if(testButton.sourceId == 0)
//                {
//                    mainLoader.source = "qrc:/pages/DishPage.qml"
//                    testButton.sourceId = 1
//                }
//                else
//                {
//                    mainLoader.source = "qrc:/pages/MainPage.qml"
//                    testButton.sourceId = 0
//                }
//            }
//        }
//    }

}
