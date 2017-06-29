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
    account/account_p.cpp \
    account/nd_account.cpp \
    account/nd_account_p.cpp \
    client/client.cpp \
    client/client_p.cpp \
    conference/conference.cpp \
    conference/conference_p.cpp \
    device/device.cpp \
    device/device_p.cpp \
    manager/device_manager.cpp \
    manager/device_manager_p.cpp \
    manager/record_manager.cpp \
    manager/record_manager_p.cpp \
    model/device_model.cpp \
    model/device_model_p.cpp \
    model/sql_initializer.cpp \
    record/record.cpp \
    record/record_p.cpp \
    service/service_base.cpp \
    service/service_base_p.cpp \
    user/user.cpp \
    user/user_p.cpp \
    websocket/protocol/proto_base.cpp \
    websocket/protocol/proto_base_p.cpp \
    websocket/protocol/proto_binary.cpp \
    websocket/protocol/proto_binary_p.cpp \
    websocket/protocol/proto_conf.cpp \
    websocket/protocol/proto_conf_p.cpp \
    websocket/protocol/proto_info.cpp \
    websocket/protocol/proto_info_p.cpp \
    websocket/binarymessage.cpp \
    websocket/binarymessage_p.cpp \
    websocket/message_queue.cpp \
    websocket/message_queue_p.cpp \
    websocket/message_socket.cpp \
    websocket/message_socket_p.cpp \
    websocket/message_thread.cpp \
    websocket/message_thread_p.cpp \
    websocket/process_thread.cpp \
    websocket/process_thread_p.cpp \
    websocket/textmessage.cpp \
    websocket/textmessage_p.cpp \
    websocket/transport_thread.cpp \
    websocket/transport_thread_p.cpp \
    manager/conference_manager.cpp \
    manager/conference_manager_p.cpp \
    model/conference_model.cpp \
    model/conference_model_p.cpp \
    websocket/protocol/proto_person.cpp \
    websocket/protocol/proto_person_p.cpp \
    websocket/protocol/proto_mobile.cpp \
    websocket/protocol/proto_mobile_p.cpp \
    websocket/task/task_p.cpp \
    websocket/task/task.cpp \
    websocket/task/task_manager.cpp \
    websocket/task/task_manager_p.cpp \
    websocket/task/task_info.cpp \
    websocket/message_packet.cpp \
    websocket/message_packet_p.cpp

HEADERS += \
    recordservice_plugin.h \
    account/account.h \
    account/account_p.h \
    account/nd_account.h \
    account/nd_account_p.h \
    client/client.h \
    client/client_p.h \
    conference/conference.h \
    conference/conference_p.h \
    device/device.h \
    device/device_p.h \
    manager/device_manager.h \
    manager/device_manager_p.h \
    manager/record_manager.h \
    manager/record_manager_p.h \
    model/device_model.h \
    model/device_model_p.h \
    model/sql_initializer.h \
    record/record.h \
    record/record_p.h \
    service/service_base.h \
    service/service_base_p.h \
    user/user.h \
    user/user_p.h \
    websocket/protocol/proto_base.h \
    websocket/protocol/proto_base_p.h \
    websocket/protocol/proto_binary.h \
    websocket/protocol/proto_binary_p.h \
    websocket/protocol/proto_conf.h \
    websocket/protocol/proto_conf_p.h \
    websocket/protocol/proto_info.h \
    websocket/protocol/proto_info_p.h \
    websocket/binarymessage.h \
    websocket/binarymessage_p.h \
    websocket/message_packet.h \
    websocket/message_queue.h \
    websocket/message_queue_p.h \
    websocket/message_socket.h \
    websocket/message_socket_p.h \
    websocket/message_thread.h \
    websocket/message_thread_p.h \
    websocket/process_thread.h \
    websocket/process_thread_p.h \
    websocket/textmessage.h \
    websocket/textmessage_p.h \
    websocket/transport_thread.h \
    websocket/transport_thread_p.h \
    manager/conference_manager.h \
    manager/conference_manager_p.h \
    model/conference_model.h \
    model/conference_model_p.h \
    websocket/protocol/proto_person.h \
    websocket/protocol/proto_person_p.h \
    websocket/protocol/proto_mobile.h \
    websocket/protocol/proto_mobile_p.h \
    websocket/task/task.h \
    websocket/task/task_p.h \
    websocket/task/task_manager.h \
    websocket/task/task_manager_p.h \
    websocket/task/task_info.h \
    websocket/message_packet_p.h

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
