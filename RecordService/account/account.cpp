#include "account.h"
#include "nd_account.h"

Account::Account(QObject *parent):
    QObject(parent),
    status_(Logout)
{
    client_ = new NdAccount(this);

    connect(client_, SIGNAL(loginResult(QString,bool,QString)),
            this, SLOT(onLogined(QString,bool,QString)));
    connect(client_, SIGNAL(logoutResult(QString,bool,QString)),
            this, SLOT(onLogouted(QString,bool,QString)));
}

Account::~Account()
{
    if(status_ == Login)
        client_->userLogout();
}

void Account::logIn()
{
    client_->userLogin(username_, password_);
    this->setStatus(Logining);
}
void Account::logOut()
{
    client_->userLogout();
    this->setStatus(Logouting);
}

QString Account::username() const
{
    return username_;
}
QString Account::password() const
{
    return password_;
}
QString Account::errorString() const
{
    return errorString_;
}

void Account::setUsername(QString username)
{
    if(username_ != username){
        username_ = username;
        Q_EMIT usernameChanged(username_);
    }
}
void Account::setPassword(QString password)
{
    if(password_ != password){
        password_ = password;
        Q_EMIT usernameChanged(password);
    }
}

void Account::setStatus(Status status)
{
    if(status_ != status){
        status_ = status;
        Q_EMIT statusChanged(status_);
    }
}

void Account::setErrorString(QString errorString)
{
    if(errorString_ != errorString){
        errorString_ = errorString;
        Q_EMIT errorStringChanged(errorString_);
    }
}

void Account::onLogined(QString account, bool ok, QString reason)
{
    if(account != username_)
        return;

    if(ok){
        this->setStatus(Login);
    }
    else{
        this->setStatus(Error);
    }

    this->setErrorString(reason);
}
void Account::onLogouted(QString account, bool ok, QString reason)
{
    if(account != username_)
        return;

    if(ok){
        this->setStatus(Logout);
    }
    else{
        this->setStatus(Error);
    }

    this->setErrorString(reason);
}
