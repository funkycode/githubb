/*
 * userapi.cpp
 *
 *  Created on: Feb 15, 2013
 *      Author: zogg
 */
#include "userapi.hpp"


UserApi::UserApi(Settings *settings, QDeclarativePropertyMap* aboutMeMap) {
	user_settings = settings;
	nam = new QNetworkAccessManager();
	aboutMeData = aboutMeMap;

}

void UserApi::eventsForUsersResponce(QNetworkReply* reply) {

	if (reply->error() != QNetworkReply::NoError) {

			QString err_str = reply->errorString();
			qDebug() << "error: " << err_str << endl;
			reply->close();
			return;

		}
	QString response = reply->readAll();
	reply->close();

	//response = QString::fromUtf8(reply->readAll());
	qDebug() << "whole response is : "<<response;



}

void UserApi::aboutMeResponce(QNetworkReply* reply) {


	if (reply->error() != QNetworkReply::NoError) {

			QString err_str = reply->errorString();
			qDebug() << "error: " << err_str << endl;
			reply->close();
			//disconnect(this, SLOT(aboutMeResponce(QNetworkReply*)));
			return;

		}
	QString response = reply->readAll();
	reply->close();
	//disconnect(this, SLOT(aboutMeResponce(QNetworkReply*)));
	//response = QString::fromUtf8(reply->readAll());
	qDebug() << "whole response is : "<<response;
	bb::data::JsonDataAccess jda;
	QVariant list = jda.loadFromBuffer(response);
	//QVariant name =  ;
	if(list.toMap()["name"].toString() != "")
	{
		qDebug()<< "we got name: "<<list.toMap()["name"].toString();
		aboutMeData->insert("name", list.toMap()["name"].toString());

	}
	if(list.toMap()["login"].toString() != "")
	{
		qDebug()<< "we got name: "<<list.toMap()["login"].toString();
		aboutMeData->insert("login", list.toMap()["login"].toString());

	}

	if(list.toMap()["avatar_url"].toString() != "")
		{
			qDebug()<< "we got avatar_url: "<<list.toMap()["avatar_url"].toString();
			aboutMeData->insert("avatar", list.toMap()["avatar_url"].toString());

		}
	if(list.toMap()["location"].toString() != "")
			{
				qDebug()<< "we got location: "<<list.toMap()["location"].toString();
				aboutMeData->insert("location", list.toMap()["location"].toString());

			}
	if(list.toMap()["hireable"].toBool())
				{
					qDebug()<< "we got hireable: "<<list.toMap()["location"].toBool();
					aboutMeData->insert("hireable", list.toMap()["location"].toBool());

				}
	if(list.toMap()["blog"].toString() != "")
				{
					qDebug()<< "we got blog: "<<list.toMap()["blog"].toString();
					aboutMeData->insert("blog", list.toMap()["location"].toString());

				}
	if(list.toMap()["bio"].toString() != "")
					{
						qDebug()<< "we got bio: "<<list.toMap()["bio"].toString();
						aboutMeData->insert("bio", list.toMap()["bio"].toString());

					}
	if(list.toMap()["public_repos"].toString() != "")
						{
							qDebug()<< "we got public_repos: "<<list.toMap()["public_repos"].toString();
							aboutMeData->insert("public_repos", list.toMap()["public_repos"].toString());

						}
	if(list.toMap()["followers"].toString() != "")
							{
								qDebug()<< "we got followers: "<<list.toMap()["followers"].toString();
								aboutMeData->insert("followers", list.toMap()["followers"].toInt());

							}
	if(list.toMap()["following"].toString() != "")
								{
									qDebug()<< "we got following: "<<list.toMap()["following"].toString();
									aboutMeData->insert("following", list.toMap()["following"].toString());

								}
	if(list.toMap()["created_at"].toString() != "")
									{
										qDebug()<< "we got created_at: "<<list.toMap()["created_at"].toString();
										aboutMeData->insert("created_at", list.toMap()["created_at"].toString());

									}



     emit loadingFinish();

	/*
	 *
	 * "company": null,
  "blog": "",
  "location": "Israel",
  "email": null,
  "hireable": false,
  "bio": "",
  "public_repos": 18,
  "followers": 10,
  "following": 50,
  "html_url": "https://github.com/funkycode",
  "created_at": "2011-02-01T06:57:47Z",
  "updated_at": "2013-02-16T01:08:21Z",
  "public_gists": 1,
  "total_private_repos": 0,
  "owned_private_repos": 0,
  "disk_usage": 9218,
  "collaborators": 0,
  "plan": {
    "name": "free",
    "space": 307200,
    "collaborators": 0,
    "private_repos": 0
  },
  "private_gists": 1
	 *
	 *
	 *
	 */

		// Add the data to the model



}

void UserApi::getEventsForUser() {

	QNetworkAccessManager* namEvents = new QNetworkAccessManager();
	QUrl url("https://api.github.com/events");
	QNetworkRequest* request = new QNetworkRequest(url);
	request->setRawHeader("Authorization",
				"token " + QByteArray(QString("%1").arg(user_settings->getAuthToken()).toAscii()));

	connect(namEvents, SIGNAL(finished(QNetworkReply*)), this, SLOT(eventsForUsersResponce(QNetworkReply*)));

    QNetworkReply *reply = namEvents->get(*request);
}

void UserApi::getAboutMe() {

	QNetworkAccessManager* namAboutMe = new QNetworkAccessManager();
	QUrl url("https://api.github.com/user");
	QNetworkRequest* request = new QNetworkRequest(url);
	request->setRawHeader("Authorization",
				"token " + QByteArray(QString("%1").arg(user_settings->getAuthToken()).toAscii()));

	connect(namAboutMe, SIGNAL(finished(QNetworkReply*)), this, SLOT(aboutMeResponce(QNetworkReply*)));

    QNetworkReply *reply = namAboutMe->get(*request);


}


