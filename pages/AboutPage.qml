import QtQuick 2.15

import "qrc:/ui/CustomTextHolder"


Rectangle
{
    id: aboutContainer
    width: parent.width
    height: parent.height
    anchors.fill: parent
    color: "#11131A"

    Row
    {
        anchors.centerIn: parent
        spacing: 20

        CustomTextHolder
        {
            height: 400 + aboutContainer.height/10
            width: 150 + aboutContainer.width/10
            aboutText: "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur."
            aboutImage: "qrc:/assets/ui/Assets/karol.png"
        }

        CustomTextHolder
        {
            height: 400 + aboutContainer.height/10
            width: 150 + aboutContainer.width/10
            aboutText: "<b>FlavourCraft</b>-<br> to projekt stworzony na potrzeby zaliczenia przedmiotu: Programowanie obiektowe w C++. Projekt powstawał przy wykorzystania środowiska Qt Creator w wersji open-source. Kod aplikacji jest dostępny na <a href=\"https://github.com/Nitjsefn/flavour-craft-cpp\">GitHub'ie</a>."
                     //"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur."
            aboutImage: "qrc:/assets/ui/Assets/OIG.png"
            eLink: "https://github.com/Nitjsefn/flavour-craft-cpp"

        }

        CustomTextHolder
        {
            height: 400 + aboutContainer.height/10
            width: 150 + aboutContainer.width/10
            aboutImage: "qrc:/assets/ui/Assets/jakub.png"
            aboutText: "<b>DragoonXVIII</b>-<br> Student I roku informatyki, programuje od gimnazjum. Zakochał się w Qt na początku liceum, ale nie pogardzi też okazją do stworzenia śmiesznego bota na discord'a.<br><a href=\"https://github.com/DragoonXVIII\">GitHub</a>"
            eLink: "https://github.com/DragoonXVIII"
        }
    }

    Text
    {
        text: 'App logo was created using <a href=\"https://www.bing.com/search?toWww=1&redig=AABBDA197AAE4F3E8EB33F33F787D691&q=Bing+AI&showconv=1\">Bing Chat</a>'
        color: "#F2E5D7"
        font.family: "Consolas"
        font.italic: true
        onLinkActivated: Qt.openUrlExternally("https://www.bing.com/search?toWww=1&redig=AABBDA197AAE4F3E8EB33F33F787D691&q=Bing+AI&showconv=1")
        y: parent.height - height - 10
        x: 20
    }
}

// creditsy: ja, krl, tt,
