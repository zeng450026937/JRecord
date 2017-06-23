import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQml 2.2
import com.nd.recordservice 1.0

ItemDelegate {
    width: 400
    height: 100

    RowLayout {
        id: rowLayout
        clip: true
        anchors.rightMargin: 10
        anchors.leftMargin: 10
        anchors.bottomMargin: 10
        anchors.topMargin: 10
        anchors.fill: parent

        Rectangle {
            id: rectangle
            clip: true
            color: "lightgray"
            width: 60
            height: width
        }
        ColumnLayout {
            clip: true
            Layout.fillWidth: true
            Layout.fillHeight: true

            RowLayout {
                clip: true
                anchors.left: parent.left
                anchors.right: parent.right
                Layout.fillHeight: true

                Label {
                    id: createTimeLabel
                    text: conference.createTime.toLocaleString()
                    clip: true
                }
                Label {
                    id: titleLabel
                    text: conference.title
                    clip: true
                }
            }
            RowLayout {
                clip: true
                anchors.left: parent.left
                anchors.right: parent.right
                Layout.fillHeight: true
                visible: conference.type === Conference.Personal ? true : false

                Label {
                    id: userNameLabel
                    text: conference.host.owner.userName
                    clip: true
                }
                Label {
                    id: userIdLabel
                    text: qsTr("(" + conference.host.owner.userId + ")")
                    clip: true
                }
            }
            RowLayout {
                clip: true
                anchors.left: parent.left
                anchors.right: parent.right
                Layout.fillHeight: true

                Label {
                    id: countLabel
                    text: "0" + qsTr(" records")
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
