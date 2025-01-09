#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScreen>
#include <QPixmap>
#include <QTimer>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 获取屏幕对象
    QScreen *screen = QGuiApplication::primaryScreen();

    if (screen) {
        // 截取屏幕的固定区域（例如：从(100, 100)到(600, 400)的区域）
        QRect region(100, 100, 500, 300);
        QPixmap screenshot = screen->grabWindow(0, region.x(), region.y(), region.width(), region.height());

        // 将截图显示在QLabel上
        ui->label->setPixmap(screenshot.scaled(ui->label->size(), Qt::KeepAspectRatio));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
