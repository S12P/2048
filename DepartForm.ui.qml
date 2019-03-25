import QtQuick 2.4

Item {
    width: largeur
    height: hauteur

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
            anchors.fill: parent
            onClicked: stackView.push("HomeForm.ui.qml")
        }
    }
}
