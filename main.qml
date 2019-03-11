import QtQuick 2.9
import QtQuick.Controls 2.3

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 800
    title: qsTr("2048")
    color: "#a9a9a9"

    property int numberOfRows: 4
    property int largeur: 500
    property int hauteur: 700
    property var numberOfScore: 2 // a changer
    property var numberOfBest: 2 // a changer

    menuBar: MenuBar {
            Menu {
                title: qsTr("&Fichier")
                Action { text: qsTr("&Nouveau...") }
                Action { text: qsTr("&Sauvegarder") }
                Action { text: qsTr("Sauvegarder sous...") }
                MenuSeparator { }
                Action { text: qsTr("&Quitter") }
            }
            Menu {
                title: qsTr("&Aide")
                Action { text: qsTr("&A propos") }
            }
        }


    StackView {
        id: stackView
        initialItem: "HomeForm.ui.qml"
        anchors.fill: parent
    }

}
