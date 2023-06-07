import QtQuick 2.15
import QtQuick.Controls 2.15


Rectangle
{
    id: descriptionContainer
    color: "#fae3c6"
    width: parent.width - indegrientsContainer.width
    height: parent.height - photoContainer.height
    anchors
    {
        top: photoContainer.bottom
        left: parent.left
        right: indegrientsContainer.left
        bottom: parent.bottom
    }

    Label
    {
        width: parent.width
        height: 50
        Text
        {
            id: descriptionTitle //dish title
            color: "#533B4D"
            text: qsTr("Kotlet Schabowy (Polish Breaded Pork Chop)")
            font.family: "Consolas"
            font.italic: true
            font.pointSize: 28
            x: parent.x + parent.width/10
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    Rectangle
    {
        id: description
        color: "#c1aba6"
        anchors.centerIn: parent
        width: parent.width - 100
        height: parent.height - 100
        radius: 6
        ScrollView
        {
            id: descriptionScrollViev
            width: description.width - 100
            height: description.height - 100
            clip: true
            anchors.horizontalCenter:  parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            ScrollBar.horizontal: ScrollBar
            {
                policy: Qt.ScrollBarAlwaysOff
            }

            Text
            {
                width: descriptionScrollViev.width
                height: contentHeight
                id: descriptionText
                color: "#533B4D"
                font.family: "Consolas"
                font.pointSize: 12
                wrapMode: Text.Wrap
                text: ""

            }
        }

    }
}
