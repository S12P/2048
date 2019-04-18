import QtQuick 2.9
import QtQuick.Controls 2.3

Rectangle {
    id: rectangle
    x: 0
    y: 0
    width: largeur
    height: hauteur
    color: "#FFDF82"

    property alias b_newgame: buttongame

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
        width: 220
        height: 115
        anchors.rightMargin: 38

        Rectangle {
            id: rectangle1
            x: 0
            y: 0
            width: 110
            height: 80
            Text {
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
                font.pixelSize: 30
            }
        }

        Rectangle {
            x: 110
            y: 0
            width: 110
            height: 80
            anchors.verticalCenter: rectangle1.verticalCenter
            anchors.right: parent.right
            Text {
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
                font.pixelSize: 30
            }
        }
        Button {
            id: buttongame
            x: 40
            y: 65
            text: qsTr("New game")
            anchors.horizontalCenter: parent.horizontalCenter
            focusPolicy: Qt.TabFocus
            onClicked: game.newgame()
        }
    }

    Rectangle {
        id: rectangle2
        opacity: opac
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        width: 5 + 5 + 10 * (numberOfRows - 1) + carre * numberOfRows
        height: 5 + 5 + 10 * (numberOfRows - 1) + carre * numberOfRows
        color: "black"

        Grid {
            x: 167
            y: 8
            anchors.horizontalCenter: rectangle2.horizontalCenter
            anchors.verticalCenter: rectangle2.verticalCenter
            rows: numberOfRows
            columns: numberOfRows
            spacing: 10

            Rectangle {
                width: carre
                height: carre
                color: cl0

                Text {
                    text: l0
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: carre
                height: carre
                color: cl1

                Text {
                    text: l1
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: carre
                height: carre
                color: cl2

                Text {
                    text: l2
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: carre
                height: carre
                color: cl3

                Text {
                    text: l3
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: carre
                height: carre
                color: cl4

                Text {
                    text: l4
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: carre
                height: carre
                color: cl5

                Text {
                    text: l5
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: carre
                height: carre
                color: cl6

                Text {
                    text: l6
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: carre
                height: carre
                color: cl7

                Text {
                    text: l7
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: carre
                height: carre
                color: cl8

                Text {
                    text: l8
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: carre
                height: carre
                color: cl9

                Text {
                    text: l9
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: carre
                height: carre
                color: cl10

                Text {
                    text: l10
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: carre
                height: carre
                color: cl11

                Text {
                    text: l11
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: carre
                height: carre
                color: cl12

                Text {
                    text: l12
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: carre
                height: carre
                color: cl13

                Text {
                    text: l13
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: carre
                height: carre
                color: cl14

                Text {
                    text: l14
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: carre
                height: carre
                color: cl15

                Text {
                    text: l15
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
        }
    }

    Rectangle {
        visible: end
        id: rectangle2end
        width: 200
        height: 230
        color: "transparent"
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        Text {
            text: "Tu as perdu"
            font.pointSize: 30
            anchors.centerIn: parent
        }
    }

    Rectangle {
        visible: win
        id: rectangle2win
        width: 200
        height: 230
        color: "transparent"
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        Text {
            id:texte
            text: "Tu as gagné"
            font.pointSize: 30
            anchors.centerIn: parent
        }
        Button {
            text: "Continuer ?"
            anchors.top: texte.bottom
            anchors.horizontalCenter: texte.horizontalCenter
            onPressed: opac = 1;
            onClicked: win=false;
        }
    }
}



