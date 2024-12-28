/****************************************************************************
**
** This file is part of the QMiniPCIDevice library.
** Copyright (C) 2024 Alexander E. <aekhv@vk.com>
** License: GNU GPL v2, see file LICENSE.
**
****************************************************************************/

#include "QMiniPCIDeviceInfo.h"

QMiniPCIDeviceInfo::QMiniPCIDeviceInfo()
{

}

QMiniPCIDeviceInfo::QMiniPCIDeviceInfo(const minipci_device_info_t &info)
    : m_location(info.location),
      m_id(info.id),
      m_link(info.link)
{

}
