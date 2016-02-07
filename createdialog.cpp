#include "createdialog.h"
#include "ui_createdialog.h"

CreateDialog::CreateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateDialog)
{
    ui->setupUi(this);
    connect(&nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(loadVersionList(QNetworkReply*)));

    QUrl url("https://api.github.com/repos/minetest/minetest/releases");
    qDebug() << "Url: " << url.toString();
    QNetworkRequest request(url);
    nam.get(request);

}

CreateDialog::~CreateDialog()
{
    delete ui;
}

void CreateDialog::loadVersionList(QNetworkReply *reply)
{
    qDebug() << "Reply code: " << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug() << "Redirection url: " << reply->attribute(QNetworkRequest::RedirectionTargetAttribute).toString();
    qDebug() << "Data size: " << reply->size();
    QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
    QJsonArray array = document.array();

    qDebug() << "Array size: " << array.size();
    for (int i = 0; i < array.size(); i++)
        ui->versionList->addItem(array.at(i).toObject().value("tag_name").toString());
    reply->deleteLater();
}

void CreateDialog::newProfile(ProfileManager *manager)
{
    //Profile
}
