import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0

FocusScope {
    id: inputField
    anchors.fill: parent
    focus: true
    Component.onCompleted: {
        inputField.forceActiveFocus()
    }

    property alias loginButton: loginButton

    property string username: usernameField.text
    property string password: passwordField.text

    ColumnLayout {
        id: layout
        anchors.centerIn: parent
        spacing: 0

        TextField {
            id: usernameField
            placeholderText: qsTr("Enter username")
            Layout.alignment: Qt.AlignCenter
            focus: true
        }
        TextField {
            id: passwordField
            placeholderText: qsTr("Enter password")
            Layout.alignment: Qt.AlignCenter
        }
        Button {
            id: loginButton
            padding: 0
            activeFocusOnTab: false
            Layout.alignment: Qt.AlignCenter
            text: qsTr("Sign In")
        }
    }
}
