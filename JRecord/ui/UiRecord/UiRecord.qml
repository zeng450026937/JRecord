import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import com.nd.recordservice 1.0

Item {
    id: recordUi
    clip: true
    anchors.fill: parent

    property var dm: ServiceBase.deviceManager()

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
                width: recordUi.width * 2 / 5
                height: recordUi.height

                header: Rectangle {
                    clip: true
                    width: deviceList.width
                    height: 40
                    color: "lightgray"
                    Label {
                        anchors.left: parent.left
                        anchors.leftMargin: 20
                        anchors.verticalCenter: parent.verticalCenter
                        clip: true
                        text: qsTr("DEVICE LIST")
                        font.bold: true
                        verticalAlignment: Qt.AlignVCenter
                    }
                }
                headerPositioning: ListView.PullBackHeader

                model: dm.model()

                delegate: Component {

                    Loader {
                        property var device: dm.device(model.uuid)
                        width: deviceList.width
                        height: 40
                        source: "./DeviceDelegate.qml"
                    }
                }

                ScrollBar.vertical: ScrollBar {
                    id: scrollbar
                }
            }
        }
    }
}
