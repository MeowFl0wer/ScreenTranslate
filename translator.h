#ifndef TRANSLATOR_H
#define TRANSLATOR_H
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

class Translator {
public:
    Translator(const QString& apiKey);
    QString translate(const QString& text, const QString& targetLang);

private:
    QString apiKey;
};

#endif // TRANSLATOR_H
