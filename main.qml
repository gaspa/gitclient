import QtQuick 2.2
import QtQuick.Controls 1.1
//import Qt.example.qjsvalueApi 1.0 as ExampleApi


ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }
    Row
    {
        id: buttonRow

        Button
        {
            id: newRepoButton
            text: "New Repo"
            onClicked: repositoryData.newRepo()
        }

        Button
        {
            id: back
            text: "<-"
            onClicked: stack.pop()
        }
    }


    StackView {
        id: stack
        initialItem: repository_view

        width: parent.width
        height: parent.height
        anchors.top: buttonRow.bottom

        anchors.horizontalCenter: parent

//        property int someValue: ExampleApi.MyApi.someProperty

        Component {
            id: repository_view

            ListView {
                width: 180
                height: 200

                model: repositoryData.repoPaths
                delegate: MouseArea{
                        Text {
                            text: modelData
                        }
                        onClicked: {
                            console.log("clicked on: ")
                            stack.push(branch_view)
                        }
                }
            }
        }
        Component {
            id: branch_view

            MouseArea {
                Text {
                    text: stack.depth
                    anchors.centerIn: parent
                }
                onClicked: stack.push(branch_view)
            }
        }

    }
}
