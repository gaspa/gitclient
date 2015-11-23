#include <QObject>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QDateTime>
#include <QQmlContext>

#include "repositoryfactory.h"

static QJSValue example_qjsvalue_singletontype_provider
        (QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)

    static int seedValue = 5;
    QJSValue example = scriptEngine->newObject();
    example.setProperty("someProperty", seedValue++);
    return example;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("gaspa");
    QCoreApplication::setOrganizationDomain("gitclient.it");
    QCoreApplication::setApplicationName("gitclient");

    QQmlApplicationEngine engine;

//    qmlRegisterSingletonType("Qt.example.qjsvalueApi", 1, 0, "MyApi",
//                             example_qjsvalue_singletontype_provider);

    //METHOD 1 - http://doc.qt.io/qt-5/qtqml-cppintegration-contextproperties.html#setting-a-simple-context-property
    engine.rootContext()->setContextProperty("currentDateTime", QDateTime::currentDateTime());

    //METHOD 2 - http://doc.qt.io/qt-5/qtqml-cppintegration-contextproperties.html#setting-an-object-as-a-context-property
    RepositoryFactory data;
    engine.rootContext()->setContextProperty("repositoryData", &data);


    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
