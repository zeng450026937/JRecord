import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import Qt.WebSockets 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Echo Server")

    function appendMessage(message) {
        messageBox.text += "\n" + message
    }

    WebSocketServer {
        id: server
        listen: true
        port: 1234
        onClientConnected: {
            webSocket.onTextMessageReceived.connect(function(message) {
                appendMessage(qsTr("Server received message: %1").arg(message));
                webSocket.sendTextMessage(message);
            });
        }
        onErrorStringChanged: {
            appendMessage(qsTr("Server error: %1").arg(errorString));
        }
    }

    WebSocket {
        id: socket
        url: server.url
        onTextMessageReceived: appendMessage(qsTr("Client received message: %1").arg(message))
        onStatusChanged: {
            if (socket.status == WebSocket.Error) {
                appendMessage(qsTr("Client error: %1").arg(socket.errorString));
            } else if (socket.status == WebSocket.Closed) {
                appendMessage(qsTr("Client socket closed."));
            }
        }
    }

    TextEdit {
        id: messageBox
        anchors.fill: parent

        MouseArea {
            anchors.fill: parent
            onClicked: {
                socket.sendTextMessage(qsTr("Hello Server!"));
            }
        }
    }
}
