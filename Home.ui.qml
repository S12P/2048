import QtQuick 2.9
import QtQuick.Controls 2.2

Page {
    width: 600
    height: 400
    font.capitalization: Font.MixedCase
    padding: 0

    title: qsTr("Page 1")

    TextInput {
        id: textInput
        x: 119
        y: 41
        width: 147
        height: 41
        text: qsTr("2048")
        font.family: "Tahoma"
        renderType: Text.NativeRendering
        scale: 1
        font.pixelSize: 36
    }
}
