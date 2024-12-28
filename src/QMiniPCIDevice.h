/****************************************************************************
**
** This file is part of the QMiniPCIDevice library.
** Copyright (C) 2024 Alexander E. <aekhv@vk.com>
** License: GNU GPL v2, see file LICENSE.
**
****************************************************************************/

#ifndef QMINIPCIDEVICE_H
#define QMINIPCIDEVICE_H

#include <QtCore>
#include "QMiniPCIError.h"
#include "QMiniPCIDriverVersion.h"
#include "QMiniPCIDeviceInfo.h"

class QMiniPCIDevice
{
public:
    QMiniPCIDevice();
    ~QMiniPCIDevice();

    static QStringList availableDevices(const QString &pattern);
    static bool removeDevice(QMiniPCIDeviceLocation &location);
    static bool rescanPCIBus();

    bool open(const QString &path);
    void close();
    int fd() { return m_fd; }
    bool isOpened() { return m_fd >= 0; }
    void setLastError(QMiniPCIError error) { m_error = error; }
    QMiniPCIError lastError() const { return m_error; }
    QMiniPCIDriverVersion driverVersion();
    QMiniPCIDeviceInfo deviceInfo();

private:
    int m_fd; // file descriptor
    QMiniPCIError m_error;
};

#endif // QMINIPCIDEVICE_H
