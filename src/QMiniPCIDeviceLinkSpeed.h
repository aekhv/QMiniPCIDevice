/****************************************************************************
**
** This file is part of the QMiniPCIDevice library.
** Copyright (C) 2024 Alexander E. <aekhv@vk.com>
** License: GNU GPL v2, see file LICENSE.
**
****************************************************************************/

#ifndef QMINIPCIDEVICELINKSPEED_H
#define QMINIPCIDEVICELINKSPEED_H

#include <QtCore>
#include "minipci.h"

class QMiniPCIDeviceLinkSpeed
{
public:
    QMiniPCIDeviceLinkSpeed();
    QMiniPCIDeviceLinkSpeed(const minipci_device_link_t &link);

    int speed() const { return m_speed; }
    int width() const { return m_width; }

    QString toString() const;

private:
    int m_speed, m_width;
};

#endif // QMINIPCIDEVICELINKSPEED_H
