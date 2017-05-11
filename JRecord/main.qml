import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

import "./scenes"
import com.nd.recordservice 1.0

ApplicationWindow {
    id: root
    visible: true
    width: loginWindow.width
    height: loginWindow.height
    title: qsTr("JRecord")

    flags: Qt.FramelessWindowHint | Qt.Window

    LoginScene{
        id: loginWindow
    }
}
