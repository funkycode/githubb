#include "settings.hpp"

Settings::Settings()
{
		m_settings = new QSettings("ZogG","GitHuBB");
}
QString Settings::getUsername()
{
	return m_settings->value("username").toString();

}
QString Settings::getAppName()
{
	return m_settings->applicationName();
}
QString Settings::getAuthID()
{
	return m_settings->value("auth_id").toString();
}
QString Settings::getAuthToken()
{
	return m_settings->value("token").toString();
}
QString Settings::getPassword()
{
	return m_settings->value("password").toString();
}
void Settings::setUsername(QString username)
{
	m_settings->setValue("username",username);
}
void Settings::setAuthID(QString auth_id)
{
	m_settings->setValue("auth_id",auth_id);
}
void Settings::setAuthToken(QString token)
{
	m_settings->setValue("token",token);
}
void Settings::setPassword(QString password)
{
	m_settings->setValue("password",password);
}

