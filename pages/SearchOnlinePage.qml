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
            source: "qrc:/assets/ui/Assets/iconmonstr-folder-30.svg"
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
                    console.log("searchButton clicked")
                    search_handler.searchDish(recipeInput.text)

                    //zsearchowane obiekty niech referencjuje do appendowania nie?

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
            width: parent.width
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
                    text: model.dishName
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
                    font.pointSize: 16
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
                    anchors.fill: parent
                    onClicked:
                    {
                        recipeListView.listViewVisible = false
                        search_handler.loadDish(model.index)
                    }
                }
            }
        }
    }


}
