import QtQuick 2.7
import QtQuick.Controls 2.0
import com.nd.recordservice 1.0

UiLoginForm {
    id: root

    Connections {
        target: inputField.loginButton
        onClicked: {
            console.log(client.username,client.password)
            client.signIn()
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
            }
            if(status == Account.Logouting){
                console.log("Logouting")
            }
            if(status == Account.Logout){
                console.log("Logout")
            }
            if(status == Account.Error){
                console.log("Error")
                popup.open()
            }
        }
    }

    Popup {
        id: popup
        modal: true
        focus: true
        x: (parent.width-implicitWidth) / 2
        y: (parent.height-implicitHeight) / 2
        Text {
            id: message
            text: client.errorString
        }
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent | Popup.CloseOnPressOutside | Popup.CloseOnReleaseOutside
    }
}
