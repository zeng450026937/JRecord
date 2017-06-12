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
                ServiceBase.active = true
            }
            if(status == NdAccount.Logouting){
                console.log("Logouting")
            }
            if(status == NdAccount.Logout){
                console.log("Logout")
                ServiceBase.active = false
            }
            if(status == NdAccount.Error){
                console.log("Error")
            }
        }
    }

    Connections {
        target: ServiceBase
        onStatusChanged: {
            if(status == ServiceBase.Connecting){
                console.log(qsTr("Connecting"))
            }
            if(status == ServiceBase.Open){
                console.log(qsTr("Open"))
                sceneLoader.state = "HOME"
            }
            if(status == ServiceBase.Closing){
                console.log(qsTr("Closing"))
            }
            if(status == ServiceBase.Closed){
                console.log(qsTr("Closed"))
                sceneLoader.state = "LOGIN"
            }
            if(status == ServiceBase.Error){
                console.log(qsTr("Error:")+ServiceBase.errorString)
            }
        }
    }

    Binding {
        target: ServiceBase
        property: "userId"
        value: NdAccount.userId
    }
    Binding {
        target: ServiceBase
        property: "userName"
        value: NdAccount.userName
    }

    Component.onCompleted: {
        sceneLoader.state = "LOGIN"

        ServiceBase.url = qsTr("ws://192.168.85.31:9008");
        ServiceBase.userGroup = qsTr("ND");
        ServiceBase.deviceType = qsTr("PC");
    }
}
