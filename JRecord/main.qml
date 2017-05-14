import QtQuick 2.7
import QtQuick.Controls 2.0

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
        target: sceneLoader.item
        onLoginSuccessed: {
            console.log("login successed")
            sceneLoader.state = "HOME"
        }
    }

    Component.onCompleted: {
        sceneLoader.state = "LOGIN"
    }
}
