import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls 2.15




Rectangle
{
    height: parent.height
    width: parent.width
    anchors.fill: parent
    Button
    {
        id: buttonik
        width: 50
        height: 50
        anchors.horizontalCenter: parent.horizontalCenter
        text: "update"
        onClicked:
        {
            gridLayout.updateIndegrients(["9","8","7","6"])
        }
    }

    Grid
    {
        id: gridLayout
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: buttonik.bottom
        columns: 2
        columnSpacing: 30
        spacing: 10
        property var indegrients: ["1","2","3","4","5"]

        Repeater
        {
            id: repeater
            model: gridLayout.indegrients.length
            Text
            {
                text: modelData
            }
        }


        function updateIndegrients(newIndegrients)
        {
            indegrients = newIndegrients
            repeater.model = indegrients
            gridLayout.forceLayout();
        }
    }
}
