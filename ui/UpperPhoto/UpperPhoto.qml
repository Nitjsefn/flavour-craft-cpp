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
        anchors.fill: parent
        fillMode: Image.PreserveAspectCrop
        source: "https://images.media-allrecipes.com/userphotos/560x315/4537037.jpg"
    }
}
