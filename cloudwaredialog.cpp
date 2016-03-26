#include <QtGui>
#include <libde265/de265.h>
#include "cloudwaredialog.h"
#include "ui_cloudwaredialog.h"
#include "libyuv/convert_from.h"


CloudwareDialog::CloudwareDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CloudwareDialog)
{
    ui->setupUi(this);

    this->mImg = new QImage(QSize(this->width() ,this->height()), QImage::Format_ARGB32);
    this->qImg = NULL;

    WelsCreateDecoder(&this->pSvcDecoder);
    SDecodingParam sDecParam = {0};
    sDecParam.sVideoProperty.eVideoBsType = VIDEO_BITSTREAM_DEFAULT;
    sDecParam.eOutputColorFormat = videoFormatI420;

    //for Parsing only, the assignment is mandatory
    sDecParam.bParseOnly = false;

    this->pSvcDecoder->Initialize(&sDecParam);


}

CloudwareDialog::~CloudwareDialog()
{
    this->pSvcDecoder->Uninitialize();
    WelsDestroyDecoder(this->pSvcDecoder);
    delete ui;
}

void CloudwareDialog::decode(const unsigned char *buf, int length)
{
    qDebug("decoding...");
    unsigned char *pData[3];
    DECODING_STATE state = this->pSvcDecoder->DecodeFrame2(buf, length, pData, &this->sDstBufInfo);
    if (state != 0) {
        qDebug("decode error");
    }
    if (this->sDstBufInfo.iBufferStatus == 1) {
        int width = this->sDstBufInfo.UsrData.sSystemBuffer.iWidth;
        int height = this->sDstBufInfo.UsrData.sSystemBuffer.iHeight;
        int *stride = this->sDstBufInfo.UsrData.sSystemBuffer.iStride;

        //QImage qimg = QImage(QSize(width ,height), QImage::Format_ARGB32);

        libyuv::I420ToARGB(pData[0], stride[0], pData[1], stride[1], pData[2], stride[2], this->mImg->bits(), this->mImg->bytesPerLine(), width, height);
        this->qImg = this->mImg;
        repaint();
        this->qImg = NULL; /* forbid system repaint use mImg */
    }


    return;

}

void CloudwareDialog::paintEvent(QPaintEvent *event)
{
    qDebug("paintEvent");
    QPainter painter(this);

    if (this->qImg) {
        QRect videoRect = qImg->rect();
//        videoRect.moveCenter(this->rect().center());

//        if (!videoRect.contains(event->rect())) {
//            QRegion region = event->region();
//            region = region.subtracted(videoRect);

//            QBrush brush = palette().background();

//            foreach (const QRect &rect, region.rects()) {
//                painter.fillRect(rect, brush);
//            }
//        }
        qDebug("painted!");
        painter.drawImage(videoRect, *qImg);
    } else {
        painter.fillRect(event->rect(), palette().background());
    }
}
