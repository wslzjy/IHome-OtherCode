#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <QHash>
#include <QUrl>
#include <qmath.h>
#include <QStringList>
#include "httpreply.h"
#include "socketclass.h"

class DownLoad : public QObject
{
    Q_OBJECT

public:
    explicit DownLoad(QObject *parent = 0);

    int NewDownLoad(QUrl url);

    int ReStartDownLoad(QUrl url);

    int StopDownLoad(QUrl url);

    void SetSocketService(SocketClass * service);

    int CancelTask(QUrl url);

private:
    QString speed(double);
    QString timeFormat(int);

signals:
    //void Update(QString url, QString, QString,  qint64, qint64);

    //void UpdateSpeed(QString, QString);
    //void UpdateTime(QString,QString);
    //void UpdatSize(QString,qint64, qint64);

    //void taskFinish(QString url);

public slots:
    void UpdateProcess(QString url, qint64 recesize, qint64 totalsize, int usedTime);

    void Finish(QString url);
private:
    QHash<QString,HttpReply*>  downloadSet;
    QHash<QString, int> usedTime_;
    SocketClass *service;
    int timer;
};

#define TASKNOTEXIST            200
#define TASKEXIST               201

#endif // DOWNLOAD_H
