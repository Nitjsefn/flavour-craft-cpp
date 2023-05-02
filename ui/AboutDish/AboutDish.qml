import QtQuick 2.15
import QtQuick.Controls 2.15


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
        width: parent.width
        height: 50
        Text
        {
            id: descriptionTitle //dish title
            color: "#533B4D"
            text: qsTr("Sushi")
            font.family: "Consolas"
            font.italic: true
            font.pointSize: 28
            x: parent.x + parent.width/10
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    Rectangle
    {
        id: description
        color: "#c1aba6"
        anchors.centerIn: parent
        width: parent.width - 100
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
                width: descriptionScrollViev.width
                height: contentHeight
                id: descriptionText
                color: "#533B4D"
                font.family: "Consolas"
                font.pointSize: 12
                wrapMode: Text.Wrap
                text: "Przygotowanie:
Ryż:
Ryż ugotować zgodnie z instrukcją na opakowaniu.
Przygotować zaprawę do ryżu. W tym celu należy wymieszać 2 łyżki octu ryżowego z 2 łyżeczkami cukru i 1/2 łyżeczką soli. Zaprawą polać ugotowany ryż i dokładnie wymieszać. Ryż studzić pod przykryciem.
Przygotowanie:

Warzywa pokroić wzdłuż w cienkie paski.
To samo robimy z awokado i łososiem.

Rozkładamy matę do sushi.
Na macie układamy listek nori, błyszczącą stroną do dołu.
Do małej miseczki wlewamy zimnej wody i dodajemy łyżkę octu ryżowego. Woda będzie nam służyła do zwilżenia rąk, by łatwiej rozprowadzało się ryż.
Zwilżamy dłoń i rozprowadzamy ostudzony ryż na listku nori. Powinien być w całości pokryty z wyjątkiem wąskiego paska od góry.

Na wyłożony ryż układamy nasze ulubione dodatki. Spokojnie mogą wystawać, obetnie się je później.

Zwijamy delikatnie naszą rolkę.

Gotową rolkę kroimy na mniejsze kawałki. Przed podaniem sushi trzymamy w lodówce.
Domowe sushi podajemy z wasabi, sosem sojowym, marynowanym imbirem i innymi ulubionymi dodatkami."
            }
        }

    }

    //Testing purpouses
    Button
    {
        z:1
        x: parent.width - 100
        y: parent.height - 100
        width: 50
        height: 50
        background: Rectangle
        {
            color:"red"
            radius: 6
            Text
            {
                text: "test"
            }
        }
        onClicked:
        {
            dish_handler.loadDish(descriptionTitle.text)
        }
    }
}
