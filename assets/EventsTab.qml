import bb.cascades 1.0

Page {
    attachedObjects: [
        Login {
            id: login
        }
    ]
    id: eventsTab
    Container {
        Button {
            text: "login"
            onClicked: {
                login.open();
            }
        }

        //        Button {
        //            text:"events"
        //             onClicked: {
        //
        //                                    userapi.getEventsForUser();
        //
        //                                  }
        //        }
        //          Button {
        //                    text:"token"
        //                     onClicked: {
        //
        //                                            sets.getAuthToken();
        //
        //                                          }
        //                }
    }
}
