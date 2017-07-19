/****************************************************************************
**
** Copyright (C) 2017 N7 Mobile sp. z o. o.
** Contact: http://n7mobile.com/Space
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
#include "general.h"

#include <QWidget>

#include "../asn1acnconstants.h"
#include "../tr.h"

using namespace Asn1Acn::Internal::OptionsPages;

General::General(Settings::GeneralPtr settings)
    : m_settings(settings)
{
    setId(Constants::GENERAL_SETTINGS_ID);
    setDisplayName(Tr::tr("General"));
    setCategory(Constants::SETTINGS_CATEGORY);
    setDisplayCategory(Tr::tr("ASN.1/ACN"));
    setCategoryIcon(Utils::Icon(Constants::OPTIONS_CATEGORY_ICON));
}

bool General::matches(const QString &searchKeyWord) const
{
    // TODO - additional keywords?
    return Core::IOptionsPage::matches(searchKeyWord);
}

QWidget* General::widget()
{
    auto w = new QWidget();//nullptr; // TODO
    m_ui.setupUi(w);
    return w;
}

void General::apply()
{
    // TODO
    Settings::save(m_settings);
}

void General::finish()
{
    // TODO
}
