import QtQuick 2.7
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
            text: device.percent + qsTr(" %")
            Layout.minimumWidth: 30
            clip: true
            leftPadding: 10
        }
        Label {
            text: qsTr("/")
            clip: true
        }
        Label {
            id: timeLabel
            text: Math.floor(device.time / 60) + qsTr(
                      " h ") + device.time % 60 + qsTr(" m")
            Layout.minimumWidth: 70
            clip: true
        }
        Label {
            id: statusLabel
            text: device.status
            Layout.minimumWidth: 70
            clip: true
        }
    }
}
