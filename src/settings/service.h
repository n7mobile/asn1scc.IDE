/****************************************************************************
**
** Copyright (C) 2017 N7 Mobile sp. z o. o.
** Contact: http://n7mobile.pl/Space
**
** This file is part of ASN.1/ACN Plugin for QtCreator.
**
** Plugin was developed under a programme and funded by
** European Space Agency.
**
** This Plugin is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This Plugin is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

#pragma once

#include <memory>

#include <QString>

#include "settings.h"

namespace Asn1Acn {
namespace Internal {
namespace Settings {

class Service : public Settings
{
    Q_OBJECT
public:
    Service() = default;
    virtual ~Service();

    QString name() const override;

    const QString &baseUri() const { return m_baseUri; }
    void setBaseUri(const QString &uri) { m_baseUri = uri; }

    const QString &path() const { return m_path; }
    void setPath(const QString &p) { m_path = p; }

    int stayAlivePeriod() const { return m_stayAlivePeriod; }
    void setStayAlivePeriod(int p) { m_stayAlivePeriod = p; }

    bool watchdogDisabled() const { return m_watchdogDisabled; }
    void setWatchdogDisabled(bool disabled) { m_watchdogDisabled = disabled; }

private:
    void saveOptionsTo(QSettings *s) const override;
    void loadOptionsFrom(QSettings *s) override;

    QString m_baseUri;
    QString m_path;
    int m_stayAlivePeriod;

    bool m_watchdogDisabled;
};

using ServicePtr = std::shared_ptr<Service>;
using ServiceConstPtr = std::shared_ptr<const Service>;

} // namespace Settings
} // namespace Internal
} // namespace Asn1Acn
