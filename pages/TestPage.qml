import QtQuick 2.15
import QtQuick.Controls 2.15



Rectangle
{
    anchors.fill: parent
    color: "#C97D60"

    //Testing purpouses
    Button
    {
        anchors.centerIn: parent
        x: parent.width/2
        y: parent.height/2
        width: 100
        height: 75
        background: Rectangle
        {
            color: "#F2E5D7"//"#724E91"
            radius: 6
            Text
            {
                width: parent.width
                height: parent.height
                color: "#533B4D"
                font.family: "Consolas"
                font.pointSize: 12
                wrapMode: Text.Wrap
                text: "http req test button"
            }
        }
        onClicked:
        {
            dish_handler.httpreq();
        }
    }
}
