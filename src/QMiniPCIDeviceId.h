/****************************************************************************
**
** This file is part of the QMiniPCIDevice library.
** Copyright (C) 2024 Alexander E. <aekhv@vk.com>
** License: GNU GPL v2, see file LICENSE.
**
****************************************************************************/

#ifndef QMINIPCIDEVICEID_H
#define QMINIPCIDEVICEID_H

#include <QtCore>
#include "minipci.h"

class QMiniPCIDeviceId
{
public:
    QMiniPCIDeviceId();
    QMiniPCIDeviceId(const minipci_device_id_t &id);

    quint16 vendorId() const { return m_vendorId; }
    quint16 deviceId() const { return m_deviceId; }
    quint16 classId() const { return m_classId; }
    quint8 revision() const { return m_revision; }

    QString toString() const;

private:
    quint16 m_vendorId, m_deviceId, m_classId;
    quint8 m_revision;
};

#endif // QMINIPCIDEVICEID_H
