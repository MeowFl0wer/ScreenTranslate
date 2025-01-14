#ifndef OCRPROCESSOR_H
#define OCRPROCESSOR_H
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <QImage>
#include <QString>

class OCRProcessor {
public:
    OCRProcessor();
    ~OCRProcessor();
    QString recognizeText(const QImage& image);

private:
    tesseract::TessBaseAPI* tessApi;
};

#endif // OCRPROCESSOR_H
