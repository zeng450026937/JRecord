import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import "./FlatSurface"

Item {
    id: root
    width: 430
    height: 330

    Page {
        id: page
        anchors.fill: parent
        padding: 0

        header: ToolBar{
            id: toolBar

            background: Rectangle{
                color: Qt.rgba(0,0,0,0)
            }
            RowLayout{
                anchors.fill: parent
                Label{
                    Layout.fillWidth: true
                }
                ToolButton{
                    text: qsTr("_")
                    width: implicitWidth
                    onClicked: {
                        ApplicationWindow.window.showMinimized()
                    }
                }
                ToolButton{
                    text: qsTr("x")
                    width: implicitWidth
                    onClicked: {
                        ApplicationWindow.window.close()
                    }
                }
            }
            MouseArea{
                propagateComposedEvents: true
                anchors.fill: parent
            }
        }

        FlatSurface {
            id: surface
            anchors.top: parent.top
            width: parent.width
            height: 180
        }

        Text {
            id: title
            anchors.centerIn: surface
            text: qsTr("JRecord")
            color: "white"
            font.bold : true
            font.pointSize: 25
        }

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
    }
}
