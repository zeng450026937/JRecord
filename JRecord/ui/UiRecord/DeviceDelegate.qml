import QtQuick 2.4
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import com.nd.recordservice 1.0

CheckDelegate {
    id: delegate
    clip: true

    checked: device.lock
    onClicked: {
        device.lock = !device.lock
    }
    Component.onCompleted: {
        delegate.indicator.anchors.left = delegate.left
        delegate.indicator.anchors.leftMargin = 10
    }

    contentItem: RowLayout {
        spacing: 5
        anchors.left: delegate.indicator.right
        anchors.right: delegate.right
        anchors.leftMargin: 10
        anchors.rightMargin: 10
        Label {
            id: nameLabel
            //text: device.name
            text: device.owner.userName
            clip: true
        }
        Label {
            clip: true
            Layout.fillWidth: true
        }
        Label {
            id: vadLabel
            text: device.vad
            width: implicitWidth
            clip: true
            leftPadding: 10
            rightPadding: 10
        }
        Label {
            id: percentLabel
            text: qsTr(device.percent + " %")
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
            text: qsTr(Math.floor(
                           device.time / 60) + " h " + device.time % 60 + " m")
            width: implicitWidth
            clip: true
            rightPadding: 10
        }
        Label {
            id: statusLabel
            text: device.status
            width: 80
            clip: true
            leftPadding: 10
            rightPadding: 10
        }
    }
}
