import QtQuick 2.9
import QtQuick.Controls 2.3
import MyControls 3.14

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
    property var numberOfScore: game.give_score() // a changer
    property var numberOfBest: game.give_best() // a changer

    Game {id : game}

    menuBar: MenuBar {
        Menu {
            title: qsTr("&Fichier")
            MenuItem {
                text: qsTr("Nouveau")
                //onTriggered:
            }
            MenuItem {
                text: qsTr("Sauvegarder")
                //onTriggered:
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
