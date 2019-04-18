import QtQuick 2.9
import QtQuick.Controls 2.3
import QtGraphicalEffects 1.0

ApplicationWindow {
    id: window
    visible: true
    width: 1000
    height: 800
    title: qsTr("2048")
    color: "#FFDF82"
    onActiveFocusItemChanged: console.log(activeFocusItem)

    property int numberOfRows: 4
    property int carre: 120
    property int largeur: width
    property int hauteur: height
    property var numberOfScore: game.score
    property var numberOfBest: game.best
    property var l0: (game.list[0] === 0) ? "" : game.list[0]
    property var l1: (game.list[1] === 0) ? "" : game.list[1]
    property var l2: (game.list[2] === 0) ? "" : game.list[2]
    property var l3: (game.list[3] === 0) ? "" : game.list[3]
    property var l4: (game.list[4] === 0) ? "" : game.list[4]
    property var l5: (game.list[5] === 0) ? "" : game.list[5]
    property var l6: (game.list[6] === 0) ? "" : game.list[6]
    property var l7: (game.list[7] === 0) ? "" : game.list[7]
    property var l8: (game.list[8] === 0) ? "" : game.list[8]
    property var l9: (game.list[9] === 0) ? "" : game.list[9]
    property var l10: (game.list[10] === 0) ? "" : game.list[10]
    property var l11: (game.list[11] === 0) ? "" : game.list[11]
    property var l12: (game.list[12] === 0) ? "" : game.list[12]
    property var l13: (game.list[13] === 0) ? "" : game.list[13]
    property var l14: (game.list[14] === 0) ? "" : game.list[14]
    property var l15: (game.list[15] === 0) ? "" : game.list[15]
    property bool end: game.end
    property bool win: game.win_end
    property bool endd: (end || win)
    property real opac: 1-(game.end||game.win_end)/2



    property var cl0: game.lcolor[0]
    property var cl1: game.lcolor[1]
    property var cl2: game.lcolor[2]
    property var cl3: game.lcolor[3]
    property var cl4: game.lcolor[4]
    property var cl5: game.lcolor[5]
    property var cl6: game.lcolor[6]
    property var cl7: game.lcolor[7]
    property var cl8: game.lcolor[8]
    property var cl9: game.lcolor[9]
    property var cl10: game.lcolor[10]
    property var cl11: game.lcolor[11]
    property var cl12: game.lcolor[12]
    property var cl13: game.lcolor[13]
    property var cl14: game.lcolor[14]
    property var cl15: game.lcolor[15]

    property var begin: game.begin






    menuBar: MenuBar {
        Menu {
            title: qsTr("&Fichier")
            MenuItem {
                text: qsTr("Nouveau")
                onClicked:game.newgame();
            }
            MenuItem {
                text: qsTr("Sauvegarder")
                onClicked:game.save();
            }
            MenuSeparator { }
            MenuItem {
                text: qsTr("Quitter")
                onTriggered: Qt.quit();
            }
        }
        Menu {
            title: qsTr("&Aide")
            MenuItem {
                text: qsTr("A propos")
                // onTriggered:
            }
        }
    }


    StackView {
        id: stackView
        initialItem: "Game.qml"
        anchors.fill: parent
        focus: true


        Keys.onPressed: {
            switch (event.key) {
            case Qt.Key_Right:
                console.log("KeyRight pressed");
                game.right_mvt();
                break;
            case Qt.Key_Left:
                console.log("KeyLeft pressed");
                game.left_mvt();
                break;
            case Qt.Key_Up:
                console.log("KeyUp pressed");
                game.top_mvt();
                break;
            case Qt.Key_Down:
                console.log("KeyDown pressed");
                game.low_mvt();
                break;
            }
        }
    }

}
