import QtQuick 2.9
import QtQuick.Controls 2.3

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

        Rectangle {
            id: rectangle1
            x: 0
            y: 0
            width: 85
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
                font.pixelSize: 40
            }
        }

        Rectangle {
            x: 95
            y: 0
            width: 85
            height: 80
            anchors.verticalCenter: rectangle1.verticalCenter
            anchors.right: parent.right
            anchors.bottom: rectangle1.bottom
            anchors.top: parent.top
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
        visible: !endd
        id: rectangle2
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        width: 5 + 5 + 10 * (numberOfRows - 1) + 70 * numberOfRows
        height: 5 + 5 + 10 * (numberOfRows - 1) + 70 * numberOfRows
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
                width: 70
                height: 70
                color: cl0

                Text {
                    text: l0
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: 70
                height: 70
                color: cl1

                Text {
                    text: l1
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: 70
                height: 70
                color: cl2

                Text {
                    text: l2
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: 70
                height: 70
                color: cl3

                Text {
                    text: l3
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: 70
                height: 70
                color: cl4

                Text {
                    text: l4
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: 70
                height: 70
                color: cl5

                Text {
                    text: l5
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: 70
                height: 70
                color: cl6

                Text {
                    text: l6
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: 70
                height: 70
                color: cl7

                Text {
                    text: l7
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: 70
                height: 70
                color: cl8

                Text {
                    text: l8
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: 70
                height: 70
                color: cl9

                Text {
                    text: l9
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: 70
                height: 70
                color: cl10

                Text {
                    text: l10
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: 70
                height: 70
                color: cl11

                Text {
                    text: l11
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: 70
                height: 70
                color: cl12

                Text {
                    text: l12
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: 70
                height: 70
                color: cl13

                Text {
                    text: l13
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: 70
                height: 70
                color: cl14

                Text {
                    text: l14
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Rectangle {
                width: 70
                height: 70
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
        color: "#ffffff"
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
        color: "#ffffff"
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        Text {
            text: "Tu as gagné"
            font.pointSize: 30
            anchors.centerIn: parent
        }
    }
}





/*##^## Designer {
    D{i:1;invisible:true}D{i:4;invisible:true}D{i:5;invisible:true}D{i:3;invisible:true}
D{i:7;invisible:true}D{i:8;invisible:true}D{i:6;invisible:true}D{i:9;invisible:true}
D{i:2;invisible:true}D{i:13;invisible:true}D{i:12;invisible:true}D{i:15;invisible:true}
D{i:14;invisible:true}D{i:17;invisible:true}D{i:16;invisible:true}D{i:19;invisible:true}
D{i:18;invisible:true}D{i:21;invisible:true}D{i:20;invisible:true}D{i:23;invisible:true}
D{i:22;invisible:true}D{i:25;invisible:true}D{i:24;invisible:true}D{i:27;invisible:true}
D{i:26;invisible:true}D{i:29;invisible:true}D{i:28;invisible:true}D{i:31;invisible:true}
D{i:30;invisible:true}D{i:33;invisible:true}D{i:32;invisible:true}D{i:35;invisible:true}
D{i:34;invisible:true}D{i:37;invisible:true}D{i:36;invisible:true}D{i:39;invisible:true}
D{i:38;invisible:true}D{i:41;invisible:true}D{i:40;invisible:true}D{i:43;invisible:true}
D{i:42;invisible:true}D{i:11;invisible:true}D{i:10;invisible:true}
}
 ##^##*/
