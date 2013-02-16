/*
 * WebImageView.cpp
 *
 *  Created on: 4 oct. 2012
 *      Author: schutz
 */

#include "WebImageView.h"
#include <bb/cascades/Image>

WebImageView::WebImageView() {

	mNetManager = new QNetworkAccessManager;

}

const QUrl& WebImageView::url() const {
	return mUrl;
}

void WebImageView::setUrl(const QUrl& url) {

	mUrl = url;
	QNetworkReply * reply = mNetManager->get(QNetworkRequest(url));
	connect(reply,SIGNAL(finished()), this, SLOT(imageLoaded()));
	emit urlChanged();
}

void WebImageView::imageLoaded() {

	QNetworkReply * reply = qobject_cast<QNetworkReply*>(sender());
	setImage(Image(reply->readAll()));

}





