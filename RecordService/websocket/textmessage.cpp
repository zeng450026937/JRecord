#include "textmessage.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include "textmessage_p.h"

TextMessage::TextMessage(QObject *parent)
    : QObject(parent), d_ptr(new TextMessagePrivate(this)) {}

TextMessage::TextMessage(TextMessagePrivate *d, QObject *parent)
    : QObject(parent), d_ptr(d) {}

TextMessage::TextMessage(const QString &string, QObject *parent)
    : QObject(parent), d_ptr(new TextMessagePrivate(this)) {
  this->decode(string);
}

TextMessage::TextMessage(QString from, QString to, QString mode, QString action,
                         const QJsonObject &data, QObject *parent)
    : QObject(parent), d_ptr(new TextMessagePrivate(this)) {
  Q_D(TextMessage);
  d->from = from;
  d->to = to;
  d->command.insert("mode", QJsonValue(mode));
  d->command.insert("action", QJsonValue(action));
  d->data = data;
}

TextMessage::~TextMessage() {}

QString TextMessage::version() const { return d_func()->version; }

QString TextMessage::from() const { return d_func()->from; }

QString TextMessage::to() const { return d_func()->to; }

QString TextMessage::mode() const {
  return d_func()->command.value("mode").toString();
}

QString TextMessage::action() const {
  return d_func()->command.value("action").toString();
}

QJsonObject TextMessage::data() const { return d_func()->data; }

bool TextMessage::result() const { return d_func()->result; }

void TextMessage::decode(const QString &message) {
  QJsonParseError error;
  QJsonDocument jsonDocument =
      QJsonDocument::fromJson(message.toUtf8(), &error);

  if (error.error == QJsonParseError::NoError) {
    Q_D(TextMessage);
    if (jsonDocument.isObject()) {
      QJsonObject json = jsonDocument.object();

      d->version = json.value(QStringLiteral("version")).toString();
      d->authorization = json.value(QStringLiteral("authorization")).toString();
      d->from = json.value(QStringLiteral("from")).toString();
      d->to = json.value(QStringLiteral("to")).toString();
      d->command = json.value(QStringLiteral("command")).toObject();
      d->data = json.value(QStringLiteral("data")).toObject();
      d->result = json.value(QStringLiteral("result")).toBool();
    } else if (jsonDocument.isArray()) {
      qDebug() << "unsupported json string format, json object is prefered.";
    }
  } else {
    qDebug() << "parse json string failed" << error.errorString();
  }
}

QString TextMessage::encode() {
  Q_D(TextMessage);

  QJsonObject json;
  json.insert("version", QJsonValue(d->version));
  json.insert("authorization", QJsonValue(d->authorization));
  json.insert("from", QJsonValue(d->from));
  json.insert("to", QJsonValue(d->to));
  json.insert("command", QJsonValue(d->command));
  json.insert("data", QJsonValue(d->data));
  json.insert("result", QJsonValue(d->result));

  QJsonDocument document;
  document.setObject(json);

  return document.toJson(QJsonDocument::Compact);
}

void TextMessage::setVersion(const QString &version) {
  Q_D(TextMessage);
  if (version != d->version) {
    d->version = version;
    Q_EMIT versionChanged(d->version);
  }
}

void TextMessage::setFrom(const QString &from) {
  Q_D(TextMessage);
  if (from != d->from) {
    d->from = from;
    Q_EMIT fromChanged(d->from);
  }
}

void TextMessage::setTo(const QString &to) {
  Q_D(TextMessage);
  if (to != d->to) {
    d->to = to;
    Q_EMIT toChanged(d->to);
  }
}

void TextMessage::setMode(const QString &mode) {
  Q_D(TextMessage);
  if (mode != d->command.value("mode").toString()) {
    d->command.insert("mode", QJsonValue(mode));
    Q_EMIT modeChanged(d->command.value("mode").toString());
  }
}

void TextMessage::setAction(const QString &action) {
  Q_D(TextMessage);
  if (action != d->command.value("action").toString()) {
    d->command.insert("action", QJsonValue(action));
    Q_EMIT modeChanged(d->command.value("action").toString());
  }
}

void TextMessage::setData(const QJsonObject &data) {
  Q_D(TextMessage);
  if (data != d->data) {
    d->data = data;
    Q_EMIT dataChanged(d->data);
  }
}

void TextMessage::setResult(const bool &result) {
  Q_D(TextMessage);
  if (result != d->result) {
    d->result = result;
    Q_EMIT resultChanged(d->result);
  }
}
