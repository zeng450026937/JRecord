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
                boundsBehavior: Flickable.StopAtBounds

                width: 500
                height: parent.height

                model:  UserModel{
                    id: userModel
                }

                delegate: DeviceDelegate {
                    id: deviceDelegate
                    locked: model.locked
                    userName: model.userName
                    vad: model.vad
                    percent: model.batteryPercent
                    time: model.batteryTime
                    status: model.status
                }

                Keys.onPressed: console.log("key pressed.")
                Keys.onUpPressed: scrollbar.decrease()
                Keys.onDownPressed: scrollbar.increase()
                ScrollBar.vertical: ScrollBar { id:scrollbar }
            }
        }
        Button{
            anchors.centerIn: parent
            onClicked: {

            }
        }
    }
}
