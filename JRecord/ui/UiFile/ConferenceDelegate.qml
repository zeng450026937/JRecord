import QtQuick 2.4
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import com.nd.recordservice 1.0

ItemDelegate {
    id: delegate
    clip: true

    contentItem: RowLayout {
        spacing: 5
        anchors.left: delegate.left
        anchors.right: delegate.right
        anchors.leftMargin: 10
        anchors.rightMargin: 10
        Rectangle {
            id: icon
            clip: true
            color: "aqua"
            width: 80
            height: width
            anchors.horizontalCenter: parent.horizontalCenter
        }

        ColumnLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true

            RowLayout {
                anchors.left: parent.left
                anchors.right: parent.right
                Layout.fillHeight: true

                Label {
                    id: createTimeLabel
                    text: conference.createTime
                    clip: true
                }
                Label {
                    id: titleLabel
                    text: conference.title
                    clip: true
                }
            }
            RowLayout {
                anchors.left: parent.left
                anchors.right: parent.right
                Layout.fillHeight: true
                visible: conference.type == Conference.Personal ? true : false

                Label {
                    id: userNameLabel
                    text: conference.host.owner.userName
                    clip: true
                }
                Label {
                    id: userIdLabel
                    text: qsTr("(" + conference.host.owner.userName + ")")
                    clip: true
                }
            }
            RowLayout {
                anchors.left: parent.left
                anchors.right: parent.right
                Layout.fillHeight: true

                Label {
                    id: countLabel
                    text: qsTr(conference.count)
                    clip: true
                }
                Label {
                    id: tagLabel
                    text: conference.tag
                    clip: true
                }
                Label {
                    id: gpsLabel
                    text: conference.gps
                    clip: true
                }
            }
        }
    }
}
