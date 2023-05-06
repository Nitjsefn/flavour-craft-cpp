import QtQuick 2.15
import QtQuick.Controls 2.15

import "qrc:/ui/CustomButton"
import "qrc:/ui/SearchBar"

Rectangle
{
    id: searchPage
    width: parent.width
    height: parent.height
    anchors.fill: parent
    color: "#11131A"

    SearchBar
    {
        id: searchBar
    }

    /*ListView
    {
        //id: recipeInputRectangle
        width: parent.width/6*4
        height: parent.height/6*3
        y: parent.height/6*2
        anchors.horizontalCenter: parent.horizontalCenter
        ListElement
        {
            name: "Twoja stara"
        }

        //color: "#724E91"
        //radius: 9
    }*/
    ListView {
        id: recipeInputRectangle
            width: parent.width/6*4
            height: parent.height/6*3
            y: parent.height/6*2
            anchors.horizontalCenter: parent.horizontalCenter

            model: ["Item 1", "Item 2", "Item 3"]
            delegate: Rectangle {
                width: parent.width
                height: 50
                color: "#724E91"
                border.width: 2
                border.color: "#CCCCCC"
                Text {
                    text: modelData
                    anchors.centerIn: parent
                }
            }
        }
}
