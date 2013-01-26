// Default empty project template
import bb.cascades 1.0

// creates one page with a label
Page {
    Container {
        layout: StackLayout {
                    
                }
        Label {
            text: qsTr("Hello World")
            textStyle.base: SystemDefaults.TextStyles.BigText
            verticalAlignment: VerticalAlignment.Center
            horizontalAlignment: HorizontalAlignment.Center
        }
        TextField {
            id:username
        }
         TextField {
                    id:password
                }
                
                Button{
                    id: saveUser
                    text:"save"
                    onClicked: {
                        
                        sets.setUsername(username.text);
                        sets.setPassword(password.text);
                      }
                }
                 Button{
                                    id: request
                                    text:"check"
                                    onClicked: {
                                        
                                        githubapi.checkToken();
                                       
                                      }
                                }
    }
}

