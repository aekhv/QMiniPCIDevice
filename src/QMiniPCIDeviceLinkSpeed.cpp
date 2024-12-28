/****************************************************************************
**
** This file is part of the QMiniPCIDevice library.
** Copyright (C) 2024 Alexander E. <aekhv@vk.com>
** License: GNU GPL v2, see file LICENSE.
**
****************************************************************************/

#include "QMiniPCIDeviceLinkSpeed.h"
#include <QtCore>

QMiniPCIDeviceLinkSpeed::QMiniPCIDeviceLinkSpeed()
    : m_speed(0),
      m_width(0)
{

}

QMiniPCIDeviceLinkSpeed::QMiniPCIDeviceLinkSpeed(const minipci_device_link_t &link)
{
    m_speed = link.speed;
    m_width = link.width;
}

QString QMiniPCIDeviceLinkSpeed::toString() const
{
    return QString("Gen.%1 x %2")
            .arg(m_speed)
            .arg(m_width);
}
