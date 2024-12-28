QT -= gui

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    QMiniPCIDevice.cpp \
    QMiniPCIDeviceId.cpp \
    QMiniPCIDeviceInfo.cpp \
    QMiniPCIDeviceLinkSpeed.cpp \
    QMiniPCIDeviceLocation.cpp \
    QMiniPCIDriverVersion.cpp \
    QMiniPCIError.cpp

HEADERS += \
    QMiniPCIDevice.h \
    QMiniPCIDeviceId.h \
    QMiniPCIDeviceInfo.h \
    QMiniPCIDeviceLinkSpeed.h \
    QMiniPCIDeviceLocation.h \
    QMiniPCIDriverVersion.h \
    QMiniPCIError.h \
    minipci.h

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target
