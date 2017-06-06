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
        target: NdAccount
        onStatusChanged: {
            if(status == NdAccount.Logining){
                console.log("Logining")
            }
            if(status == NdAccount.Login){
                console.log("Login")
                sceneLoader.state = "HOME"
            }
            if(status == NdAccount.Logouting){
                console.log("Logouting")
            }
            if(status == NdAccount.Logout){
                console.log("Logout")
            }
            if(status == NdAccount.Error){
                console.log("Error")
            }
        }
    }

    Component.onCompleted: {
        sceneLoader.state = "LOGIN"
    }
}
