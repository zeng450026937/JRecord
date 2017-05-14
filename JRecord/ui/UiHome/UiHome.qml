import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: root
    width: 500
    height: 680
    visible: true

    flags: Qt.FramelessWindowHint | Qt.Window

    Rectangle {
        color: Qt.rgba(1.0,0.7,0.5,1.0)
        anchors.fill: parent
    }

    Behavior on width {

        NumberAnimation {
            duration: 600
            easing.type: Easing.OutCirc
        }
    }
    Component.onCompleted: {
        root.width = 800
    }
}
