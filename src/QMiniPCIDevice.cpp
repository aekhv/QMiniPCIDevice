/****************************************************************************
**
** This file is part of the QMiniPCIDevice library.
** Copyright (C) 2024 Alexander E. <aekhv@vk.com>
** License: GNU GPL v2, see file LICENSE.
**
****************************************************************************/

#include "QMiniPCIDevice.h"
#include <fcntl.h>      // open()
#include <unistd.h>     // write() & close()
#include <sys/ioctl.h>  // ioctl()
#include "minipci.h"

QMiniPCIDevice::QMiniPCIDevice()
    : m_fd(-1)
{
}

QMiniPCIDevice::~QMiniPCIDevice()
{
    close();
}

QStringList QMiniPCIDevice::availableDevices(const QString &pattern)
{
    QStringList list;
    QDir dir("/dev");
    dir.setNameFilters(QStringList() << pattern);
    foreach (const QString item, dir.entryList(QDir::System))
        list.append("/dev/" + item);
    return list;
}

bool QMiniPCIDevice::removeDevice(QMiniPCIDeviceLocation &location)
{
    const QString path = QString("/sys/bus/pci/devices/%1/remove")
            .arg(location.toString());
    int fd = ::open(path.toLocal8Bit().data(), O_WRONLY);
    if (fd >= 0) {
        const char c = '1';
        ::write(fd, &c, sizeof(c));
        ::close(fd);
        return true;
    } else
        return false;
}

bool QMiniPCIDevice::rescanPCIBus()
{
    int fd = ::open("/sys/bus/pci/rescan", O_WRONLY);
    if (fd >= 0) {
        const char c = '1';
        ::write(fd, &c, sizeof(c));
        ::close(fd);
        return true;
    } else
        return false;
}

bool QMiniPCIDevice::open(const QString &path)
{
    close();
    m_fd = ::open(path.toLocal8Bit().data(), O_RDWR);
    m_error = (m_fd >= 0)
            ? QMiniPCIError(QMiniPCIError::NoError)
            : QMiniPCIError(QMiniPCIError::DeviceOpeningError);
    return m_error.success();
}

void QMiniPCIDevice::close()
{
    if (m_fd >= 0) {
        ::close(m_fd);
        m_fd = -1;
        m_error = QMiniPCIError(QMiniPCIError::NoError);
    }
}

QMiniPCIDriverVersion QMiniPCIDevice::driverVersion()
{
    minipci_driver_version_t version;
    memset(&version, 0, sizeof(version));
    int err = ioctl(m_fd, MINIPCI_IOCTL_GET_DRIVER_VERSION, &version);
    if (err < 0)
        m_error = QMiniPCIError(QMiniPCIError::DeviceIoctlError);
    else
        m_error = QMiniPCIError(QMiniPCIError::NoError);
    return QMiniPCIDriverVersion(version);
}

QMiniPCIDeviceInfo QMiniPCIDevice::deviceInfo()
{
    minipci_device_info_t info;
    memset(&info, 0, sizeof(info));
    int err = ioctl(m_fd, MINIPCI_IOCTL_GET_DEVICE_INFO, &info);
    if (err < 0)
        m_error = QMiniPCIError(QMiniPCIError::DeviceIoctlError);
    else
        m_error = QMiniPCIError(QMiniPCIError::NoError);
    return QMiniPCIDeviceInfo(info);
}
