#pragma once

#include <QQmlExtensionPlugin>
class QJSEngine;

class RecordServicePlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);

};
