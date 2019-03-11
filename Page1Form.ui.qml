import QtQuick 2.9
import QtQuick.Controls 2.2

Page {
    width: 600
    height: 400
    font.capitalization: Font.MixedCase
    padding: 0

    title: qsTr("Page 1")

    Label {
        text: qsTr("Made by SP")
        anchors.verticalCenterOffset: 187
        anchors.horizontalCenterOffset: -8
        anchors.centerIn: parent
    }

    Frame {
        id: frame
        x: 169
        y: 150
        width: 200
        height: 200
    }
}
