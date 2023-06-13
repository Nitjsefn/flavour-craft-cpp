import QtQuick 2.15
import QtQuick.Controls 2.15


import "qrc:/ui/UpperPhoto"
import "qrc:/ui/AboutDish"
import "qrc:/ui/DishIngredients"

Rectangle
{
    color: "#fae3c6"
    width: parent.width
    height: parent.height
    anchors.fill: parent

    Connections
    {
        target: search_handler
        function onSetUpDish(aboutDish)
        {
            console.log(aboutDish[0],aboutDish[2],aboutDish[3],aboutDish[4])
            dishTitle.text = aboutDish[0]
            //= aboutDish[1]
            descriptionText.text = aboutDish[2]
            indegrientsText.text = aboutDish[3]
            dishPhoto.source = aboutDish[4]
        }
    }

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

    Rectangle
    {
        id: titlesContainer
        width: parent.width
        height: 100
        anchors.top: photoContainer.bottom
        color: "#fae3c6"//"red"//"#fae3c6"
        Rectangle
        {
            id: dishTitleContainer
            width: parent.width/3*2
            height: parent.height
            anchors.left: parent.left
            color: "#fae3c6"
            anchors.leftMargin: 25
            Text
            {
                id: dishTitle
                width: parent.width - 100
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                verticalAlignment: Text.AlignVCenter
                wrapMode: Text.Wrap
                color: "#533B4D"
                text: qsTr("Kotlet Schabowy (Polish Breaded Pork Chop)")
                font.family: "Consolas"
                font.bold: true
                font.pointSize: 24
            }
        }

        Rectangle
        {
            id: indegrientsTitleContainer
            width: parent.width/3
            height: parent.height
            anchors.right: parent.right
            color: "#fae3c6"
            Text
            {
                id: indegrientsTitle
                width: parent.width - 100
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#533B4D"
                text: qsTr("Ingredients:")
                font.family: "Consolas"
                font.italic: true
                font.pointSize: 20
            }
        }
    }


    Rectangle
    {
        id: descriptionContainer
        color: "#fae3c6"
        width: parent.width/3*2
        height: parent.height - photoContainer.height - titlesContainer.height
        anchors.top: titlesContainer.bottom
        anchors.left: parent.left

        Rectangle
        {
            id: description
            color: "#c1aba6"
            anchors.horizontalCenter: parent.horizontalCenter
            y: 25
            width: parent.width - 100
            height: parent.height - 100
            radius: 6

            ScrollView
            {
                id: descriptionScrollViev
                width: description.width - 50
                height: description.height - 50
                clip: true
                anchors.centerIn: parent

                ScrollBar.horizontal: ScrollBar
                {
                    policy: Qt.ScrollBarAlwaysOff
                }

                Text
                {
                    id: descriptionText
                    width: descriptionScrollViev.width
                    height: contentHeight
                    color: "#533B4D"
                    font.family: "Consolas"
                    font.pointSize: 12
                    wrapMode: Text.Wrap
                    text: ""
                }
            }
        }

    }

    Rectangle
    {
        id:indegrientsContainer
        color: "#fae3c6"
        width: parent.width/3
        height: parent.height - photoContainer.height - titlesContainer.height
        anchors.top: titlesContainer.bottom
        anchors.right: parent.right

        Rectangle
        {
            id: indegrients
            color: "#c1aba6"
            anchors.horizontalCenter: parent.horizontalCenter
            y: 25
            width: parent.width - 100
            height: parent.height - 100
            radius: 6

            ScrollView
            {
                id: indegrientsScrollViev
                width: indegrients.width - 25
                height: indegrients.height - 25
                clip: true
                anchors.centerIn: parent

                ScrollBar.horizontal: ScrollBar
                {
                    policy: Qt.ScrollBarAlwaysOff
                }

                Text
                {
                    id: indegrientsText
                    width: indegrientsScrollViev.width
                    height: contentHeight
                    color: "#533B4D"
                    font.family: "Consolas"
                    font.pointSize: 12
                    wrapMode: Text.Wrap
                    text: qsTr("pork chop: 2 boneless
                                salt black pepper: to taste
                                purpose flour: 1 tablespoon
                                egg: 1
                                bread crumb: 5 tablespoons
                                vegetable oil: 2 tablespoons")
                }
            }
        }
    }

}





/*

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
            id: descriptionTitle
            width: parent.width/3*2
            height: 100
            anchors.margins: { left: 10; right: 0 }

            Text
            {
                id: descriptionTitle //dish title
                color: "#533B4D"
                text: qsTr("Kotlet Schabowy (Polish Breaded Pork Chop)")
                font.family: "Consolas"
                font.bold: true

                font.pointSize: 24
                wrapMode: Text.Wrap
                x: parent.x + parent.width/10
                anchors.verticalCenter: parent.verticalCenter
                width: parent.width/3*2

            }
        }

        Rectangle
        {
            id: description
            color: "#c1aba6"
            anchors.centerIn: parent
            width: parent.width - 150
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
                    id: descriptionText
                    width: descriptionScrollViev.width
                    height: contentHeight
                    color: "#533B4D"
                    font.family: "Consolas"
                    font.pointSize: 12
                    wrapMode: Text.Wrap
                    text: ""
                }
            }
        }
    }



    Rectangle
    {
        id: indegrientsContainer
        color: "#fae3c6"
        width: parent.width/3
        height: parent.height - photoContainer.heigth
        anchors
        {
            top: photoContainer.bottom
            right: parent.right
            bottom: parent.bottom
        }

        Label
        {
            id: titleOfIndegrients
            width: parent.width
            height: 50
            anchors
            {
                top: parent.top
                right: parent.right
            }

            Text
            {
                id: indegrientsTitle
                color: "#533B4D"
                text: qsTr("Ingredients:")
                font.family: "Consolas"
                font.italic: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 20
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        Rectangle
        {
            id: indegrients
            color: "#c1aba6"
            anchors.top: titleOfIndegrients.bottom
            anchors.horizontalCenter: parent
            width: parent.width - 100
            height: indegrientsItems.height + 100
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
                anchors.margins: 30
                anchors.centerIn: parent
                wrapMode: Text.WordWrap
            }

        }
    }


}
*/
