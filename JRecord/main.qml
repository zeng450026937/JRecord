import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

import com.nd.recordservice 1.0

ApplicationWindow {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("DJRecord")

    ColumnLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        anchors.top: parent.top

        TextField {
            id: usernameField
            placeholderText: qsTr("Text Field")
        }
        TextField {
            id: passwordField
            placeholderText: qsTr("Text Field")
        }

        Button {
            id: loginButton
            text: qsTr("Login")
            onClicked: account.logIn()
        }

        Text {
            id: errorString
            text: account.errorString
        }
        Text {
            id: statusLabel
        }

    }

    Account{
        id: account
        username: usernameField.text
        password: passwordField.text
        onStatusChanged: {
            if(status === Account.Login){
                statusLabel.text = qsTr("Login successed!")
            }
        }
    }

}
