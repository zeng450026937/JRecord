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

                model:  UserModel{
                    id: userModel
                }

                delegate: ItemDelegate {
                    width: deviceList.width
                    height: label.implicitHeight
                    Label {
                        id: label
                        anchors.fill: parent
                        text: model.userId + "\n" +
                              model.userType + "\n" +
                              model.userName + "\n" +
                              model.deviceType + "\n" +
                              model.deviceName + "\n" +
                              model.batteryPercent + "\n" +
                              model.batteryTime + "\n" +
                              model.status + "\n" +
                              model.vad + "\n" +
                              model.locked
                    }
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

                userList.pull();
            }
        }
    }

    UserList{
        id: userList
        service: ServiceBase
        list: [
            User{
                userId: qsTr("userId")
                userName: qsTr("userName")
            }
        ]
    }
}
