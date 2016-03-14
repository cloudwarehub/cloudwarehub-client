#ifndef CLOUDWAREDIALOG_H
#define CLOUDWAREDIALOG_H

#include <QDialog>
#include <libde265/de265.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <wels/codec_api.h>

namespace Ui {
class CloudwareDialog;
}

class CloudwareDialog : public QDialog
{
    Q_OBJECT

public:
    int wid; /* x11 window id */
    explicit CloudwareDialog(QWidget *parent = 0);
    ~CloudwareDialog();
    void decode(const unsigned char *data, int length);

private:
    Ui::CloudwareDialog *ui;
    de265_decoder_context *ctx;
    int num;
    QImage* mImg;
    ISVCDecoder *pSvcDecoder;
    SBufferInfo sDstBufInfo;
    SParserBsInfo sDstParseInfo;

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // CLOUDWAREDIALOG_H
