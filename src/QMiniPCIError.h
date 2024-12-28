/****************************************************************************
**
** This file is part of the QMiniPCIDevice library.
** Copyright (C) 2024 Alexander E. <aekhv@vk.com>
** License: GNU GPL v2, see file LICENSE.
**
****************************************************************************/

#ifndef QMINIPCIERROR_H
#define QMINIPCIERROR_H

#include <QtCore>

class QMiniPCIError
{
public:
    enum ErrorType {
        NoError,
        DeviceOpeningError, // device opening error
        DeviceIoctlError,   // ioctl error
        DeviceTimeout,      // a command sent, but no response
        DeviceError,        // a command sent, but error received
        UnknownError
    };

    QMiniPCIError(ErrorType type = NoError);

    bool success() const { return m_type == NoError; }
    ErrorType type() const { return m_type; }

    QString toString() const;

private:
    ErrorType m_type;
};

#endif // QMINIPCIERROR_H
