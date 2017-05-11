import QtQuick 2.7
import QtQuick.Controls 2.0

ApplicationWindow {
    id: root
    visible: true
    width: sceneLoader.width
    height: sceneLoader.height
    title: qsTr("JRecord")

    flags: Qt.FramelessWindowHint | Qt.Window

    Loader{
        id: sceneLoader
        source: "./ui/UiLogin/UiLogin.qml"
    }

}
