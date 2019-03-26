import QtQuick 2.9
import QtQuick.Controls 2.3

Item {
    property alias rectMouse: mouse1
    width: largeur
    height: hauteur
    id: depart

    AnimatedImage {
        id: animatedImage
        x: 244
        y: 280
        width: 160
        height: 152
        rotation: 0
        playing: false
        currentFrame: 0
        source: "2048.png"
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }

    property alias button1 : button1


    Button {
        id: button1
        x: -50
        y: 21
        spacing: -1

        Text {
            id: element
            x: 0
            y: 0
            width: 100
            height: 39
            text: qsTr("Jouez !")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            lineHeight: 0
            font.pixelSize: 21
        }
    }



    BorderImage {
        id: borderImage
        x: 229
        y: 449
        width: 182
        height: 64
        source: "bouton_jouez.png"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: animatedImage.bottom
        Loader {
            id: pageLoader
        }
        MouseArea {
            id: mouse1
            anchors.fill: parent

        }
    }
}
