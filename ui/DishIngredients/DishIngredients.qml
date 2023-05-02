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
            text: qsTr("Indegrients:")
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
    }
}
