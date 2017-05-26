TEMPLATE = lib
TARGET = RecordService
QT += qml quick websockets concurrent sql
CONFIG += plugin c++11

TARGET = $$qtLibraryTarget($$TARGET)
uri = com.nd.recordservice

# Input
SOURCES += \
    recordservice_plugin.cpp \
    account/account.cpp \
    account/nd_account.cpp \
    websocket/message_queue.cpp \
    model/fileentrymodel.cpp \
    model/account_model.cpp \
    model/device_model.cpp \
    sql_initialize.cpp \
    conference/conference.cpp \
    conference/conference_p.cpp \
    user/userlist.cpp \
    user/userlist_p.cpp \
    user/user.cpp \
    user/user_p.cpp \
    user/devicedescription.cpp \
    websocket/textmessage.cpp \
    websocket/textmessage_p.cpp \
    websocket/binarymessage.cpp \
    websocket/binarymessage_p.cpp \
    websocket/message_thread.cpp \
    websocket/message_thread_p.cpp \
    websocket/transport_thread.cpp \
    websocket/transport_thread_p.cpp \
    websocket/process_thread.cpp \
    websocket/process_thread_p.cpp \
    service/service_base.cpp \
    service/service_base_p.cpp \
    websocket/message_queue_p.cpp \
    user/devicedescription_p.cpp \
    client/client.cpp \
    client/client_p.cpp \
    model/sql_initialize.cpp \
    model/user_model.cpp

HEADERS += \
    recordservice_plugin.h \
    account/account.h \
    account/nd_account.h \
    websocket/message_queue.h \
    websocket/message_packet.h \
    model/fileentrymodel.h \
    model/account_model.h \
    model/device_model.h \
    sql_initialize.h \
    protocol.h \
    conference/conference.h \
    conference/conference_p.h \
    user/userlist.h \
    user/userlist_p.h \
    user/user.h \
    user/user_p.h \
    user/devicedescription.h \
    websocket/textmessage.h \
    websocket/textmessage_p.h \
    websocket/binarymessage.h \
    websocket/binarymessage_p.h \
    websocket/message_thread.h \
    websocket/message_thread_p.h \
    websocket/transport_thread.h \
    websocket/transport_thread_p.h \
    websocket/process_thread.h \
    websocket/process_thread_p.h \
    service/service_base.h \
    service/service_base_p.h \
    websocket/message_queue_p.h \
    user/devicedescription_p.h \
    client/client.h \
    client/client_p.h \
    model/sql_initialize.h \
    model/user_model.h

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
