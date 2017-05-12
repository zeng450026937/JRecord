import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import "FlatSurface"

Page {
    width: 450
    height: 350
    padding: 0
    property alias logo: logo
    property alias inputField: inputField
    property alias toolBar: toolBar

    ColumnLayout {
        id: columnLayout
        spacing: 0
        anchors.fill: parent

        Item {
            Layout.preferredHeight: parent.height * 5 / 9
            Layout.fillWidth: true

            FlatSurface {
                id: flatSurface
                anchors.fill: parent

                Text {
                    id: logo
                    anchors.centerIn: parent
                    text: qsTr("JRecord")
                    font.family: "Verdana"
                    color: "white"
                    font.bold: false
                    font.pointSize: 25
                    clip: true
                }
            }
            ToolBar {
                id: toolBar
                anchors.top: flatSurface.top
                anchors.right: flatSurface.right
                width: implicitWidth
                height: implicitHeight
                clip: true

                background: Rectangle {
                    anchors.fill: parent
                    color: "transparent"
                }
                RowLayout {
                    anchors.fill: parent
                    spacing: 0

                    ToolButton {
                        text: qsTr("_")
                        font.bold: true
                        activeFocusOnTab: false
                        focusPolicy: Qt.NoFocus
                    }
                    ToolButton {
                        text: qsTr("x")
                        font.bold: true
                        activeFocusOnTab: false
                        focusPolicy: Qt.NoFocus
                    }
                }
            }
        }

        Pane {
            id: pane
            clip: true
            padding: 0
            Layout.fillHeight: true
            Layout.fillWidth: true

            InputField {
                id: inputField
                anchors.fill: parent
                focus: true
            }
        }
    }
}
