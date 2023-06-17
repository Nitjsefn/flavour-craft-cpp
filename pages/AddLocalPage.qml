import QtQuick 2.15
import QtQuick.Controls 2.15

import "qrc:/ui/CustomButton"
import "qrc:/ui/Values"

Rectangle
{
    id: addLocalPage
    width: parent.width
    height: parent.height
    anchors.fill: parent
    color: "#11131A"

    Values
    {
        id: values
    }

    ScrollView
    {
        width: parent.width/6*4
        height: parent.height/6*3
        //clip: true
        anchors.centerIn: parent

        ScrollBar.horizontal: ScrollBar
        {
            policy: Qt.ScrollBarAlwaysOff
        }

        Column
        {
            width: parent.width
            spacing: 20
            anchors.centerIn:  parent

            Rectangle //titleBar
            {
                id: titleRecipeInput
                width: parent.width
                height: 64
                color: "#724E91"
                radius: 9
                Text
                {
                    id: titleRecipeText
                    anchors
                    {
                        left: parent.left
                        leftMargin: 20
                        rightMargin: 20
                        verticalCenter: parent.verticalCenter
                    }
                    verticalAlignment: TextInput.AlignVCenter
                    font.family: "Consolas"
                    font.italic: true
                    font.pointSize: 18
                    color: values.buttonColor
                    text: qsTr("Name:    ")
                }
                TextInput
                {
                    id: titleRecipeInputText
                    width: parent.width - 40 - titleRecipeText.width
                    height: parent.height - 10
                    anchors
                    {
                        right: parent.right
                        leftMargin: 20
                        rightMargin: 20
                        verticalCenter: parent.verticalCenter
                    }
                    verticalAlignment: TextInput.AlignVCenter
                    wrapMode: TextInput.Wrap
                    maximumLength: 32
                    font.family: "Consolas"
                    font.italic: true
                    font.pointSize: 16
                    color: values.buttonColor
                }
            }

            Rectangle //countryBar
            {
                id: countryRecipeInput
                width: parent.width
                height: 64
                color: "#724E91"
                radius: 9
                Text
                {
                    id: countryRecipeText
                    anchors
                    {
                        left: parent.left
                        leftMargin: 20
                        rightMargin: 20
                        verticalCenter: parent.verticalCenter
                    }
                    verticalAlignment: TextInput.AlignVCenter
                    font.family: "Consolas"
                    font.italic: true
                    font.pointSize: 18
                    color: values.buttonColor
                    text: qsTr("Country:    ")
                }
                TextInput
                {
                    id: countryRecipeInputText
                    width: parent.width - 40 - countryRecipeText.width
                    height: parent.height - 10
                    anchors
                    {
                        right: parent.right
                        leftMargin: 20
                        rightMargin: 20
                        verticalCenter: parent.verticalCenter
                    }
                    verticalAlignment: TextInput.AlignVCenter
                    wrapMode: TextInput.Wrap
                    maximumLength: 32
                    font.family: "Consolas"
                    font.italic: true
                    font.pointSize: 16
                    color: values.buttonColor
                }
            }

            Rectangle //tagsBar
            {
                id: tagsRecipeInput
                width: parent.width
                height: 64
                color: "#724E91"
                radius: 9
                Text
                {
                    id: tagsRecipeText
                    anchors
                    {
                        left: parent.left
                        leftMargin: 20
                        rightMargin: 20
                        verticalCenter: parent.verticalCenter
                    }
                    verticalAlignment: TextInput.AlignVCenter
                    font.family: "Consolas"
                    font.italic: true
                    font.pointSize: 18
                    color: values.buttonColor
                    text: qsTr("Tags:    ")
                }
                TextInput
                {
                    id: tagsRecipeInputText
                    width: parent.width - 40 - tagsRecipeText.width
                    height: parent.height - 10
                    anchors
                    {
                        right: parent.right
                        leftMargin: 20
                        rightMargin: 20
                        verticalCenter: parent.verticalCenter
                    }
                    verticalAlignment: TextInput.AlignVCenter
                    wrapMode: TextInput.Wrap
                    maximumLength: 32
                    font.family: "Consolas"
                    font.italic: true
                    font.pointSize: 16
                    color: values.buttonColor
                }
            }

            Rectangle //stepsBar
            {
                id: stepsRecipeInput
                width: parent.width
                height: stepsRecipeInputText.height + 20
                color: "#724E91"
                radius: 9
                Text
                {
                    id: stepsRecipeText
                    anchors
                    {
                        left: parent.left
                        leftMargin: 20
                        rightMargin: 20
                        verticalCenter: parent.verticalCenter
                    }
                    verticalAlignment: TextInput.AlignVCenter
                    font.family: "Consolas"
                    font.italic: true
                    font.pointSize: 18
                    color: values.buttonColor
                    text: qsTr("Steps:    ")
                }
                TextEdit
                {
                    id: stepsRecipeInputText
                    width: parent.width - 40 - stepsRecipeText.width
                    height: contentHeight
                    anchors
                    {
                        right: parent.right
                        leftMargin: 20
                        rightMargin: 20
                        verticalCenter: parent.verticalCenter
                    }
                    verticalAlignment: TextInput.AlignVCenter
                    wrapMode: TextInput.Wrap
                    font.family: "Consolas"
                    font.italic: true
                    font.pointSize: 16
                    color: values.buttonColor
                }
            }

            Rectangle //IngredientsBar
            {
                id: ingredientsRecipeInput
                width: parent.width
                height: ingredientsRecipeInputText.height + 20
                color: "#724E91"
                radius: 9
                Text
                {
                    id: ingredientsRecipeText
                    anchors
                    {
                        left: parent.left
                        leftMargin: 20
                        rightMargin: 20
                        verticalCenter: parent.verticalCenter
                    }
                    verticalAlignment: TextInput.AlignVCenter
                    font.family: "Consolas"
                    font.italic: true
                    font.pointSize: 18
                    color: values.buttonColor
                    text: qsTr("Ingredients:    ")
                }
                TextEdit
                {
                    id: ingredientsRecipeInputText
                    width: parent.width - 40 - ingredientsRecipeText.width
                    height: contentHeight
                    anchors
                    {
                        right: parent.right
                        leftMargin: 20
                        rightMargin: 20
                        verticalCenter: parent.verticalCenter
                    }
                    verticalAlignment: TextInput.AlignVCenter
                    wrapMode: TextInput.Wrap
                    font.family: "Consolas"
                    font.italic: true
                    font.pointSize: 16
                    color: values.buttonColor
                }
            }

            Rectangle //phothoLinkBar
            {
                id: phothoLinkRecipeTitle
                width: parent.width
                height: 64
                color: "#724E91"
                radius: 9
                Text
                {
                    id: phothoLinkRecipeText
                    anchors
                    {
                        left: parent.left
                        leftMargin: 20
                        rightMargin: 20
                        verticalCenter: parent.verticalCenter
                    }
                    verticalAlignment: TextInput.AlignVCenter
                    font.family: "Consolas"
                    font.italic: true
                    font.pointSize: 18
                    color: values.buttonColor
                    text: qsTr("Photo Link:    ")
                }
                TextInput
                {
                    id: phothoLinkRecipeInput
                    width: parent.width - 40 - phothoLinkRecipeText.width
                    height: parent.height - 10
                    anchors
                    {
                        right: parent.right
                        leftMargin: 20
                        rightMargin: 20
                        verticalCenter: parent.verticalCenter
                    }
                    verticalAlignment: TextInput.AlignVCenter
                    wrapMode: TextInput.Wrap
                    maximumLength: 32
                    font.family: "Consolas"
                    font.italic: true
                    font.pointSize: 16
                    color: values.buttonColor
                }
            }

            CustomButton
            {
                id: addButton
                anchors.horizontalCenter: parent.horizontalCenter
                Text
                {
                    color: values.buttonTextColor
                    text: "Add Recipe"
                    font.bold: true
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    anchors.centerIn: parent
                    font.pointSize: 16
                }
                MouseArea
                {
                    anchors.fill: parent
                    onClicked:
                    {
                        search_handler.createNewDish(titleRecipeInputText.text, countryRecipeInputText.text, tagsRecipeInputText.text,
                                                     stepsRecipeInputText.text, ingredientsRecipeInputText.text, phothoLinkRecipeInput.text);
                        mainLoader.source = "qrc:/pages/MainPage.qml"
                        mainWindow.navigationButtons = 0
                    }
                }
            }
        }
    }
}
