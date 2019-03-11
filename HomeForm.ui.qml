import QtQuick 2.9
import QtQuick.Controls 2.3

Page {
    id: page
    width: 500
    height: 700
    transformOrigin: Item.Center

    title: qsTr("2048")


    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 500
        height: 700
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

        Button {
            id: button
            x: 322
            y: 98
            text: qsTr("New game")
        }


        Row {
            anchors.right: parent.right
            spacing: 5
            id: scoreBoard
            x: 282
            y: 12
            width: 180
            height: 80
            anchors.rightMargin: 38

            Rectangle{
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
                x: 85
                y: 0
                width: 85
                height: 80
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
        }



        Rectangle {
            x: 50
            y: 239
            width: 5 + 5 + 10*(numberOfRows-1) + 70*numberOfRows; height: 5 + 5 + 10*(numberOfRows-1) + 70*numberOfRows; color: "black"

            Grid {
                x: 5; y: 5
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
}
