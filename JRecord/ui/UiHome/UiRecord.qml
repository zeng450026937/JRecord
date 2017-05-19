import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import com.nd.recordservice 1.0

Item {
    id: recordUi
    clip: true
    width: 600
    height: 400

    Pane {
        anchors.fill: parent
        padding: 0
        clip: true

        StackView {
            id: stackView
            clip: true
            anchors.fill: parent
            initialItem: ListView {
                id: deviceList
                clip: true
                width: 300
                height: parent.height

                model:  UserEntryModel {
                    id: userModel
                }

                delegate: ItemDelegate {
                    width: deviceList.width
                    height: 140
                    Label {
                        anchors.fill: parent
                        text: model.account + "\n" +
                              model.userName + "\n" +
                              model.deviceName + "\n" +
                              model.selected + "\n" +
                              model.batteryPercent + "\n" +
                              model.batteryTime + "\n" +
                              model.deviceStatus + "\n" +
                              model.voiceStatus
                    }
                }

                Keys.onUpPressed: scrollbar.decrease()
                Keys.onDownPressed: scrollbar.increase()
                ScrollBar.vertical: ScrollBar { id:scrollbar }
            }
        }
    }
}
