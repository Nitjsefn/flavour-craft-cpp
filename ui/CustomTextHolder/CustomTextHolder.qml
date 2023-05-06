import QtQuick 2.15

Rectangle
{
    color: "#F2E5D7"
    radius: 9
    width: parent.width
    height: parent.height
    property alias aboutText: customText.text
    property alias aboutImage: customImage.source
    property alias eLink: customText.elink

    Column
    {
        width: parent.width - 32
        height: parent.height - 32
        y: 32
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 20

        Image
        {
            id: customImage
            source: "default"
            width: 128
            height: 128
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Text
        {
            id: customText
            property string elink: "value"
            text: "default"
            width: parent.width
            anchors.horizontalCenter: parent.horizontalCenter
            color: "#724E91"
            textFormat: Text.RichText
            font.family: "Consolas"
            font.italic: true
            font.pointSize: 11
            wrapMode: Text.Wrap
            horizontalAlignment: Text.AlignHCenter
            onLinkActivated: Qt.openUrlExternally(elink)
        }
    }
    /* font.color: "#724E91"
    font.family: "Consolas"
    font.italic: true
    font.pointSize: 11
    */

}
