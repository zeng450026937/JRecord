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

    header: ToolBar {
        visible: false
        width: implicitWidth
        anchors.right: parent.right
        Layout.alignment: Qt.AlignRight
        RowLayout {
            width: implicitWidth
            ToolButton{
                text: qsTr("_")
                width: implicitWidth
                focusPolicy: Qt.NoFocus
            }
            ToolButton{
                text: qsTr("x")
                width: implicitWidth
                focusPolicy: Qt.NoFocus
            }
        }
    }

    ColumnLayout {
        id: columnLayout
        spacing: 0
        anchors.fill: parent

        FlatSurface {
            id: flatSurface
            Layout.preferredHeight: parent.height * 5 / 9
            Layout.fillWidth: true

            Text {
                id: logo
                anchors.centerIn: parent
                text: qsTr("JRecord")
                color: "white"
                font.bold : true
                font.pointSize: 25
            }
        }

        Pane {
            id: pane
            Layout.fillHeight: true
            Layout.fillWidth: true
            focus: true

            InputField {
                id: inputField
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.fill: parent
                anchors.bottom: parent.bottom
            }
        }
    }
}
