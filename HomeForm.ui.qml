import QtQuick 2.9
import QtQuick.Controls 2.2

Page {
    id: page
    width: 600
    height: 400

    title: qsTr("2048")

    Label {
        text: qsTr("You are on the home page.")
        anchors.centerIn: parent
    }

    //footer: qsTr("Made by SP")
}
