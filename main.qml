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
    property int largeur: width
    property int hauteur: height
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


    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: largeur
        height: hauteur
        color: "#a9a9a9"

        Text {
            id: element1
            x: 14
            y: 42
            width: 204
            height: 83
            text: qsTr("2048")
            font.family: "Courier"
            font.pixelSize: 56
        }




        Rectangle {
            anchors.right: parent.right
            id: scoreBoard
            width: 180
            height: 150
            anchors.rightMargin: 38



            Rectangle{
                id: rectangle1
                x: 0
                y: 0
                width: 85
                height: 80
                Text{
                    x: 22
                    y: 0
                    width: 41
                    height: 22
                    text: qsTr("Score")
                }
                Text {
                    id: score
                    x: 14
                    y: 20
                    width: 58
                    height: 52
                    text: numberOfScore
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.family: "Courier"
                    font.pixelSize: 40
                }

            }



            Rectangle{
                x: 95
                y: 0
                width: 85
                height: 80
                anchors.verticalCenter: rectangle1.verticalCenter
                anchors.right: parent.right
                anchors.bottom: rectangle1.bottom
                anchors.top: parent.top
                Text{
                    x: 27
                    y: 0
                    width: 31
                    height: 22
                    text: qsTr("Best")
                }
                Text {
                    id: best
                    x: 14
                    y: 20
                    width: 58
                    height: 52
                    text: numberOfBest
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.family: "Courier"
                    font.pixelSize: 40
                }
            }
            Button {
                id: button
                x: 40
                y: 91
                text: qsTr("New game")
                anchors.horizontalCenter: parent.horizontalCenter
                focusPolicy: Qt.TabFocus
            }
        }



        Rectangle {
            id: rectangle2
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            width: 5 + 5 + 10*(numberOfRows-1) + 70*numberOfRows
            height: 5 + 5 + 10*(numberOfRows-1) + 70*numberOfRows
            color: "black"

            Grid {
                x: 167
                y: 8
                anchors.horizontalCenter: rectangle2.horizontalCenter
                anchors.verticalCenter: rectangle2.verticalCenter
                rows: numberOfRows
                columns: numberOfRows
                spacing: 10

                Repeater { model: 24
                    Rectangle { width: 70; height: 70
                        color: "burlywood"

                        Text { text: "0"
                            font.pointSize: 30
                            anchors.centerIn: parent } }
                }
            }
        }
    }

}
