import QtQuick 2.7
import QtQuick.Controls 2.0
import com.nd.recordservice 1.0

ApplicationWindow {
    id: root
    visible: true
    title: qsTr("JRecord")
    width: 450
    height: 350

    flags: Qt.FramelessWindowHint | Qt.Window

    Loader{
        id: sceneLoader
        anchors.fill: parent
        focus: true

        states: [
            State {
                name: "LOGIN"
                PropertyChanges {
                    target: sceneLoader
                    source: "./ui/UiLogin/UiLogin.qml"
                }
                PropertyChanges {
                    target: root
                    visible: true
                }
            },
            State {
                name: "HOME"
                PropertyChanges {
                    target: sceneLoader
                    source: "./ui/UiHome/UiHome.qml"
                }
                PropertyChanges {
                    target: root
                    visible: false
                }
            }
        ]
    }

    Connections {
        target: Account
        onStatusChanged: {
            if(status == Account.Logining){
                console.log("Logining")
            }
            if(status == Account.Login){
                console.log("Login")
                sceneLoader.state = "HOME"
            }
            if(status == Account.Logouting){
                console.log("Logouting")
            }
            if(status == Account.Logout){
                console.log("Logout")
            }
            if(status == Account.Error){
                console.log("Error")
            }
        }
    }

    Component.onCompleted: {
        sceneLoader.state = "LOGIN"
    }
}
