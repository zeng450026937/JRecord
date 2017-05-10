import QtQuick 2.7
import QtQuick.Controls 2.0
import "./FlatSurfaceShader"

Item {
    id: root
    width: 430
    height: 330

    Pane {
        anchors.fill: parent
        padding: 0

        FlatSurfaceShader {
            id: surface
            anchors.top: parent.top
            width: parent.width
            height: 180
        }

        Text {
            id: title
            anchors.centerIn: surface
            text: qsTr("JRecord")
            color: "white"
            font.bold : true
            font.pointSize: 25
        }
    }
}
