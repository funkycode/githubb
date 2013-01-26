#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

#include <QObject>
#include <QString>
#include <QSettings>
#include <QDebug>
#include <keys.cpp>

class Settings : public QObject {
Q_OBJECT
public:
	Settings(QObject *parent = 0);
	QString getAuthID();
	QString getAuthToken();
	QString getUsername();
	QString getPassword();
	QString getAppName();
	Q_INVOKABLE void setPassword(QString password);
	Q_INVOKABLE void setUsername(QString username);
	void setAuthToken(QString token);
	void setAuthID(QString auth_id);
public slots:
private:
    QSettings* m_sets;
private slots:

};

#endif /* SETTINGS_HPP_ */
