import QtQuick 2.7
import QtWebEngine 1.4

Item {
    id: container

    WebEngineView {
        id: webView
        anchors.fill: parent
        url: "canvas-basic.html"
    }
}
