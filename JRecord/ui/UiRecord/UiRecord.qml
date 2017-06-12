import QtQuick 2.7
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
                //boundsBehavior: Flickable.StopAtBounds

                width: 500
                height: parent.height

                header: Rectangle{
                    clip: true
                    width: deviceList.width
                    height: 40
                    color: "lightgray"
                    Label{
                        anchors.left: parent.left
                        anchors.leftMargin: 20
                        anchors.verticalCenter: parent.verticalCenter
                        clip: true
                        text: qsTr("device list")
                        font.bold: true
                        verticalAlignment: Qt.AlignVCenter
                    }
                }
                headerPositioning: ListView.PullBackHeader

                model:  UserModel{
                    id: userModel
                }

                delegate: Component{

                    Loader{
                        width: parent.width
                        height: 40
                        property int deviceIndex: index
                        property string deviceUuid
                        source: "./DeviceDelegate.qml"
                    }
                }

                Keys.onUpPressed: scrollbar.decrease()
                Keys.onDownPressed: scrollbar.increase()
                ScrollBar.vertical: ScrollBar { id:scrollbar }
            }
        }
    }
}
