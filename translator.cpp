#include "translator.h"

Translator::Translator(const QString& apiKey) {
    this->apiKey = apiKey;
}

QString Translator::translate(const QString& text, const QString& targetLang) {
    QNetworkAccessManager* manager = new QNetworkAccessManager();
    QNetworkRequest request(QUrl("https://translation.googleapis.com/language/translate/v2?key=" + apiKey));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["q"] = text;
    json["target"] = targetLang;
    QJsonDocument doc(json);

    QNetworkReply* reply = manager->post(request, doc.toJson());

    QObject::connect(reply, &QNetworkReply::finished, [reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray responseData = reply->readAll();
            QJsonDocument responseDoc = QJsonDocument::fromJson(responseData);
            QJsonObject responseObj = responseDoc.object();
            QString translatedText = responseObj["data"].toObject()["translations"].toArray()[0].toObject()["translatedText"].toString();
            qDebug() << "Translated text:" << translatedText;
        } else {
            qDebug() << "Error:" << reply->errorString();
        }
        reply->deleteLater();
    });

    return "";  // 翻译结果会在回调中返回
}
