import QtQuick 2.7
import "./fss.js" as FlatSurface

Item {
    id: container

    Rectangle {
        id: background
        anchors.fill: parent
        color: "#111118"

        Canvas {
            id: canvas
            anchors.fill: parent
            renderTarget: Canvas.FramebufferObject
            renderStrategy: Canvas.Threaded
            clip: true

            property bool initialised: false
            property var surface

            onPaint: {
                if(!initialised){
                    surface.initialise()
                    initialised = true
                }
                else{
                    surface.animate()
                }
            }
            onPainted: {
                requestPaint()
            }
            onCanvasSizeChanged: {
                if(initialised){
                    surface.resize(canvasSize.width, canvasSize.height)
                }
            }

            Component.onCompleted: {
                surface = new FlatSurface.FSS.Surface(canvas)
            }
        }
    }
}
