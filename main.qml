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
    property var l0: game.list[0]
    property var l1: game.list[1]
    property var l2: game.list[2]
    property var l3: game.list[3]
    property var l4: game.list[4]
    property var l5: game.list[5]
    property var l6: game.list[6]
    property var l7: game.list[7]
    property var l8: game.list[8]
    property var l9: game.list[9]
    property var l10: game.list[10]
    property var l11: game.list[11]
    property var l12: game.list[12]
    property var l13: game.list[13]
    property var l14: game.list[14]
    property var l15: game.list[15]


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
