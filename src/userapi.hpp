/*
 * userapi.hpp
 *
 *  Created on: Feb 15, 2013
 *      Author: zogg
 */

#ifndef USERAPI_HPP_
#define USERAPI_HPP_

#include <githubapi.hpp>

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
#include <bb/cascades/WebView>

using namespace bb::cascades;

class UserApi : public QObject {
	Q_OBJECT
public:

	UserApi(Settings *settings, QDeclarativePropertyMap* aboutMeMap);

	Q_INVOKABLE void getEventsForUser();
	Q_INVOKABLE void getAboutMe();
//	Q_INVOKABLE void requestToken();


signals:
	void loadingFinish();

public slots:
	void eventsForUsersResponce(QNetworkReply* reply);
	void aboutMeResponce(QNetworkReply* reply);

private:
	QNetworkAccessManager *nam;
	Settings *user_settings;
    QDeclarativePropertyMap* aboutMeData;

};







#endif /* USERAPI_HPP_ */
