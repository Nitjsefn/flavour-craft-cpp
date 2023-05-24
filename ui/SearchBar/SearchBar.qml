import QtQuick 2.15

import "qrc:/ui/CustomButton"
import "qrc:/ui/Values"

Rectangle
{
    id: recipeInputRectangle
    width: parent.width/6*4
    height: 64
    y: parent.height/6
    anchors.horizontalCenter: parent.horizontalCenter

    color: "#724E91"
    radius: 9

    Values
    {
        id: values
    }

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
                //signal to backend
                dish_handler.searchDish(recipeInput.text)
                recipeListView.listViewVisible = true
            }
        }
    }

}
