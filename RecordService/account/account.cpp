#include "account.h"
#include "nd_account.h"

Account::Account(QObject *parent):
    QObject(parent),
    status_(Logout)
{
    client_ = new NdAccount(this);

    connect(client_, SIGNAL(loginResult(QString,bool,QString)),
            this, SLOT(onSignIned(QString,bool,QString)));
    connect(client_, SIGNAL(logoutResult(QString,bool,QString)),
            this, SLOT(onSignOuted(QString,bool,QString)));
}

Account::~Account()
{
    if(status_ == Login)
        client_->userSignOut();
}

void Account::signIn()
{
    client_->userSignIn(username_, password_);
    this->setStatus(Logining);
}
void Account::signOut()
{
    client_->userSignOut();
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

void Account::onSignIned(QString account, bool ok, QString reason)
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
void Account::onSignOuted(QString account, bool ok, QString reason)
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
