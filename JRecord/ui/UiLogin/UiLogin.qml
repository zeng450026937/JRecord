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

    signal loginSuccessed()

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
        }
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
                    onClicked: ApplicationWindow.window.showMinimized()
                }
                ToolButton {
                    text: qsTr("x")
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

        property string username: usernameField.text
        property string password: passwordField.text

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
                    text: inputField.username
                    placeholderText: qsTr("Enter username")
                    Layout.alignment: Qt.AlignCenter
                    selectByMouse: true
                    focus: true
                    onAccepted: passwordField.focus = true
                }
                TextField {
                    id: passwordField
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
                    padding: 0
                    activeFocusOnTab: false
                    focusPolicy: Qt.NoFocus
                    Layout.alignment: Qt.AlignCenter
                    Layout.fillWidth: true
                    text: qsTr("Sign In")

                    Connections {
                        onClicked: {
                            //client.signIn()
                            loginSuccessed()
                        }
                    }
                }
            }
        }

    }


    Account {
        id: client
        username: inputField.username
        password: inputField.password
        onStatusChanged: {
            if(status == Account.Logining){
                console.log("Logining")
            }
            if(status == Account.Login){
                console.log("Login")
                loginSuccessed()
            }
            if(status == Account.Logouting){
                console.log("Logouting")
            }
            if(status == Account.Logout){
                console.log("Logout")
            }
            if(status == Account.Error){
                console.log("Error",client.errorString)
                popup.open()
            }
        }
    }

    Popup {
        id: popup
        modal: true
        focus: true
        width: parent.width
        closePolicy: Popup.CloseOnEscape |
                     Popup.CloseOnPressOutsideParent |
                     Popup.CloseOnPressOutside |
                     Popup.CloseOnReleaseOutside

        Text {
            id: message
            anchors.fill: parent
            wrapMode: Text.Wrap
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: client.errorString
        }
    }
}
