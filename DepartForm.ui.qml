import QtQuick 2.4

Item {
    width: 640
    height: 800

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
    }

    BorderImage {
        id: borderImage
        x: 229
        y: 449
        width: 182
        height: 64
        source: "bouton_jouez.png"
        Loader {
            id: pageLoader
        }
        MouseArea {
            anchors.fill: parent
            onClicked: stackView.push("HomeForm.ui.qml")
        }
    }
}









/*##^## Designer {
    D{i:1;anchors_height:152;anchors_width:165;anchors_x:118;anchors_y:124}
}
 ##^##*/
