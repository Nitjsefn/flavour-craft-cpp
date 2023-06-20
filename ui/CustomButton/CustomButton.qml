import QtQuick 2.15
import QtQuick.Controls 2.15

import "qrc:/ui/Values"

Rectangle
{
    Values
    {
        id: values
    }

    width: 144
    height: 48
    radius: 15
    color: values.buttonColor

    //border.color: "black"
    //border.width: 4

    HoverHandler
    {
        onHoveredChanged:
        {
                if(hovered)
                {
                    parent.color = "#7F7F7F"
                }
                else
                {
                    parent.color = values.buttonColor
                }
        }
    }
}

/*
        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                //console.log("searchButton clicked")
            }
        }
  */
