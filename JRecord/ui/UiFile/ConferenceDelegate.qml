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
        anchors.rightMargin: 10
        anchors.leftMargin: 10
        anchors.bottomMargin: 10
        anchors.topMargin: 10
        anchors.fill: parent

        Rectangle {
            id: rectangle
            color: "lightgray"
            width: 60
            height: width
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
                    text: conference.createTime.toLocaleString()
                }
                Label {
                    id: titleLabel
                    text: conference.title
                }
            }
            RowLayout {
                anchors.left: parent.left
                anchors.right: parent.right
                Layout.fillHeight: true
                visible: conference.type === Conference.Personal ? true : false

                Label {
                    id: userNameLabel
                    text: conference.host.owner.userName
                }
                Label {
                    id: userIdLabel
                    text: qsTr("(" + conference.host.owner.userId + ")")
                }
            }
            RowLayout {
                anchors.left: parent.left
                anchors.right: parent.right
                Layout.fillHeight: true

                Label {
                    id: countLabel
                    text: "0" + qsTr(" records")
                }
                Label {
                    id: tagLabel
                    text: conference.tag
                }
                Label {
                    id: gpsLabel
                    text: conference.gps
                }
            }
        }
    }
}
