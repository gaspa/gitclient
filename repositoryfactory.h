#ifndef REPOSITORYFACTORY_H
#define REPOSITORYFACTORY_H

#include <QObject>
#include <QDateTime>

class Repository: public QObject
{
    Q_OBJECT

public:
    explicit Repository(QString _path, QObject *parent = 0);

    Q_INVOKABLE QString getPath();
private:
    QString path;
};

class RepositoryFactory : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QStringList repoPaths READ getExistingRepos NOTIFY repoChanged)

public:
    explicit RepositoryFactory(QObject *parent = 0);

    Q_INVOKABLE QDateTime getCurrentDateTime() const;

    Q_INVOKABLE bool newRepo();

    Q_INVOKABLE QStringList getExistingRepos();
signals:

    void repoChanged();

public slots:

private:
    QList<Repository*> repos;

};

#endif // REPOSITORYFACTORY_H
