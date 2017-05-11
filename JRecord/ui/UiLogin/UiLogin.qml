import QtQuick 2.7
import com.nd.recordservice 1.0

UiLoginForm {
    id: root

    signal loginSuccessed
    signal loginFailed(string errorString)

    Connections {
        target: root.loginButton
        onClicked: {
            console.log(client.username,client.password)
            client.signIn()
        }
    }

    Account {
        id: client
        username: root.username
        password: root.password
        onStatusChanged: {
            if(status == Account.Logining)
                console.log("Logining")
            if(status == Account.Login){
                console.log("Login")
                loginSuccessed()
            }
            if(status == Account.Logouting)
                console.log("Logouting")
            if(status == Account.Logout)
                console.log("Logout")
            if(status == Account.Error){
                console.log("Error")
                loginFailed(client.errorString)
            }
        }
        onErrorStringChanged: {
            console.log(errorString)
        }
    }
}
