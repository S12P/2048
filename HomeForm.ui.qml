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
            //onClicked:game.newgame();
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

            Rectangle { width: 70; height: 70
                color: "burlywood"

                Text { text: l0
                    font.pointSize: 30
                    anchors.centerIn: parent }
            }
            Rectangle { width: 70; height: 70
                color: "burlywood"

                Text { text: l1
                    font.pointSize: 30
                    anchors.centerIn: parent }
            }
            Rectangle { width: 70; height: 70
                color: "burlywood"

                Text { text: l2
                    font.pointSize: 30
                    anchors.centerIn: parent }
            }
            Rectangle { width: 70; height: 70
                color: "burlywood"

                Text { text: l3
                    font.pointSize: 30
                    anchors.centerIn: parent }
            }
            Rectangle { width: 70; height: 70
                color: "burlywood"

                Text { text: l4
                    font.pointSize: 30
                    anchors.centerIn: parent }
            }
            Rectangle { width: 70; height: 70
                color: "burlywood"

                Text { text: l5
                    font.pointSize: 30
                    anchors.centerIn: parent }
            }
            Rectangle { width: 70; height: 70
                color: "burlywood"

                Text { text: l6
                    font.pointSize: 30
                    anchors.centerIn: parent }
            }
            Rectangle { width: 70; height: 70
                color: "burlywood"

                Text { text: l7
                    font.pointSize: 30
                    anchors.centerIn: parent }
            }
            Rectangle { width: 70; height: 70
                color: "burlywood"

                Text { text: l8
                    font.pointSize: 30
                    anchors.centerIn: parent }
            }
            Rectangle { width: 70; height: 70
                color: "burlywood"

                Text { text: l9
                    font.pointSize: 30
                    anchors.centerIn: parent }
            }
            Rectangle { width: 70; height: 70
                color: "burlywood"

                Text { text: l10
                    font.pointSize: 30
                    anchors.centerIn: parent }
            }
            Rectangle { width: 70; height: 70
                color: "burlywood"

                Text { text: l11
                    font.pointSize: 30
                    anchors.centerIn: parent }
            }
            Rectangle { width: 70; height: 70
                color: "burlywood"

                Text { text: l12
                    font.pointSize: 30
                    anchors.centerIn: parent }
            }
            Rectangle { width: 70; height: 70
                color: "burlywood"

                Text { text: l13
                    font.pointSize: 30
                    anchors.centerIn: parent }
            }
            Rectangle { width: 70; height: 70
                color: "burlywood"

                Text { text: l14
                    font.pointSize: 30
                    anchors.centerIn: parent }
            }
            Rectangle { width: 70; height: 70
                color: "burlywood"

                Text { text: l15
                    font.pointSize: 30
                    anchors.centerIn: parent }
            }
        }
    }
}
