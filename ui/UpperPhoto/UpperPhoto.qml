import QtQuick

Rectangle
{
    id: photoContainer
    //color: "#fae3c6"
    width: parent.width
    height: parent.height/3
    anchors
    {
        top: parent.top
        left: parent.left
        right: parent.right
    }
    Image
    {
        id: dishPhoto
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        fillMode: Image.PreserveAspectFit
        source: "qrc:/assets/ui/Assets/sushi.jpg"
    }
}
