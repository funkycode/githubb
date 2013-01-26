 #include <QSettings>
#include "keys.cpp"

class Settings : public QObject
{
public:
	Settings();
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
    QSettings* m_settings;
private slots:

};
