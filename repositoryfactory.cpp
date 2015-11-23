#include <QDebug>
#include <QFileDialog>
#include <QApplication>

#include "repositoryfactory.h"

Repository::Repository(QString _path, QObject *parent)
    : QObject(parent)
    , path(_path)
{
}

 QString Repository::getPath()
 {
     return path;
 }


RepositoryFactory::RepositoryFactory(QObject *parent)
    : QObject(parent)
    , repos()
{
}

QDateTime RepositoryFactory::getCurrentDateTime() const {
    return QDateTime::currentDateTime();
}

bool RepositoryFactory::newRepo()
{
    QString dir = QFileDialog::getExistingDirectory(QApplication::activeWindow(), tr("Open Directory"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    qDebug() << "dir:" << dir;
    if(!dir.isEmpty())
    {
        repos.append(new Repository(dir));
        emit repoChanged();
    }
    return !dir.isEmpty();
}

QStringList RepositoryFactory::getExistingRepos()
{
    QStringList a;
    foreach(Repository* r,repos)
        a << r->getPath();
    return a;
}
