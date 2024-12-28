/****************************************************************************
**
** This file is part of the QMiniPCIDevice library.
** Copyright (C) 2024 Alexander E. <aekhv@vk.com>
** License: GNU GPL v2, see file LICENSE.
**
****************************************************************************/

#include "QMiniPCIError.h"

QMiniPCIError::QMiniPCIError(ErrorType type)
    : m_type(type)
{

}

QString QMiniPCIError::toString() const
{
    switch (m_type) {
    case NoError:
        return "No error";
    case DeviceOpeningError:
        return "Device opening error";
    case DeviceIoctlError:
        return "Device IOCTL error";
    case DeviceTimeout:
        return "Device timeout";
    case DeviceError:
        return "Device error";
    default:
        return "Unknown error";
    }
}
