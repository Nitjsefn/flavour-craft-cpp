import QtQuick 2.15
import QtQuick.Controls 2.15


Rectangle
{
    id: indegrientsContainer
    color: "#fae3c6"
    width: parent.width/4
    height: parent.height - photoContainer.heigth
    anchors
    {
        top: photoContainer.bottom
        right: parent.right
        bottom: parent.bottom
    }

    Label
    {
        width: parent.width
        height: 50
        Text
        {
            id: indegrientsTitle
            color: "#533B4D"
            text: qsTr("Ingredients:")
            font.family: "Consolas"
            font.italic: true
            font.pointSize: 20
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    Rectangle
    {
        id: indegrients
        color: "#c1aba6"
        anchors.centerIn: parent
        width: parent.width - 100
        height: parent.height - 100
        radius: 6
        Text
        {
            id: indegrientsItems
            color: "#533B4D"
            text: qsTr("pork chop: 2 boneless
salt black pepper: to taste
purpose flour: 1 tablespoon
egg: 1
bread crumb: 5 tablespoons
vegetable oil: 2 tablespoons")
            font.family: "Consolas"
            font.italic: true
            font.pointSize: 12
            anchors.fill: parent
            anchors.margins: 5
            wrapMode: Text.WordWrap
        }

    }
}
