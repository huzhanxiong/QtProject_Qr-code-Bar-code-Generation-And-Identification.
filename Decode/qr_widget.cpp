#include "qr_widget.h"
#include <QDebug>
#include <QPainter>
//#include <qrencode/qrencode.h>
#include <zint.h>



qr_widget::qr_widget(QWidget *parent) :
    QWidget(parent)
{

}


void qr_widget::paintEvent(QPaintEvent *paint)
{
    if(ready_show == 1)
    {
        //ready_show = 0;
        struct zint_symbol* my_symbol = ZBarcode_Create();

        switch(code_type)
        {
            case 0:
                my_symbol->symbology = BARCODE_QRCODE;
                break;
            case 1:
                my_symbol->symbology = BARCODE_DATAMATRIX;
                break;
            default:
                break;
        }


        my_symbol->option_1 = 1;    //容错率
        my_symbol->option_2 = 1;    //版本号

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
            QPainter painter(this);
            QColor bg("white");
            painter.setBrush(bg);
            painter.setPen(Qt::NoPen);
            painter.drawRect(0,0,width(),height());

            QPixmap pix;
            pix.load("./build.png");

            painter.drawPixmap(20,20,191,191,pix);
        }

 /*   if(1){
        QColor fg("black");
        QColor bg("white");
        painter.setBrush(bg);
        painter.setPen(Qt::NoPen);
        painter.drawRect(0,0,width(),height());
        painter.setBrush(fg);
        const int s=qr->width>0?qr->width:1;
        const double w=width();
        const double h=height();
        const double aspect=w/h;
        const double scale=((aspect>1.0)?h:w)/s;
        for(int y=0;y<s;y++){
            const int yy=y*s;
            for(int x=0;x<s;x++){
                const int xx=yy+x;
                const unsigned char b=qr->data[xx];
                if(b &0x01){
                    const double rx1=x*scale, ry1=y*scale;
                    QRectF r(rx1, ry1, scale, scale);
                    painter.drawRects(&r,1);
                }
            }



        }
       // QRcode_free(qr);
    }
    else{
        QColor error("white");
        painter.setBrush(error);
        painter.drawRect(0,0,width(),height());
        qDebug()<<"QR FAIL: "<< ("errno");
    }*/
/*    QLabel* lb = new QLabel(this);
    lb->resize(50,50);
    lb->move((this->width()-50)/2,(this->height()-50)/2);
    QPixmap pe1("/Users/toby/Desktop/xxoo/Qt-App/WeixinPC/512.png");
    QPixmap tmp =pe1.scaled(50,50,Qt::IgnoreAspectRatio);
    lb->setPixmap(tmp);
    lb->show();  */
//    QRectF target((this->width()-50)/2,(this->height()-50)/2, 50, 50);
//    QRectF source(0, 0, 50, 50);
//    QImage img("/Users/toby/Desktop/xxoo/Qt-App/WeixinPC/128.png");
//    QImage tmpImg = img.scaled(50,50,Qt::IgnoreAspectRatio);
//    painter.drawImage(target,tmpImg,source);
//    painter.end();
//   qr=0;
    }



    if(ready_show == 2)
    {
        //ready_show = 0;
        struct zint_symbol* my_symbol = ZBarcode_Create();

        switch(code_type)
        {
            case 0:
                my_symbol->symbology = BARCODE_CODE11;
                break;
            case 1:
                my_symbol->symbology = BARCODE_CODE39;
                break;
            case 2:
                my_symbol->symbology = BARCODE_CODE128;
                break;

            default:
                break;
        }


        my_symbol->option_1 = 1;    //容错率
        my_symbol->option_2 = 1;    //版本号

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
            QPainter painter(this);
            QColor bg("white");
            painter.setBrush(bg);
            painter.setPen(Qt::NoPen);
            painter.drawRect(0,0,width(),height());

            QPixmap pix;
            pix.load("./build.png");

            painter.drawPixmap(10,10,601,91,pix);
        }
    }
}
