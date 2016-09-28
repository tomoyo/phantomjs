#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QNetworkReply>
#include <QFile>

class Downloader : public QObject
{
    Q_OBJECT

public:
    Downloader(QObject *parent, QFile *file, QNetworkReply *reply);
    void startDownload();

public slots:
    void handleReadyRead();
    void handleFinished();

signals:
    void downloadFinished(bool ok);

private:
   QNetworkReply *m_reply;
   QFile *m_file;
};

#endif // DOWNLOADER_H
