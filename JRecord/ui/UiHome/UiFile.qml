import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item {
    id: fileUi
    clip: true
    width: 600
    height: 400

    Pane {
        anchors.fill: parent
        padding: 0

        Rectangle {
            anchors.fill: parent
            color: Qt.rgba(Math.random(),Math.random(),Math.random(),1.0)
        }

        Label {
            anchors.centerIn: parent
            text: qsTr("fileUi")
        }

    }
}
