import QtQuick 2.15
import QtQuick.Controls 2.15

import "qrc:/ui/CustomButton"
//import "qrc:/ui/SearchBar"
import "qrc:/ui/Values"

Rectangle
{
    id: searchPage
    width: parent.width
    height: parent.height
    anchors.fill: parent
    color: "#11131A"

    Values
    {
        id: values
    }

    Connections
    {
        target: webSearch_handler
        function onConnError()
        {
            //console.log("connection error")
            warningText.text = "Connection error"
            warning.visible = true;
        }
    }

    Connections
    {
        target: webSearch_handler
        function onNoRecipesFound()
        {
            //console.log("no recipe found")
            warningText.text = "No recipe found"
            warning.visible = true;
        }
    }

    Rectangle
    {
        id: warning
        z:1
        visible: false
        anchors.fill: parent
        color: "#80000000"
        Rectangle
        {
            anchors.centerIn: parent
            width: 300;
            height: 150;
            color: values.buttonColor
            radius: 9
            Text
            {
                id: warningText
                anchors.fill: parent
                text: qsTr("")
                font.family: "Consolas"
                font.italic: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 20
                color: values.buttonTextColor
            }
        }
        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                warning.visible = false
            }
        }
    }

    Rectangle //searchBar
    {
        id: recipeInputRectangle
        width: parent.width/6*4
        height: 64
        y: parent.height/6
        anchors.horizontalCenter: parent.horizontalCenter

        color: "#724E91"
        radius: 9

        Image
        {
            id: searchImage
            //width: 48
            //height: 48
            anchors
            {
                left: parent.left
                leftMargin: 20
                verticalCenter: parent.verticalCenter
            }
            source: "qrc:/assets/ui/Assets/iconmonstr-folder-31.svg"
            sourceSize: Qt.size(48, 48)
            fillMode: Image.PreserveAspectFit
        }

        TextInput
        {
            id: recipeInput
            anchors
            {
                left: searchImage.right
                leftMargin: 20
                rightMargin: 20
                verticalCenter: parent.verticalCenter
            }
            width: parent.width - searchImage.width - searchButton.width - 20 - 20 - 20 - 20
            height: parent.height - 10
            //horizontalAlignment: TextInput.AlignRight
            verticalAlignment: TextInput.AlignVCenter
            wrapMode: TextInput.Wrap
            maximumLength: 32
            font.family: "Consolas"
            font.italic: true
            font.pointSize: 16
            color: values.buttonColor
            //background: "#FFFFFF"
        }

        CustomButton
        {
            id: searchButton
            anchors.right: recipeInputRectangle.right
            anchors.rightMargin: 20
            anchors.verticalCenter: parent.verticalCenter
            property bool searchButton: true
            Text
            {
                anchors.centerIn: parent
                text: "Search"
                font.family: "Consolas"
                font.bold: true
                font.pointSize: 16
                color: values.buttonTextColor
            }

            MouseArea
            {
                anchors.fill: parent
                onClicked:
                {
                    webSearch_handler.searchForRecipes(recipeInput.text)
                    recipeInput.clear()
                    recipeListView.listViewVisible = true
                }
            }
        }

    }

    ListView
    {
        id: recipeListView

        width: parent.width/6*4
        height: parent.height/6*3
        y: parent.height/6*2
        anchors.horizontalCenter: parent.horizontalCenter


        property bool listViewVisible: false
        visible: listViewVisible ? true : false

        model: search_handler
        spacing: 20
        delegate: Rectangle //jak wyglada jeden element
        {
            id: delegatedItemPattern
            width: searchPage.width/6*4
            height: 50
            color: "#724E91"
            radius: 15
            border.width: 2
            border.color: "#CCCCCC"
            property int index: ListView.view.currentIndex
            Rectangle
            {
                color: "transparent"
                anchors.fill: parent
                anchors.leftMargin: 20
                anchors.rightMargin: 20 + openButton.width

                Text
                {
                    id: dishName
                    text: model.dishName.length > 45 ? model.dishName.slice(0, 40) + "..." : model.dishName

                    color: values.buttonColor
                    font.family: "Consolas"
                    font.bold: true
                    verticalAlignment: Text.AlignVCenter
                    font.pointSize: 16
                    height: parent.height
                    anchors.left: parent.left
                }

                Text
                {
                    text: model.dishCountry
                    color: values.buttonColor
                    font.family: "Consolas"
                    font.bold: true
                    verticalAlignment: Text.AlignVCenter
                    font.pointSize: 12
                    height: parent.height
                    anchors.right: parent.right
                }
            }

            CustomButton
            {
                id: openButton
                anchors.right: parent.right
                Text
                {
                    anchors.centerIn: parent
                    text: "Open"
                    font.family: "Consolas"
                    font.bold: true
                    font.pointSize: 16
                    color: values.buttonTextColor
                }

                MouseArea
                {
                    //signal ustawWzor(string wzor)
                    anchors.fill: parent
                    onClicked:
                    {
                        recipeListView.listViewVisible = false
                        search_handler.loadOnlineDish(model.index);
                        search_handler.clearDishes();
                    }
                }
            }
        }
    }

    Rectangle
    {
        id: dishImageItem
        visible: false
        anchors.fill: parent
        color: "#80000000"
        Image
        {
            id: dishImage
            //source: "file"
            property alias pathImage: dishImage.source
            width: parent.width/3*2
            height: parent.height/3*2
            anchors.centerIn: parent
            MouseArea
            {
                anchors.fill: parent
                onClicked:
                {
                    dishImageItem.visible = false
                    testButton.visible = true
                    backButton.visible = true
                    menuButton.visible = true
                }
            }
        }
        Text
        {
            id: dishImageTitleText
            //text: qsTr()
            font.family: "Consolas"
            font.bold: true
            font.pointSize: 12
            color: values.buttonColor
            y: dishImage.y + dishImage.height + 10
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Text
        {
            id: dishImageDescriptionText
            text: qsTr("kliknij obrazek aby zamknąć")
            font.family: "Consolas"
            font.bold: true
            font.pointSize: 8
            color: values.buttonColor
            y: dishImageTitleText.y + dishImageTitleText.height + 2
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
