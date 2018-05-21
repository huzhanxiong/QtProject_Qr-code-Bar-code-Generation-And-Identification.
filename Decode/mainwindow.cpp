#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QPainter>
#include <QMessageBox>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include <QZXing.h>
#include <libdmtx/dmtx.h>
#include <zint.h>
//#include <QTextCodec>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QTextCodec *codec = QTextCodec::codecForName("utf8");
    //QTextCodec::setCodecForLocale(codec);
//ui->QR_widget->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Btn_openFile_clicked()
{

/*    QPixmap qrCode = QPixmap::grabWidget(ui->QR_widget);
    ui->image->setPixmap(qrCode);

    qrCode.save("../Decode/Hello world!.png", "PNG");
*/

    QString fileName = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("选择待识别图片"),
                                                    QApplication::applicationDirPath(),
                                                    tr("All Files (*.*)"));
    ui->file_name->setText(fileName);
    ui->image->setPixmap(QPixmap(ui->file_name->text()));
    QZXing decoder;
    QString qrmsg = decoder.decodeImageFromFile(ui->file_name->text());
    ui->Recog_text->setText(qrmsg);

/*
    struct zint_symbol* my_symbol = ZBarcode_Create();
    my_symbol->symbology = BARCODE_QRCODE;

    char* testvalue = "./build.png";
    strcpy(my_symbol->outfile, testvalue);

    QString str = QString::fromLocal8Bit("梦想");
    ZBarcode_Encode(my_symbol, (unsigned char*)str.toStdString().c_str(), 0);
    ZBarcode_Print(my_symbol, 0);
    ZBarcode_Delete(my_symbol);


    QImage qImg("./build.png");
    if(qImg.isNull())
        qDebug() << "qImg is empty.";
    else ui->image->setPixmap(QPixmap::fromImage(qImg));
*/




    if(0)
    {
    size_t          width, height, bytesPerPixel;
    //unsigned char   str[] = "30Q324343430794<OQQ";
    unsigned char  *pxl;
    DmtxEncode     *enc;
    DmtxImage      *img;
    DmtxDecode     *dec;
    DmtxRegion     *reg;
    DmtxMessage    *msg;

   /* fprintf(stdout, "input:  \"%s\"\n", str); */

    /* 1) ENCODE a new Data Matrix barcode image (in memory only) */

    uchar* strx = (uchar*)ui->file_name->text().toStdString().c_str();
    uchar* strn = strx;
    int strNum = 0;
    while(*strn)
    {
        strNum++;
        strn++;
    }

    enc = dmtxEncodeCreate();
    assert(enc != NULL);
    dmtxEncodeDataMatrix(enc, strNum, strx);
qDebug() << "test  " << strx << " " << strNum;
    /* 2) COPY the new image data before releasing encoding memory */

    width = dmtxImageGetProp(enc->image, DmtxPropWidth);
    height = dmtxImageGetProp(enc->image, DmtxPropHeight);
    bytesPerPixel = dmtxImageGetProp(enc->image, DmtxPropBytesPerPixel);

    pxl = (unsigned char *)malloc(width * height * bytesPerPixel);
    assert(pxl != NULL);
    memcpy(pxl, enc->image->pxl, width * height * bytesPerPixel);

    dmtxEncodeDestroy(&enc);

    /* 3) DECODE the Data Matrix barcode from the copied image */

    img = dmtxImageCreate(pxl, width, height, DmtxPack24bppRGB);
    assert(img != NULL);


    QImage qImg;
    qImg = QImage((const uchar*)pxl, img->width, img->height,
                         img->height * img->channelCount,
                            QImage::Format_RGB888);
    if(qImg.isNull())
        qDebug() << "qImg is empty.";
//    else ui->image->setPixmap(QPixmap::fromImage(qImg));


    dec = dmtxDecodeCreate(img, 1);
    assert(dec != NULL);

    reg = dmtxRegionFindNext(dec, NULL);
    if(reg != NULL) {
    msg = dmtxDecodeMatrixRegion(dec, reg, DmtxUndefined);
    if(msg != NULL) {
        //fputs("output: \"", stdout);
        //fwrite(msg->output, sizeof(unsigned char), msg->outputIdx, stdout);
        //fputs("\"\n", stdout);

    std::string str(reinterpret_cast<char*>(msg->output));
    qDebug() << str.c_str();

        dmtxMessageDestroy(&msg);
          }
        dmtxRegionDestroy(&reg);
       }

       dmtxDecodeDestroy(&dec);
       dmtxImageDestroy(&img);
       free(pxl);
    }
}



void MainWindow::paintEvent(QPaintEvent *pe)
{

}

void MainWindow::on_buildCode_Btn_clicked()
{
    ui->QR_widget->ready_show = 1;
    ui->QR_widget->code_text = ui->text_input->toPlainText();
    ui->QR_widget->code_type = ui->chooseCode_Box->currentIndex();
    ui->QR_widget->update();


/*
QString code_text = ui->text_input->toPlainText();
    struct zint_symbol* my_symbol = ZBarcode_Create();
    my_symbol->symbology = BARCODE_QRCODE;

    char* testvalue = "./build.png";
    strcpy(my_symbol->outfile, testvalue);

    ZBarcode_Encode(my_symbol, (unsigned char*)code_text.toStdString().c_str(), 0);
    ZBarcode_Print(my_symbol, 0);
    ZBarcode_Delete(my_symbol);


    QImage qImg("./build.png");
    if(qImg.isNull())
        qDebug() << "qImg is empty.";
    else
    {
        ui->image_build->setStyleSheet("border-image: url(./build.png)");

    }
*/
}


void MainWindow::on_Btn_savePic_clicked()
{
    QString file_path = QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("请选择图片保存路径"), "./");
    QString file = file_path + ".png";
qDebug() << file;
    QPixmap pixmap = ui->QR_widget->grab(QRect(0, 0, 231, 231));
    pixmap.save(file, "png");
}


void MainWindow::on_buildCode_Btn_bar_clicked()
{
    ui->QR_widget_bar->ready_show = 2;
    ui->QR_widget_bar->code_text = ui->text_input_bar->toPlainText();
    ui->QR_widget_bar->code_type = ui->chooseCode_Box_bar->currentIndex();
    ui->QR_widget_bar->update();
}


void MainWindow::on_Btn_savePic_bar_clicked()
{
    QString file_path = QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("请选择图片保存路径"), "./");
    QString file = file_path + ".png";
qDebug() << file;
    QPixmap pixmap = ui->QR_widget_bar->grab(QRect(0, 0, 621, 101));
    pixmap.save(file, "png");
}


void MainWindow::on_Btn_openFile_bar_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("选择待识别图片"),
                                                    QApplication::applicationDirPath(),
                                                    tr("All Files (*.*)"));
    ui->file_name_bar->setText(fileName);
    ui->image_bar->setPixmap(QPixmap(ui->file_name_bar->text()));
    QZXing decoder;
    QString qrmsg = decoder.decodeImageFromFile(ui->file_name_bar->text());
qDebug() << qrmsg;

    ui->Recog_text_bar->setText(qrmsg);
}
