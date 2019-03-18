import QtQuick 2.4

Item {
    width: 400
    height: 400

    AnimatedImage {
        id: animatedImage
        x: 118
        y: 124
        width: 165
        height: 152
        rotation: 0
        playing: false
        currentFrame: 0
        source: "2048.png"
    }

    BorderImage {
        id: borderImage
        x: 110
        y: 299
        width: 182
        height: 64
        source: "bouton_jouez.png"
        Loader {id:pageLoader}
        MouseArea{
            anchors.fill: parent
            onClicked: pageLoader.source = "main.qml"
        }
    }
}
