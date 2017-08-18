#include "textmessage.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include "textmessage_p.h"

TextMessage::TextMessage(QObject *parent)
    : MessagePacket(new TextMessagePrivate(this), parent) {}

TextMessage::TextMessage(TextMessagePrivate *d, QObject *parent)
    : MessagePacket(d, parent) {}

TextMessage::TextMessage(const QString &string, QObject *parent)
    : MessagePacket(new TextMessagePrivate(this), parent) {
  this->decode(string);
}

TextMessage::TextMessage(QString from, QString to, QString mode, QString action,
                         const QJsonObject &data, QObject *parent)
    : MessagePacket(new TextMessagePrivate(this), parent) {
  Q_D(TextMessage);
  d->from = from;
  d->to = to;
  d->command.insert(QStringLiteral("mode"), QJsonValue(mode));
  d->command.insert(QStringLiteral("action"), QJsonValue(action));
  d->data = data;
}

QString TextMessage::version() const { return d_func()->version; }

QString TextMessage::from() const { return d_func()->from; }

QString TextMessage::to() const { return d_func()->to; }

QString TextMessage::mode() const {
  return d_func()->command.value(QLatin1String("mode")).toString();
}

QString TextMessage::action() const {
  return d_func()->command.value(QLatin1String("action")).toString();
}

QJsonValue TextMessage::data() const { return d_func()->data; }

bool TextMessage::result() const { return d_func()->result; }

QJsonObject TextMessage::command() const { return d_func()->command; }

bool TextMessage::equals(MessagePacket *msg) {
  if (!msg) return false;
  Q_D(TextMessage);

  if (d->uuid == msg->uuid()) return true;

  TextMessage *textMsg = dynamic_cast<TextMessage *>(msg);
  if (textMsg && textMsg->command() == this->command()) return true;

  return false;
}

void TextMessage::decode(const QString &message) {
  QJsonParseError error;
  QJsonDocument jsonDocument =
      QJsonDocument::fromJson(message.toUtf8(), &error);

  if (error.error == QJsonParseError::NoError) {
    Q_D(TextMessage);
    if (jsonDocument.isObject()) {
      QJsonObject json = jsonDocument.object();

      d->version = json.value(QLatin1String("version")).toString();
      d->authorization = json.value(QLatin1String("authorization")).toString();
      d->from = json.value(QLatin1String("from")).toString();
      d->to = json.value(QLatin1String("to")).toString();
      d->command = json.value(QLatin1String("command")).toObject();
      d->data = json.value(QLatin1String("data"));
      d->result = json.value(QLatin1String("result")).toBool();
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
  json.insert(QStringLiteral("version"), QJsonValue(d->version));
  json.insert(QStringLiteral("authorization"), QJsonValue(d->authorization));
  json.insert(QStringLiteral("from"), QJsonValue(d->from));
  json.insert(QStringLiteral("to"), QJsonValue(d->to));
  json.insert(QStringLiteral("command"), QJsonValue(d->command));
  json.insert(QStringLiteral("data"), QJsonValue(d->data));
  json.insert(QStringLiteral("result"), QJsonValue(d->result));

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
  if (mode != d->command.value(QLatin1String("mode")).toString()) {
    d->command.insert(QStringLiteral("mode"), QJsonValue(mode));
    Q_EMIT modeChanged(d->command.value(QLatin1String("mode")).toString());
  }
}

void TextMessage::setAction(const QString &action) {
  Q_D(TextMessage);
  if (action != d->command.value(QLatin1String("action")).toString()) {
    d->command.insert(QStringLiteral("action"), QJsonValue(action));
    Q_EMIT modeChanged(d->command.value(QLatin1String("action")).toString());
  }
}

void TextMessage::setData(const QJsonValue &data) {
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
