#include "downloader.h"

#include <QNetworkReply>
#include <QUrl>
#include <QDateTime>
#include <QFile>
#include <QDebug>

#include "phantom.h"

Downloader::Downloader(QObject *parent, QFile *file, QNetworkReply *reply) :
    QObject(parent), m_file(file), m_reply(reply)
{
    qDebug() << "Downloader: Downloader";

    m_file->setParent(this);
    m_reply->setParent(this);

    connect(reply, SIGNAL(readyRead()), this, SLOT(handleReadyRead()), Qt::QueuedConnection);
    connect(reply, SIGNAL(finished()), this, SLOT(handleFinished()), Qt::QueuedConnection);
}

void Downloader::startDownload() {
    handleReadyRead();

    if( m_reply->isFinished() ) {
        handleFinished();
    }
}

void Downloader::handleReadyRead()
{
    qDebug() << "Downloader: handleReadyRead" << m_reply->bytesAvailable();

    m_file->write(m_reply->readAll());
}

void Downloader::handleFinished()
{
    qDebug() << "Downloader: handleFinished";

    m_file->close();
    this->deleteLater();

    emit downloadFinished(true);
}
