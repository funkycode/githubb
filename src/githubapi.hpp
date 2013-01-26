/*
 * githubapi.hpp
 *
 *  Created on: Jan 26, 2013
 *      Author: zogg
 */

#ifndef GITHUBAPI_HPP_
#define GITHUBAPI_HPP_

#include <iostream>
#include <QtCore>
#include <QtCore/QObject>
#include <QSettings>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkSession>
#include <bb/data/JsonDataAccess>
#include <QList>
#include <QtScript/QScriptEngine>
#include <QtScriptTools/QtScriptTools>
#include <QDebug>
#include <settings.hpp>
#include <bb/cascades/WebView>

using namespace bb::cascades;

class GitHubApi : public QObject {
	Q_OBJECT
public:

	void checkToken();
	void requestToken();
	GitHubApi(Settings *settings);

public slots:
	void getToken(QNetworkReply* reply);

private:
	QNetworkAccessManager *nam;
	Settings *user_settings;

};




#endif /* GITHUBAPI_HPP_ */
