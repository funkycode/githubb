#include <githubapi.hpp>
#include <QtCore/QList>



GitHubApi::GitHubApi(Settings *settings) {
	user_settings = settings;
	nam = new QNetworkAccessManager();
	connect(nam, SIGNAL(finished(QNetworkReply*)), this,
				SLOT(getToken(QNetworkReply*)));

}

void GitHubApi::getToken(QNetworkReply* reply) {

	if (reply->error() != QNetworkReply::NoError) {

		QString err_str = reply->errorString();
		qDebug() << "error: " << err_str << endl;
		reply->close();
		return;

	}

	bb::data::JsonDataAccess jda;
	QString response = reply->readAll();
	reply->close();
	//response = QString::fromUtf8(reply->readAll());
	qDebug() << "whole response is : "<<response;
	QVariant jsonva = jda.loadFromBuffer(response);
	if(jsonva.isValid())
	{
		qDebug() << "json is valid";
	}
	else
	{
		qDebug() << "json is not valid";
		return;
	}

//


if(jsonva.canConvert(QVariant::Map)) {
	//


	         qDebug() << "searching for " <<  user_settings->getAppName() ;
	         QVariant var = jsonva;
					QVariant app =  var.toMap()["app"];
					if (app.toMap()["name"].toString() == user_settings->getAppName())
					{
						user_settings->setAuthToken(var.toMap()["token"].toString());
						user_settings->setAuthID( var.toMap()["id"].toString());
						qDebug()<< "found token " << user_settings->getAuthToken();
						return;
					}
					else
					{
						qDebug() << "appname is:" << app.toMap()["name"].toString();
					}
}
if(jsonva.canConvert(QVariant::List)) {
//


         qDebug() << "searching for " <<  user_settings->getAppName() ;
			foreach(const QVariant &var, jsonva.toList()) {
				QVariant app =  var.toMap()["app"];
				if (app.toMap()["name"].toString() == user_settings->getAppName())
				{
					user_settings->setAuthToken(var.toMap()["token"].toString());
					user_settings->setAuthID( var.toMap()["id"].toString());
					qDebug()<< "found token " << user_settings->getAuthToken();
					return;
				}
				else
				{
					qDebug() << "appname is:" << app.toMap()["name"].toString();
				}
	}
			qDebug()<< "seems no f% authorization for " << user_settings->getAppName();
			qDebug()<< "Gonna try request one \o/";
			requestToken();
}
	return;

}

void GitHubApi::checkToken() {
	QUrl url("https://api.github.com/authorizations");
	QNetworkRequest* request = new QNetworkRequest(url);
	request->setRawHeader("Authorization", "Basic " + QByteArray(QString("%1:%2").arg(user_settings->getUsername()).arg(user_settings->getPassword()).toAscii()).toBase64());
    QNetworkReply *reply = nam->get(*request);

}

void GitHubApi::requestToken() {

	QUrl url("https://api.github.com/authorizations");
	QNetworkRequest* request = new QNetworkRequest(url);
	request->setRawHeader("Authorization", "Basic " + QByteArray(QString("%1:%2").arg(user_settings->getUsername()).arg(user_settings->getPassword()).toAscii()).toBase64());
	QByteArray postdata;

	//POST data
	    QString json_req = "{";
	    json_req.append("\"client_id\":");
	    json_req.append("\"");
	    json_req.append(CLIENT_ID);
	    json_req.append("\",");
	    json_req.append("\"client_secret\":");
	    json_req.append("\"");
	    json_req.append(CLIENT_SECRET);
	    json_req.append("\"");
	    json_req.append("}");
	//POST data
	postdata.append(json_req.toUtf8());

    QNetworkReply *reply = nam->post(*request, postdata);

}


