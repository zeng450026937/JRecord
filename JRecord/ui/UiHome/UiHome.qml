import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import com.nd.recordservice 1.0

ApplicationWindow {
    id: root
    width: 800
    height: 680
    visible: true

    flags: Qt.FramelessWindowHint | Qt.Window

    color: "black"

    Page{
        id: page
        anchors.fill: parent
        anchors.margins: 1
        clip: true

        header: ToolBar {
            id: toolBar
            clip: true

            MouseArea {
                id: mouseArea
                property int xMouse
                property int yMouse
                property int deltaX
                property int deltaY
                anchors.fill: parent
                acceptedButtons: Qt.LeftButton
                onPressed: {
                    xMouse = mouse.x
                    yMouse = mouse.y
                }
                onPositionChanged: {
                    deltaX = mouse.x-xMouse
                    deltaY = mouse.y-yMouse
                    ApplicationWindow.window.setX(ApplicationWindow.window.x + deltaX)
                    ApplicationWindow.window.setY(ApplicationWindow.window.y + deltaY)
                }
            }

            RowLayout {
                anchors.fill: parent
                spacing: 0

                ToolButton {
                    text: qsTr("=")
                    clip: true
                    font.bold: true
                    activeFocusOnTab: false
                    focusPolicy: Qt.NoFocus
                    onClicked: drawer.visible = !drawer.visible
                }

                Label {
                    clip: true
                    text: Account.username == ""?"admin":Account.username
                    Layout.fillWidth: true
                    horizontalAlignment: Qt.AlignRight
                }
                ToolButton {
                    text: qsTr("_")
                    clip: true
                    font.bold: true
                    activeFocusOnTab: false
                    focusPolicy: Qt.NoFocus
                    onClicked: ApplicationWindow.window.showMinimized()
                }
                ToolButton {
                    text: qsTr("x")
                    clip: true
                    font.bold: true
                    activeFocusOnTab: false
                    focusPolicy: Qt.NoFocus
                    onClicked: ApplicationWindow.window.close()
                }
            }

            Label {
                clip: true
                text: qsTr("JRecord")
                font.bold: true
                font.pointSize: 15
                font.family: "Verdana"
                anchors.centerIn: parent
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }
        }

        SwipeView {
            id: swipeView
            clip: true
            anchors.fill: parent
            currentIndex: tabBar.currentIndex

            UiRecord {
                clip: true
            }
            UiFile {
                clip: true
            }
            UiSetting {
                clip: true
            }
        }

        Drawer {
            id: drawer
            width: root.width * 0.3
            height: root.height
        }

        footer: TabBar {
            id: tabBar
            clip: true
            currentIndex: swipeView.currentIndex

            background: Rectangle {
                anchors.fill: parent
                color: "transparent"
            }

            TabButton {
                text: qsTr("Record")
                clip: true
            }
            TabButton {
                text: qsTr("File")
                clip: true
            }
            TabButton {
                text: qsTr("Setting")
                clip: true
            }
        }
    }
}
