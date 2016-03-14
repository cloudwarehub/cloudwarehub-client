#-------------------------------------------------
#
# Project created by QtCreator 2016-03-10T15:28:10
#
#-------------------------------------------------

QT       += core gui network 

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cloudwarehub-client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cipclient.cpp \
    cipchannel.cpp \
    cipchannelmaster.cpp \
    cipchannelevent.cpp \
    cipchanneldisplay.cpp \
    cloudwaredialog.cpp \
    vendor/libyuv/source/compare.cc \
    vendor/libyuv/source/compare_common.cc \
    vendor/libyuv/source/compare_gcc.cc \
    vendor/libyuv/source/compare_neon.cc \
    vendor/libyuv/source/compare_neon64.cc \
    vendor/libyuv/source/compare_win.cc \
    vendor/libyuv/source/convert.cc \
    vendor/libyuv/source/convert_argb.cc \
    vendor/libyuv/source/convert_from.cc \
    vendor/libyuv/source/convert_from_argb.cc \
    vendor/libyuv/source/convert_jpeg.cc \
    vendor/libyuv/source/convert_to_argb.cc \
    vendor/libyuv/source/convert_to_i420.cc \
    vendor/libyuv/source/cpu_id.cc \
    vendor/libyuv/source/mjpeg_decoder.cc \
    vendor/libyuv/source/mjpeg_validate.cc \
    vendor/libyuv/source/planar_functions.cc \
    vendor/libyuv/source/rotate.cc \
    vendor/libyuv/source/rotate_any.cc \
    vendor/libyuv/source/rotate_argb.cc \
    vendor/libyuv/source/rotate_common.cc \
    vendor/libyuv/source/rotate_gcc.cc \
    vendor/libyuv/source/rotate_mips.cc \
    vendor/libyuv/source/rotate_neon.cc \
    vendor/libyuv/source/rotate_neon64.cc \
    vendor/libyuv/source/rotate_win.cc \
    vendor/libyuv/source/row_any.cc \
    vendor/libyuv/source/row_common.cc \
    vendor/libyuv/source/row_gcc.cc \
    vendor/libyuv/source/row_mips.cc \
    vendor/libyuv/source/row_neon.cc \
    vendor/libyuv/source/row_neon64.cc \
    vendor/libyuv/source/row_win.cc \
    vendor/libyuv/source/scale.cc \
    vendor/libyuv/source/scale_any.cc \
    vendor/libyuv/source/scale_argb.cc \
    vendor/libyuv/source/scale_common.cc \
    vendor/libyuv/source/scale_gcc.cc \
    vendor/libyuv/source/scale_mips.cc \
    vendor/libyuv/source/scale_neon.cc \
    vendor/libyuv/source/scale_neon64.cc \
    vendor/libyuv/source/scale_win.cc \
    vendor/libyuv/source/video_common.cc

HEADERS  += mainwindow.h \
    cipchannel.h \
    cipchannelmaster.h \
    cipclient.h \
    cip_protocol.h \
    cip_defs.h \
    cipchannelevent.h \
    cloudwaredialog.h \
    cipchanneldisplay.h \
    vendor/libyuv/include/libyuv/basic_types.h \
    vendor/libyuv/include/libyuv/compare.h \
    vendor/libyuv/include/libyuv/convert.h \
    vendor/libyuv/include/libyuv/convert_argb.h \
    vendor/libyuv/include/libyuv/convert_from.h \
    vendor/libyuv/include/libyuv/convert_from_argb.h \
    vendor/libyuv/include/libyuv/cpu_id.h \
    vendor/libyuv/include/libyuv/mjpeg_decoder.h \
    vendor/libyuv/include/libyuv/planar_functions.h \
    vendor/libyuv/include/libyuv/rotate.h \
    vendor/libyuv/include/libyuv/rotate_argb.h \
    vendor/libyuv/include/libyuv/rotate_row.h \
    vendor/libyuv/include/libyuv/row.h \
    vendor/libyuv/include/libyuv/scale.h \
    vendor/libyuv/include/libyuv/scale_argb.h \
    vendor/libyuv/include/libyuv/scale_row.h \
    vendor/libyuv/include/libyuv/version.h \
    vendor/libyuv/include/libyuv/video_common.h

FORMS    += mainwindow.ui \
    cloudwaredialog.ui

INCLUDEPATH += /usr/local/include ./vendor/libyuv/include
INCLUDEPATH += ffmpeg/include


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib/release/ -lde265
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib/debug/ -lde265
else:unix: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lde265

INCLUDEPATH += $$PWD/../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../usr/local/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/Cellar/openh264/1.5.0/lib/release/ -lopenh264
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/Cellar/openh264/1.5.0/lib/debug/ -lopenh264
else:unix: LIBS += -L$$PWD/../../../../../usr/local/Cellar/openh264/1.5.0/lib/ -lopenh264

INCLUDEPATH += $$PWD/../../../../../usr/local/Cellar/openh264/1.5.0/include
DEPENDPATH += $$PWD/../../../../../usr/local/Cellar/openh264/1.5.0/include
