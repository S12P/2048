import QtQuick 2.9
import QtQuick.Controls 2.3
//import MyControls 3.14

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 800
    title: qsTr("2048")
    color: "#a9a9a9"

    property int numberOfRows: 4
    property int largeur: width
    property int hauteur: height
    property var numberOfScore: game.score // a changer
    property var numberOfBest: game.best // a changer
    property var list: game.list


    menuBar: MenuBar {
        Menu {
            title: qsTr("&Fichier")
            MenuItem {
                text: qsTr("Nouveau")
                onClicked:game.newgame();
            }
            MenuItem {
                text: qsTr("Sauvegarder")
                onClicked:game.save();
            }
            MenuSeparator { }
            MenuItem {
                text: qsTr("Quitter")
                onTriggered: Qt.quit();
            }
        }
        Menu {
            title: qsTr("&Aide")
            MenuItem {
                text: qsTr("A propos")
                // onTriggered:
            }
        }
    }


    StackView {
        id: stackView
        initialItem: "HomeForm.ui.qml"
        anchors.fill: parent
    }

}
