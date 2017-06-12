import QtQuick 2.4
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import com.nd.recordservice 1.0

CheckDelegate {
    id: delegate
    clip: true

    property alias locked: userCheckBox.checked
    property alias userName: userCheckBox.text
    property alias vad: vadLabel.text
    property alias percent: percentLabel.text
    property alias time: timeLabel.text
    property alias status: statusLabel.text

    property var device: Device{
        service: ServiceBase
        uuid: deviceUuid
    }

    contentItem: RowLayout {
        spacing: 5
        anchors.fill: parent
        CheckBox {
            id: userCheckBox
            text: qsTr("user")
            clip: true
        }
        Label {
            Layout.fillWidth: true
        }
        Label {
            id: vadLabel
            text: qsTr("vad")
            width: implicitWidth
            clip: true
            leftPadding: 10
            rightPadding: 10
        }
        Label {
            id: percentLabel
            text: qsTr("percent")
            width: implicitWidth
            clip: true
            leftPadding: 10
        }
        Label {
            text: qsTr("/")
            clip: true
        }
        Label {
            id: timeLabel
            text: qsTr("time")
            width: implicitWidth
            clip: true
            rightPadding: 10
        }
        Label {
            id: statusLabel
            text: qsTr("status")
            width: implicitWidth
            clip: true
            leftPadding: 10
            rightPadding: 10
        }
    }
}
