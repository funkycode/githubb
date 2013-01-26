#include <settings.hpp>


Settings::Settings(QObject *parent)
{
	   m_sets = new QSettings("ZogG", "GitHuBB");
}

QString Settings::getUsername()
{
	return m_sets->value("username").toString();

}
QString Settings::getAppName()
{
	return m_sets->applicationName();
}
QString Settings::getAuthID()
{
	return m_sets->value("auth_id").toString();
}
QString Settings::getAuthToken()
{
	return m_sets->value("token").toString();
}
QString Settings::getPassword()
{
	return m_sets->value("password").toString();
}
void Settings::setUsername(QString username)
{
	qDebug() << "username is set to "<< username;
	m_sets->setValue("username",username);
}
void Settings::setAuthID(QString auth_id)
{
	m_sets->setValue("auth_id",auth_id);
}
void Settings::setAuthToken(QString token)
{
	m_sets->setValue("token",token);
}
void Settings::setPassword(QString password)
{
	m_sets->setValue("password",password);
}


