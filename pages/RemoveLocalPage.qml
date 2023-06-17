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

    Component.onCompleted: search_handler.searchLocalDish("")

    Text
    {
        anchors.bottom: recipeListView.top
        height: contentHeight + 20
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Wybierz przepis do usunięcia: "
        color: values.buttonColor
        font.family: "Consolas"
        font.bold: true
        verticalAlignment: Text.AlignVCenter
        font.pointSize: 22
    }

    ListView
    {
        id: recipeListView

        width: parent.width/6*4
        height: parent.height/6*3
        anchors.verticalCenter:  parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter


        property bool listViewVisible: true
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
                    text: model.dishName
                    color: values.buttonColor
                    font.family: "Consolas"
                    font.bold: true
                    verticalAlignment: Text.AlignVCenter
                    font.pointSize: 16
                    height: parent.height
                    anchors.left: parent.left
                }

                Image
                {
                    id: showDishImage
                    //anchors.left: dishName.right
                    anchors.verticalCenter: parent.verticalCenter
                    x: dishName.x + dishName.width + 10
                    source: "qrc:/assets/ui/Assets/iconmonstr-photo-camera-5.svg"
                    height: 24; width: 24;
                    MouseArea
                    {
                        anchors.fill: parent
                        onClicked:
                        {
                            //console.log(model.dishPhotoLink)
                            dishImage.pathImage = model.dishPhotoLink
                            dishImageTitleText.text = model.dishName
                            dishImageItem.visible = true
                            testButton.visible = false
                            backButton.visible = false
                            menuButton.visible = false
                        }
                    }
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
                    text: "delete"
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
                        search_handler.deleteDish(model.index);
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
