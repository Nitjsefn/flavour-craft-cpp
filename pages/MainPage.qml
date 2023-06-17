import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import Qt.labs.platform 1.1

import "qrc:/ui/CustomButton"
import "qrc:/ui/Values"

Rectangle
{
    width: parent.width
    height: parent.height
    anchors.fill: parent

    Values //for additional predifined values
    {
        id: values
    }

    Image     // background image
    {
        id: backgroundImage
        source: "qrc:/assets/ui/Assets/tlo2.png"
        anchors.fill: parent
        fillMode: Image.PreserveAspectCrop
    }

    Rectangle // shadow
    {
        anchors.fill: backgroundImage
        color: "#40000000"
    }

    Text // data copyright
    {
        id: dataLink
        color: "#F2E5D7"
        font.family: "Consolas"
        font.italic: true
        //font.pointSize: 8
        //text: "Data disgraceful \"borrowed\" from:\nhttps://cosylab.iiitd.edu.in/recipedb/\nObraz autorstwa denamorado na Freepik"
        text: 'Recipes <a href="https://cosylab.iiitd.edu.in/recipedb/">database</a>'
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        onLinkActivated: Qt.openUrlExternally("https://cosylab.iiitd.edu.in/recipedb/")
        //anchors.bottom: graphicLink.top
        y: parent.height - height - 10
        x: 20
    }

    Text // graphic copyright
    {
        id: graphicLink
        color: "#F2E5D7"
        font.family: "Consolas"
        font.italic: true
        //font.pointSize: 8
        //text: "Data disgraceful \"borrowed\" from:\nhttps://cosylab.iiitd.edu.in/recipedb/\nObraz autorstwa denamorado na Freepik"
        text: 'Obraz autorstwa denamorado na <a href="https://pl.freepik.com/darmowe-zdjecie/autentyczny-wloski-makaron_7053702.htm#query=Food&position=37&from_view=search&track=robertav1_2_sidr">Freepik</a> '
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        onLinkActivated: Qt.openUrlExternally("https://pl.freepik.com/darmowe-zdjecie/autentyczny-wloski-makaron_7053702.htm#query=Food&position=37&from_view=search&track=robertav1_2_sidr")
        //anchors.bottom: dataLink.top
        y: parent.height - dataLink.height - height - 10
        x: 20
    }

    Column
    {
        anchors.centerIn: parent
        spacing: 24

        Rectangle //title
        {
            color: "transparent"
            width: 256 + 96
            height: 96
            Text
            {
                text: "FlavourCraft"
                color: "#28C2FF"//"#724E91"//"#F2E5D7"//"#533B4D"
                font.family: "Consolas"
                font.italic: true
                font.bold: true
                style: Text.Outline
                styleColor: "#11131A"
                font.pointSize: 68
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        Rectangle //local
        {
            id: localDataBaseButton
            width: 256 + 96
            height: 96
            color: values.buttonColor
            radius: 30
            Rectangle
            {
                id: localDataBaseButtonBackground
                color: values.buttonColor
                radius: 30
                anchors.fill: parent
                Image
                {
                    id: localDataBaseButtonImage
                    sourceSize: Qt.size(80, 80)
                    fillMode: Image.PreserveAspectFit
                    anchors.verticalCenter: parent.verticalCenter
                    //anchors.left: parent.left
                    x: parent.x + 16
                    source: "qrc:/assets/ui/Assets/iconmonstr-folder-30.svg"
                }
                Rectangle
                {
                    width: 256
                    height: 96
                    color: "transparent"
                    anchors.left: localDataBaseButtonImage.right
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    Text
                    {
                        text: "Wyszukaj \nlokalnie"
                        color: "#533B4D"
                        font.pointSize: 24
                        font.family: "Consolas"
                        font.bold: true
                        font.italic: true
                        wrapMode: Text.Wrap
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                        //anchors.right: parent.right
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }
                HoverHandler
                {
                    onHoveredChanged:
                    {
                            if(hovered)
                            {
                                localDataBaseButtonBackground.color = "#80000000"
                            }
                            else
                            {
                                localDataBaseButtonBackground.color = values.buttonColor
                            }
                        //console.log("infoButton hovered")
                    }
                }
            }
            MouseArea
            {
                anchors.fill: parent
                onClicked:
                {
                    mainLoader.source = "qrc:/pages/SearchLocalPage.qml"
                    mainWindow.navigationButtons = 1
                    //console.log("infoButton clicked")
                }
            }
        }

        Row
        {
            id: localDataBaseOptions
            spacing: 20

            Rectangle //local base edit
            {
                id: localDataBaseAdd
                width: 176 - 10
                height: 48
                radius: 30

                Rectangle
                {
                    id: localDataBaseAddBackground
                    color: values.buttonColor
                    radius: 30
                    anchors.fill: parent

                    Image
                    {
                        id: localDataBaseAddBackgroundImage
                        sourceSize: Qt.size(40, 40)
                        fillMode: Image.PreserveAspectFit
                        anchors.verticalCenter: parent.verticalCenter
                        //anchors.left: parent.left
                        x: parent.x + 16
                        source: "qrc:/assets/ui/Assets/iconmonstr-folder-24.svg"
                    }

                    Rectangle
                    {
                        width: 176 - 40 - 20
                        height: 48
                        color: "transparent"
                        anchors.left: localDataBaseAddBackgroundImage.right
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        Text
                        {
                            //width: 120
                            text: "Dodaj\nprzepis"
                            color: "#533B4D"
                            font.pointSize: 12
                            font.family: "Consolas"
                            font.bold: true
                            font.italic: true
                            wrapMode: Text.Wrap
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter: parent.horizontalCenter
                            //anchors.right: parent.right
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                    HoverHandler
                    {
                        onHoveredChanged:
                        {
                                if(hovered)
                                {
                                    localDataBaseAddBackground.color = "#80000000"
                                }
                                else
                                {
                                    localDataBaseAddBackground.color = values.buttonColor
                                }
                            //console.log("aboutButton hovered")
                        }
                    }
                }
                MouseArea
                {
                    anchors.fill: parent
                    onClicked:
                    {
                        //console.log("Add recipe pressed")
                        mainLoader.source = "qrc:/pages/AddLocalPage.qml"
                        mainWindow.navigationButtons = 1
                    }
                }
            }


            Rectangle //local base edit
            {
                id: localDataBaseDelete
                width: 176 - 10
                height: 48
                radius: 30

                Rectangle
                {
                    id: localDataBaseDeleteBackground
                    color: values.buttonColor
                    radius: 30
                    anchors.fill: parent

                    Image
                    {
                        id: localDataBaseDeleteBackgroundImage
                        sourceSize: Qt.size(40, 40)
                        fillMode: Image.PreserveAspectFit
                        anchors.verticalCenter: parent.verticalCenter
                        //anchors.left: parent.left
                        x: parent.x + 16
                        source: "qrc:/assets/ui/Assets/iconmonstr-trash-can-lined.svg"
                    }

                    Rectangle
                    {
                        width: 176 - 40 - 20
                        height: 48
                        color: "transparent"
                        anchors.left: localDataBaseDeleteBackgroundImage.right
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        Text
                        {
                            //width: 120
                            text: "Usuń\nprzepis"
                            color: "#533B4D"
                            font.pointSize: 12
                            font.family: "Consolas"
                            font.bold: true
                            font.italic: true
                            wrapMode: Text.Wrap
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.horizontalCenter: parent.horizontalCenter
                            //anchors.right: parent.right
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                    HoverHandler
                    {
                        onHoveredChanged:
                        {
                                if(hovered)
                                {
                                    localDataBaseDeleteBackground.color = "#80000000"
                                }
                                else
                                {
                                    localDataBaseDeleteBackground.color = values.buttonColor
                                }
                            //console.log("aboutButton hovered")
                        }
                    }
                }
                MouseArea
                {
                    anchors.fill: parent
                    onClicked:
                    {
                        //console.log("Delete recipe pressed")
                        mainLoader.source = "qrc:/pages/RemoveLocalPage.qml"
                        mainWindow.navigationButtons = 1
                    }
                }
            }
        }

        Rectangle //internet
        {
            id: internetDataBaseButton
            width: 256 + 96
            height: 96
            radius: 30
            Rectangle
            {
                id: internetDataBaseButtonBackground
                color: values.buttonColor
                radius: 30
                anchors.fill: parent

                Image
                {
                    id: internetDataBaseButtonImage
                    sourceSize: Qt.size(80, 80)
                    fillMode: Image.PreserveAspectFit
                    anchors.verticalCenter: parent.verticalCenter
                    //anchors.left: parent.left
                    x: parent.x + 16
                    source: "qrc:/assets/ui/Assets/iconmonstr-cloud-32.svg"
                }

                Rectangle
                {
                    width: 256
                    height: 96
                    color: "transparent"
                    anchors.left: internetDataBaseButtonImage.right
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    Text
                    {
                        text: "Wyszukaj \nw sieci"
                        color: "#533B4D"
                        font.pointSize: 24
                        font.family: "Consolas"
                        font.bold: true
                        font.italic: true
                        wrapMode: Text.Wrap
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                        //anchors.right: parent.right
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }
                HoverHandler
                {
                    onHoveredChanged:
                    {
                            if(hovered)
                            {
                                internetDataBaseButtonBackground.color = "#80000000"
                            }
                            else
                            {
                                internetDataBaseButtonBackground.color = values.buttonColor
                            }
                        //console.log("internetButton hovered")
                    }
                }
            }
            MouseArea
            {
                anchors.fill: parent
                onClicked:
                {
                    mainLoader.source = "qrc:/pages/SearchOnlinePage.qml"
                    mainWindow.navigationButtons = 1
                    //console.log("internetButton clicked")
                }
            }
        }

        Rectangle //about
        {
            id: aboutButton
            width: 256 + 96
            height: 96
            radius: 30
            Rectangle
            {
                id: aboutButtonBackground
                color: values.buttonColor
                radius: 30
                anchors.fill: parent

                Image
                {
                    id: aboutButtonImage
                    sourceSize: Qt.size(80, 80)
                    fillMode: Image.PreserveAspectFit
                    anchors.verticalCenter: parent.verticalCenter
                    //anchors.left: parent.left
                    x: parent.x + 16
                    source: "qrc:/assets/ui/Assets/iconmonstr-info-7.svg"
                }

                Rectangle
                {
                    width: 256
                    height: 96
                    color: "transparent"
                    anchors.left: aboutButtonImage.right
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    Text
                    {
                        text: "O aplikacji"
                        color: "#533B4D"
                        font.pointSize: 24
                        font.family: "Consolas"
                        font.bold: true
                        font.italic: true
                        wrapMode: Text.Wrap
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                        //anchors.right: parent.right
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }
                HoverHandler
                {
                    onHoveredChanged:
                    {
                            if(hovered)
                            {
                                aboutButtonBackground.color = "#80000000"
                            }
                            else
                            {
                                aboutButtonBackground.color = values.buttonColor
                            }
                        //console.log("aboutButton hovered")
                    }
                }
            }
            MouseArea
            {
                anchors.fill: parent
                onClicked:
                {
                    mainLoader.source = "qrc:/pages/AboutPage.qml"
                    mainWindow.navigationButtons = 1
                    //console.log("aboutButton clicked")
                }
            }
        }
    }    
}
