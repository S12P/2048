import QtQuick 2.9
import QtQuick.Controls 2.3

//Page {
    //id: page
    //width: largeur/1
    //height: hauteur/1
    //transformOrigin: Item.Center

    //title: qsTr("2048")


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
            y : 300
            anchors.rightMargin: (largeur - width)/2
            width: 5 + 5 + 10*(numberOfRows-1) + 70*numberOfRows
            height: 5 + 5 + 10*(numberOfRows-1) + 70*numberOfRows
            color: "black"

            Grid {
                x: 167
                y: 8
                anchors.verticalCenterOffset: 79
                anchors.leftMargin: 177
                anchors.bottom: parent.bottom
                anchors.bottomMargin: -297
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                rows: numberOfRows; columns: numberOfRows; spacing: 10

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
//}
