import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import "FlatSurface"

Page {
    width: 450
    height: 350
    padding: 0
    property alias loginButton: inputField.loginButton
    property alias username: inputField.username
    property alias password: inputField.password

    ColumnLayout {
        id: columnLayout
        spacing: 0
        anchors.fill: parent

        Item {
            id: name
            Layout.preferredHeight: parent.height * 5 / 9
            Layout.fillWidth: true

            FlatSurface {
                id: flatSurface
                anchors.fill: parent

                Text {
                    id: logo
                    anchors.centerIn: parent
                    text: qsTr("JRecord")
                    color: "white"
                    font.bold : true
                    font.pointSize: 25
                }
            }
            ToolBar {
                anchors.top: flatSurface.top
                anchors.right: flatSurface.right
                width: implicitWidth
                height: implicitHeight

                background: Rectangle {
                    anchors.fill: parent
                    color: "transparent"
                }
                RowLayout {
                    anchors.fill: parent
                    spacing: 0

                    ToolButton{
                        text: qsTr("_")
                        activeFocusOnTab: false
                    }
                    ToolButton{
                        text: qsTr("x")
                        activeFocusOnTab: false
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
