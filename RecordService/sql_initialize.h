#ifndef SQL_INITIALIZE_H
#define SQL_INITIALIZE_H

#include <QString>
#include <QVariant>

class SqlInitialize {
  SqlInitialize()
      : accountTypeTableName(QStringLiteral("AccountType")),
        accountStatusTableName(QStringLiteral("AccountStatus")),
        accountsTableName(QStringLiteral("Accounts")),
        deviceTypeTableName(QStringLiteral("DeviceType")),
        deviceStatusTableName(QStringLiteral("DeviceStatus")),
        deviceVadTableName(QStringLiteral("DeviceVAD")),
        devicesTableName(QStringLiteral("Devices")),
        conferenceTypeTableName(QStringLiteral("ConferenceType")),
        conferencesTableName(QStringLiteral("Conferencs")),
        fileTypeTableName(QStringLiteral("FileType")),
        fileSuffixTableName(QStringLiteral("FileSuffix")),
        filesTableName(QStringLiteral("Files")),
        downloadsTableName(QStringLiteral("Downloads")) {}

  ~SqlInitialize() {}

 public:
  static SqlInitialize *GetInstance();

  const QString accountTypeTableName;
  const QString accountStatusTableName;
  const QString accountsTableName;
  const QString deviceTypeTableName;
  const QString deviceStatusTableName;
  const QString deviceVadTableName;
  const QString devicesTableName;
  const QString conferenceTypeTableName;
  const QString conferencesTableName;
  const QString fileTypeTableName;
  const QString fileSuffixTableName;
  const QString filesTableName;
  const QString downloadsTableName;

  QVariantList accountTypeList;
  QVariantList accountStatusList;
  QVariantList accountsList;
  QVariantList deviceTypeList;
  QVariantList deviceStatusList;
  QVariantList deviceVadList;
  QVariantList devicesList;
  QVariantList conferenceTypeList;
  QVariantList conferencesList;
  QVariantList fileTypeList;
  QVariantList fileSuffixList;
  QVariantList filesList;
  QVariantList downloadsList;

  void connectToDatabase();

  void createAccountTypeTable();
  void createAccountStatusTable();
  void createAccountsTable();

  void createDeviceTypeTable();
  void createDeviceStatusTable();
  void createDeviceVadTable();
  void createDevicesTable();

  void createConferencTypeTable();
  void createConferencsTable();
  void createFileTypeTable();
  void createFileSuffixTable();
  void createFilesTable();

  void createDownloadsTable();
};

#endif  // SQL_INITIALIZE_H
