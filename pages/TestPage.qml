import QtQuick 2.15
import QtQuick.Controls 2.15



Rectangle
{
    anchors.fill: parent
    color: "#C97D60"

    //Testing purpouses
    Row
    {
        anchors.centerIn: parent
        spacing: 20

        Button
        {
            width: 100
            height: 75
            background: Rectangle
            {
                color: "#F2E5D7"//"#724E91"
                radius: 6
                Text
                {
                    anchors.centerIn: parent
                    color: "#533B4D"
                    font.family: "Consolas"
                    font.pointSize: 12
                    wrapMode: Text.Wrap
                    text: "testbutton1"
                }
            }
            onClicked:
            {
                search_handler.testFuntion_1();
            }
        }

        Button
        {
            width: 100
            height: 75
            background: Rectangle
            {
                color: "#F2E5D7"//"#724E91"
                radius: 6
                Text
                {
                    anchors.centerIn: parent
                    color: "#533B4D"
                    font.family: "Consolas"
                    font.pointSize: 12
                    wrapMode: Text.Wrap
                    text: "testbutton2"
                }
            }
            onClicked:
            {
                search_handler.testFuntion_2();
            }
        }

        Button
        {
            width: 100
            height: 75
            background: Rectangle
            {
                color: "#F2E5D7"//"#724E91"
                radius: 6
                Text
                {
                    anchors.centerIn: parent
                    color: "#533B4D"
                    font.family: "Consolas"
                    font.pointSize: 12
                    wrapMode: Text.Wrap
                    text: "testbutton3"
                }
            }
            onClicked:
            {
                search_handler.testFuntion_3();
            }
        }
    }


}
