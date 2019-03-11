import QtQuick 2.9
import QtQuick.Controls 2.3

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("2048")
    /*
    header: ToolBar {
        contentHeight: toolButton.implicitHeight

        ToolButton {
            id: toolButton
            text: stackView.depth > 1 ? "\u25C0" : "\u2630"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            onClicked: {
                if (stackView.depth > 1) {
                    stackView.pop()
                } else {
                    drawer.open()
                }
            }
        }

        Label {
            text: stackView.currentItem.title
            anchors.centerIn: parent
        }


    }*/

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

    Drawer {
        id: drawer
        width: window.width * 0.66
        height: window.height

        Column {
            anchors.fill: parent

            ItemDelegate {
                text: qsTr("Page 1")
                width: parent.width
                onClicked: {
                    stackView.push("Page1Form.ui.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Page 2")
                width: parent.width
                onClicked: {
                    stackView.push("Page2Form.ui.qml")
                    drawer.close()
                }
            }
        }
    }

    StackView {
        id: stackView
        initialItem: "HomeForm.ui.qml"
        anchors.fill: parent
    }

    footer: TabBar {

    }
}
