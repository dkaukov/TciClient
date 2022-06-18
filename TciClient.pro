QT += core websockets qml

QML_IMPORT_NAME = com.expertelectronics.tci
QML_IMPORT_MAJOR_VERSION = 1

TEMPLATE = lib

INCLUDEPATH += $$PWD
DEPENDPATH  += $$PWD

HEADERS += $$PWD/tciclient.h \
    $$PWD/TciTrxState/TciTrxState.h \
    $$PWD/TciParser/TciCommand.h \
    $$PWD/TciParser/TciParser.h \
    $$PWD/TciParser/TciParserAbstract.h \
    $$PWD/TciParser/TciParserCommandAbsract.h
SOURCES += $$PWD/tciclient.cpp \
    $$PWD/TciTrxState/TciTrxState.cpp \
    $$PWD/TciParser/TciCommand.cpp \
    $$PWD/TciParser/TciParser.cpp



