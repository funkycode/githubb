// Default empty project template
#include "Githubb.hpp"
#include "githubapi.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>

using namespace bb::cascades;

Githubb::Githubb(bb::cascades::Application *app)
: QObject(app)
{
    // create scene document from main.qml asset
    // set parent to created document to ensure it exists for the whole application lifetime

    Settings *settings = new Settings();
    GitHubApi *gh_api = new GitHubApi(settings);



    QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);
	qml->setContextProperty("sets",settings);
	qml->setContextProperty("githubapi",gh_api);
    // create root object for the UI
    AbstractPane *root = qml->createRootObject<AbstractPane>();
    // set created root object as a scene
    app->setScene(root);
}

