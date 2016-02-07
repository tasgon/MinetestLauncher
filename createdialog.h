#ifndef CREATEDIALOG_H
#define CREATEDIALOG_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include "profilemanager.h"

namespace Ui {
class CreateDialog;
}

class CreateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateDialog(QWidget *parent = 0);
    static void newProfile(ProfileManager*);

    ~CreateDialog();

private:
    Ui::CreateDialog *ui;
    QNetworkAccessManager nam;

private slots:
    void loadVersionList(QNetworkReply*);
};

#endif // CREATEDIALOG_H
