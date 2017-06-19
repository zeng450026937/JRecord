import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import "FlatSurface"
import com.nd.recordservice 1.0

Item {
    id: loginUi
    width: 450
    height: 350
    clip: true

    Item {
        clip: true
        anchors.top: parent.top
        anchors.bottom: inputField.top
        anchors.left: parent.left
        anchors.right: parent.right

        FlatSurface {
            id: flatSurface
            clip: true
            anchors.fill: parent

            MouseArea {
                id: mouseArea
                property int xMouse
                property int yMouse
                property int deltaX
                property int deltaY
                anchors.fill: parent
                acceptedButtons: Qt.LeftButton
                onPressed: {
                    xMouse = mouse.x
                    yMouse = mouse.y
                }
                onPositionChanged: {
                    deltaX = mouse.x - xMouse
                    deltaY = mouse.y - yMouse
                    ApplicationWindow.window.setX(
                                ApplicationWindow.window.x + deltaX)
                    ApplicationWindow.window.setY(
                                ApplicationWindow.window.y + deltaY)
                }
            }
        }
        Label {
            id: logo
            anchors.centerIn: parent
            text: qsTr("JRecord")
            font.family: "Verdana"
            color: "white"
            font.bold: true
            font.pointSize: 25
            clip: true
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
                    clip: true
                    font.bold: true
                    activeFocusOnTab: false
                    focusPolicy: Qt.NoFocus
                    onClicked: ApplicationWindow.window.showMinimized()
                }
                ToolButton {
                    text: qsTr("x")
                    clip: true
                    font.bold: true
                    activeFocusOnTab: false
                    focusPolicy: Qt.NoFocus
                    onClicked: ApplicationWindow.window.close()
                }
            }
        }
    }

    Item {
        id: inputField
        clip: true
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        height: parent.height * 4 / 9

        property alias username: usernameField.text
        property alias password: passwordField.text

        property alias loginButton: loginButton

        FocusScope {
            id: inputScope
            anchors.fill: parent
            focus: true
            Component.onCompleted: {
                inputScope.forceActiveFocus()
            }

            ColumnLayout {
                anchors.centerIn: parent
                spacing: 0

                TextField {
                    id: usernameField
                    clip: true
                    text: inputField.username
                    placeholderText: qsTr("Enter username")
                    Layout.alignment: Qt.AlignCenter
                    selectByMouse: true
                    focus: true
                    onAccepted: passwordField.focus = true
                }
                TextField {
                    id: passwordField
                    clip: true
                    text: inputField.password
                    placeholderText: qsTr("Enter password")
                    Layout.alignment: Qt.AlignCenter
                    selectByMouse: true
                    echoMode: TextInput.Password
                    inputMethodHints: Qt.ImhHiddenText
                    onAccepted: loginButton.clicked()
                }

                Button {
                    id: loginButton
                    clip: true
                    padding: 0
                    activeFocusOnTab: false
                    focusPolicy: Qt.NoFocus
                    Layout.alignment: Qt.AlignCenter
                    Layout.fillWidth: true
                    text: qsTr("Sign In")

                    Connections {
                        onClicked: {
                            NdAccount.active = !NdAccount.active
                        }
                    }
                }
            }
        }
    }

    Binding {
        target: NdAccount
        property: "userId"
        value: inputField.username
    }
    Binding {
        target: NdAccount
        property: "password"
        value: inputField.password
    }

    Connections {
        target: NdAccount
        onStatusChanged: {
            if (status == NdAccount.Logining) {

            }
            if (status == NdAccount.Login) {

            }
            if (status == NdAccount.Logouting) {

            }
            if (status == NdAccount.Logout) {

            }
            if (status == NdAccount.Error) {
                popup.open()
            }
        }
    }

    Popup {
        id: popup
        clip: true
        modal: true
        focus: true
        width: parent.width
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent
                     | Popup.CloseOnPressOutside | Popup.CloseOnReleaseOutside

        Text {
            id: message
            anchors.fill: parent
            wrapMode: Text.Wrap
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: NdAccount.errorString
        }
    }
}
