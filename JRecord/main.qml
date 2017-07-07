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

    Loader {
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
            if (status == NdAccount.Logining) {
                console.log("Logining")
            }
            if (status == NdAccount.Login) {
                console.log("Login")
            }
            if (status == NdAccount.Logouting) {
                console.log("Logouting")
            }
            if (status == NdAccount.Logout) {
                console.log("Logout")
            }
            if (status == NdAccount.Error) {
                console.log("Error" + NdAccount.errorString)
            }
        }
        onActiveChanged: {
            ServiceBase.active = active
        }
    }

    Connections {
        target: ServiceBase
        onStatusChanged: {
            if (status == ServiceBase.Connecting) {
                console.log(qsTr("Connecting"))
            }
            if (status == ServiceBase.Open) {
                console.log(qsTr("Open"))
            }
            if (status == ServiceBase.Closing) {
                console.log(qsTr("Closing"))
            }
            if (status == ServiceBase.Closed) {
                console.log(qsTr("Closed"))
            }
            if (status == ServiceBase.Error) {
                console.log(qsTr("Error:") + ServiceBase.errorString)
            }
        }
        onActiveChanged: {
            if (active) {
                sceneLoader.state = "HOME"
                var dm = ServiceBase.deviceManager()
                dm.getDeviceList()

                var cm = ServiceBase.conferenceManager()
                cm.refresh()
            } else {
                sceneLoader.state = "LOGIN"
            }
            NdAccount.active = active
        }
    }

    Device {
        id: pc
        owner: User {
            id: user
            userId: "311715"
            userName: NdAccount.userName
            userGroup: qsTr("ND")
        }
        type: qsTr("PC")
    }

    Component.onCompleted: {
        sceneLoader.state = "LOGIN"

        ServiceBase.url = qsTr("ws://192.168.85.31:9007")
        ServiceBase.device = pc
    }
}
