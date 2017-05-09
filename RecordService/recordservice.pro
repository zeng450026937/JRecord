TEMPLATE = lib
TARGET = RecordService
QT += qml quick websockets concurrent
CONFIG += plugin c++11

TARGET = $$qtLibraryTarget($$TARGET)
uri = com.nd.recordservice

# Input
SOURCES += \
    recordservice_plugin.cpp \
    account/account.cpp \
    account/nd_account.cpp \
    websocket/websocket.cpp \
    websocket/websocket_p.cpp \
    websocket/message_processor.cpp \
    websocket/message_queue.cpp \
    websocket/message_packet.cpp

HEADERS += \
    recordservice_plugin.h \
    account/account.h \
    account/nd_account.h \
    websocket/websocket.h \
    websocket/websocket_p.h \
    websocket/message_processor.h \
    websocket/message_queue.h \
    websocket/message_packet.h

DISTFILES = qmldir

DESTDIR = ../Out/com/nd/recordservice

!equals(_PRO_FILE_PWD_, $$OUT_PWD/$$DESTDIR) {
    copy_qmldir.target = $$OUT_PWD/$$DESTDIR/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"

    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}
