// Default empty project template
#ifndef Githubb_HPP_
#define Githubb_HPP_

#include <QObject>
#include "githubapi.hpp"

namespace bb { namespace cascades { class Application; }}

/*!
 * @brief Application pane object
 *
 *Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class Githubb : public QObject
{
    Q_OBJECT
public:
    Githubb(bb::cascades::Application *app);
    virtual ~Githubb() {}
};


#endif /* Githubb_HPP_ */
