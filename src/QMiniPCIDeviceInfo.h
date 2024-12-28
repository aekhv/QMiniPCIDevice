/****************************************************************************
**
** This file is part of the QMiniPCIDevice library.
** Copyright (C) 2024 Alexander E. <aekhv@vk.com>
** License: GNU GPL v2, see file LICENSE.
**
****************************************************************************/

#ifndef QMINIPCIDEVICEINFO_H
#define QMINIPCIDEVICEINFO_H

#include <QtCore>
#include "QMiniPCIDeviceLocation.h"
#include "QMiniPCIDeviceId.h"
#include "QMiniPCIDeviceLinkSpeed.h"

class QMiniPCIDeviceInfo
{
public:
    QMiniPCIDeviceInfo();
    QMiniPCIDeviceInfo(const minipci_device_info_t &info);

    QMiniPCIDeviceLocation location() const { return m_location; }
    QMiniPCIDeviceId id() const { return m_id; }
    QMiniPCIDeviceLinkSpeed link() const { return m_link; }

private:
    QMiniPCIDeviceLocation m_location;
    QMiniPCIDeviceId m_id;
    QMiniPCIDeviceLinkSpeed m_link;
};

#endif // QMINIPCIDEVICEINFO_H
