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
        //addLocaleInternetRecipeButton
        if(mainWindow.previousSource == "qrc:/pages/SearchOnlinePage.qml" && mainWindow.currentSource == "qrc:/pages/DishPage.qml")
        {
            addInternetRecipeToLocal.visible = true
        }
        else
        {
            addInternetRecipeToLocal.visible = false
        }
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

    CustomButton
    {
        id: addInternetRecipeToLocal
        x: parent.width - width - menuButton.width - backButton.width - 24 - 24 - 24
        y: parent.height - height - 24
        property int sourceId: 0
        Text
        {
            color: values.buttonTextColor
            text: "Dodaj\nlokalnie"
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.centerIn: parent
            font.pointSize: 14
        }

        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                //console.log("elo ziomeczku to znowu ja bogaj")
                webTagsInput.visible = true
            }
        }
    }

    Rectangle
    {
        id: webTagsInput
        visible: false
        color: "#40000000"
        width: parent.width
        height: 64
        anchors.fill: parent
        MouseArea
        {
            anchors.fill: parent
        }
        Rectangle
        {
            visible: webTagsInput.visible ? true : false
            anchors.centerIn: parent
            width:parent.width/3
            height: 64
            radius: 9
            color: "#724E91"
            Text
            {
                id: webTagsInputText
                height: parent.height
                width: contentWidth + 20
                text: "tags:   "
                font.family: "Consolas"
                font.italic: true
                font.pointSize: 16
                color: values.buttonColor
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            TextInput
            {
                id: webTagsInputTextInput
                width: parent.width- webTagsInputText.width - 40
                height: parent.height - 10
                anchors
                {
                    leftMargin: 20
                    rightMargin: 20
                    verticalCenter: parent.verticalCenter
                    left: webTagsInputText.right
                }
                verticalAlignment: TextInput.AlignVCenter
                wrapMode: TextInput.Wrap
                maximumLength: 32
                font.family: "Consolas"
                font.italic: true
                font.pointSize: 16
                color: values.buttonColor
            }

        }
        CustomButton
        {
            id: xd
            x: parent.width - width - menuButton.width - backButton.width - 24 - 24 - 24
            y: parent.height - height - 24
            property int sourceId: 0
            Text
            {
                color: values.buttonTextColor
                text: "Dodaj"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.centerIn: parent
                font.pointSize: 14
            }

            MouseArea
            {
                anchors.fill: parent
                onClicked:
                {
                    //console.log("elo ziomeczku to znowu ja bogaj")
                    search_handler.addOnlineDish(webTagsInputTextInput.text);
                    webTagsInput.visible = false
                }
            }
        }
    }

}
