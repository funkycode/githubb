// Default empty project template
import bb.cascades 1.0

// creates one page with a label

Sheet {
    id: login
    Page {
        Container {
            layout: StackLayout {
            }
            Label {
                text: qsTr("Login")
                textStyle.base: SystemDefaults.TextStyles.BigText
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
            }
            Label {
                 id : usernameL
                text: qsTr("Username: ") +sets.getUsername();
                textStyle.base: SystemDefaults.TextStyles.BigText
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
             //    visible: (sets.getUsername() != "" && sets.getUsername() != undefined ) ? true : false
            }
            TextField {
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
                id: username
                visible: (sets.getUsername() != "" || sets.getUsername() != undefined ) ? false : true
            }
            
            TextField {
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
                id: password
                visible: (sets.getPassword() != "" || sets.getPassword() != undefined ) ? false : true
            }
            Button {
                id: saveUser
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
                text: "save"
                onClicked: {
                    sets.setUsername(username.text);
                    sets.setPassword(password.text);
                }
            }
            Button {
                id: request
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
                text: "authorize"
                onClicked: {
                    githubapi.checkToken();
                    login.close();
                }
            }
        }
    }
}
