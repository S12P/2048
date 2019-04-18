import QtQuick 2.9
import QtQuick.Controls 2.3

DepartForm {

    button1{
        MouseArea {
            id: mouse1
            anchors.fill: parent
            onClicked: stackView.push("HomeForm.ui.qml")

        }

      }
}
