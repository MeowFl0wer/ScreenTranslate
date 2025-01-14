#include "ocrprocessor.h"


OCRProcessor::OCRProcessor() {
    tessApi = new tesseract::TessBaseAPI();
    if (tessApi->Init(nullptr, "eng")) {  // "eng"是英语的语言包
        qCritical() << "Tesseract初始化失败!";
    }
}

OCRProcessor::~OCRProcessor() {
    tessApi->End();
    delete tessApi;
}

QString OCRProcessor::recognizeText(const QImage& image) {
    // 将QImage转换为Pix格式
    Pix* pix = pixCreate(image.width(), image.height(), 8);
    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            QRgb pixel = image.pixel(x, y);
            int gray = qGray(pixel);
            pixSetPixel(pix, x, y, gray);
        }
    }

    // 调用Tesseract进行识别
    tessApi->SetImage(pix);
    char* outText = tessApi->GetUTF8Text();
    QString result = QString::fromUtf8(outText);
    delete[] outText;
    pixDestroy(&pix);

    return result;
}
