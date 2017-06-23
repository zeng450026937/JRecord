import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0
import com.nd.recordservice 1.0

ApplicationWindow {
    id: root
    width: 800
    height: 680
    visible: true

    flags: Qt.FramelessWindowHint | Qt.Window

    Page {
        id: page
        anchors.fill: parent
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
                    deltaX = mouse.x - xMouse
                    deltaY = mouse.y - yMouse
                    ApplicationWindow.window.setX(
                                ApplicationWindow.window.x + deltaX)
                    ApplicationWindow.window.setY(
                                ApplicationWindow.window.y + deltaY)
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
                    text: NdAccount.userName
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

            ListModel {
                id: viewModel
                ListElement {
                    sourceUri: "../UiRecord/UiRecord.qml"
                }
                ListElement {
                    sourceUri: "../UiFile/UiFile.qml"
                }
                ListElement {
                    sourceUri: "../UiSetting/UiSetting.qml"
                }
            }

            Repeater {
                model: viewModel

                Loader {
                    id: viewLoader
                    clip: true
                    source: sourceUri
                }
            }
        }

        Drawer {
            id: drawer
            width: root.width * 0.3
            height: root.height
            clip: true

            Rectangle {
                id: background
                width: parent.width
                height: column.implicitHeight + 30
                color: Qt.rgba(0.5, 0.5, 0.5, 0.2)
                clip: true
                Column {
                    id: column
                    spacing: 5
                    anchors.fill: parent
                    anchors.leftMargin: 10
                    anchors.rightMargin: 10
                    anchors.topMargin: 15
                    anchors.bottomMargin: 15
                    Image {
                        id: image
                        property bool rounded: true
                        property bool adapt: false

                        width: parent.width / 3
                        height: width
                        source: NdAccount.image
                        asynchronous: true
                        clip: true

                        layer.enabled: rounded
                        layer.effect: OpacityMask {
                            maskSource: Item {
                                width: image.width
                                height: image.height
                                Rectangle {
                                    anchors.centerIn: parent
                                    width: image.adapt ? image.width : Math.min(
                                                             image.width,
                                                             image.height)
                                    height: image.adapt ? image.height : width
                                    radius: Math.min(width, height)
                                }
                            }
                        }
                    }
                    Label {
                        clip: true
                        padding: 10
                        text: NdAccount.userName
                        font.bold: true
                        font.pointSize: 15
                    }
                    Label {
                        clip: true
                        width: parent.width
                        padding: 10
                        text: NdAccount.signature
                        wrapMode: Text.Wrap
                    }
                    Button {
                        clip: true
                        text: qsTr("Sign Out")
                        onClicked: NdAccount.active = false
                    }
                }
            }
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
