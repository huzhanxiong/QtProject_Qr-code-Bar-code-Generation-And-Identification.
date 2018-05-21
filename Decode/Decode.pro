#-------------------------------------------------
#
# Project created by QtCreator 2018-02-23T17:52:30
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Decode
TEMPLATE = app

LIBS += -LE:\Qt_MSVC\test\Decode\Decode\lib \
        -llibzint \
        -lQZXing2


SOURCES += main.cpp\
        mainwindow.cpp \
    qr_widget.cpp \
    libdmtx/dmtx.c \
    libdmtx/dmtxbytelist.c \
    libdmtx/dmtxdecode.c \
    libdmtx/dmtxdecodescheme.c \
    libdmtx/dmtxencode.c \
    libdmtx/dmtxencodeascii.c \
    libdmtx/dmtxencodebase256.c \
    libdmtx/dmtxencodec40textx12.c \
    libdmtx/dmtxencodeedifact.c \
    libdmtx/dmtxencodeoptimize.c \
    libdmtx/dmtxencodescheme.c \
    libdmtx/dmtxencodestream.c \
    libdmtx/dmtximage.c \
    libdmtx/dmtxmatrix3.c \
    libdmtx/dmtxmessage.c \
    libdmtx/dmtxplacemod.c \
    libdmtx/dmtxreedsol.c \
    libdmtx/dmtxregion.c \
    libdmtx/dmtxscangrid.c \
    libdmtx/dmtxsymbol.c \
    libdmtx/dmtxtime.c \
    libdmtx/dmtxvector2.c




HEADERS  += mainwindow.h \
    qr_widget.h \
    libdmtx/dmtx.h \
    libdmtx/dmtxstatic.h


FORMS    += mainwindow.ui


RESOURCES += \
    image.qrc
