import bb.cascades 1.0

TabbedPane {
     id : mainPage
    showTabsOnActionBar: true
    
 
    
    Tab {
        title: qsTr("Events")
       // imageSource: "asset:///images/upload-tab.png"
        
        EventsTab {
            id: eventsTab
        }
       
    }
        Tab {
                title: qsTr("Me")
             //   imageSource: "asset:///images/about-tab.png"
                
                AboutMeTab {
                    id: aboutMeTab
                }
            }
     
   
       
    
    onCreationCompleted: {
        // this slot is called when declarative scene is created
        // write post creation initialization here
        console.log("TabbedPane - onCreationCompleted()")

        // enable layout to adapt to the device rotation
        // don't forget to enable screen rotation in bar-bescriptor.xml (Application->Orientation->Auto-orient)
        OrientationSupport.supportedDisplayOrientation = SupportedDisplayOrientation.All;
    }
}
