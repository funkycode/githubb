import bb.cascades 1.0
import bb.data 1.0
import org.labsquare 1.0
import QtQuick 1.0

Page {
    id: aboutMeTab
    Container {
        Container {
            id: dataContainer
            visible: false

            //            layout: StackLayout {
            //                orientation: LayoutOrientation.LeftToRight
            //            }
            Container {
                maxHeight: 250
                layout: StackLayout {
                    orientation: LayoutOrientation.TopToBottom
                }
                Container {
                    layout: StackLayout {
                        orientation: LayoutOrientation.LeftToRight
                    }
                    layoutProperties: StackLayoutProperties {
                        spaceQuota: 3
                    }
                    WebImageView {
                        layoutProperties: StackLayoutProperties {
                            spaceQuota: 1
                        }
                        id: avatar
                        maxHeight: 210
                        preferredHeight: 210
                        scalingMethod: ScalingMethod.AspectFit
                        url: aboutme.avatar
                        visible: (aboutme.avatar != "" && aboutme.login != avatar ) ? true : false
                    }
                    Label {
                        layoutProperties: StackLayoutProperties {
                            spaceQuota: 1
                        }
                        text: aboutme.login
                        textStyle.base: SystemDefaults.TextStyles.BigText
                        verticalAlignment: VerticalAlignment.Center
                        horizontalAlignment: HorizontalAlignment.Center
                        visible: (aboutme.login != "" && aboutme.login != undefined ) ? true : false
                    }
                }
                //                    layout: StackLayout {
                //                        orientation: LayoutOrientation.LeftToRight
                //                    }
                //                    layoutProperties: StackLayoutProperties {
                //                    spaceQuota: 1
                //
                //                    }
                Container {
                    layout: StackLayout {
                        orientation: LayoutOrientation.LeftToRight
                    }
                    layoutProperties: StackLayoutProperties {
                        spaceQuota: 1
                    }
                    verticalAlignment: VerticalAlignment.Center
                    horizontalAlignment: HorizontalAlignment.Center
                    Label {
                        layoutProperties: StackLayoutProperties {
                            spaceQuota: 1
                        }
                        text: "followers: " + aboutme.followers
                        //textStyle.base: SystemDefaults.TextStyles.BigText
                        verticalAlignment: VerticalAlignment.Center
                        horizontalAlignment: HorizontalAlignment.Center
                        visible: (aboutme.followers != "" && aboutme.followers != undefined ) ? true : false
                    }
                    Label {
                        layoutProperties: StackLayoutProperties {
                            spaceQuota: 1
                        }
                        text: "following: " + aboutme.following
                        //textStyle.base: SystemDefaults.TextStyles.BigText
                        verticalAlignment: VerticalAlignment.Center
                        horizontalAlignment: HorizontalAlignment.Center
                        visible: (aboutme.following != "" && aboutme.following != undefined ) ? true : false
                    }
                    Label {
                        layoutProperties: StackLayoutProperties {
                            spaceQuota: 1
                        }
                        text: "pub. repos: " + aboutme.public_repos
                        //textStyle.base: SystemDefaults.TextStyles.BigText
                        verticalAlignment: VerticalAlignment.Center
                        horizontalAlignment: HorizontalAlignment.Center
                        visible: (aboutme.public_repos != "" && aboutme.public_repos != undefined ) ? true : false
                    }
                }
                //    }
            }
            Label {
                text: qsTr("Name: ") + aboutme.name
                textStyle.base: SystemDefaults.TextStyles.BigText
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
                visible: (aboutme.name != "" && aboutme.name != undefined ) ? true : false
            }
            Label {
                text: qsTr("Location: ") + aboutme.location
                textStyle.base: SystemDefaults.TextStyles.BigText
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
                visible: (aboutme.location != "" && aboutme.location != undefined ) ? true : false
            }
            Label {
                text: qsTr("created_at: ") + aboutme.created_at
                textStyle.base: SystemDefaults.TextStyles.BigText
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
                visible: (aboutme.created_at != "" && aboutme.created_at != undefined ) ? true : false
            }
            Label {
                text: qsTr("Hireable")
                textStyle.base: SystemDefaults.TextStyles.BigText
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
                visible: (aboutme.hireable != "" && aboutme.hireable != undefined ) ? true : false
            }
        }
        Container {
            id: loaderContainer
            horizontalAlignment: HorizontalAlignment.Center
            verticalAlignment: VerticalAlignment.Center
            visible: true
            Label {
                text: qsTr("Loading ...")
                textStyle.base: SystemDefaults.TextStyles.BigText
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
            }
            ActivityIndicator {
                id: myIndicator
                preferredWidth: 500
                preferredHeight: 500
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
            }
        }
        onCreationCompleted: {
            myIndicator.start();
            userapi.getAboutMe();
        }
        attachedObjects: [
            Connections {
                target: userapi
                onLoadingFinish: {
                    loaderContainer.visible = false;
                    dataContainer.visible = true;
                }
            }
        ]
    }
}
