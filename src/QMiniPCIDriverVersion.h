/****************************************************************************
**
** This file is part of the QMiniPCIDevice library.
** Copyright (C) 2024 Alexander E. <aekhv@vk.com>
** License: GNU GPL v2, see file LICENSE.
**
****************************************************************************/

#ifndef QMINIPCIDRIVERVERSION_H
#define QMINIPCIDRIVERVERSION_H

#include <QtCore>
#include "minipci.h"

class QMiniPCIDriverVersion
{
public:
    QMiniPCIDriverVersion();
    QMiniPCIDriverVersion(const minipci_driver_version_t &version);

    int major() const { return m_major; }
    int minor() const { return m_minor; }
    int patch() const { return m_patch; }

    QString toString() const;

private:
    int m_major, m_minor, m_patch;
};

#endif // QMINIPCIDRIVERVERSION_H
