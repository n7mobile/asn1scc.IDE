/****************************************************************************
**
** Copyright (C) 2018 N7 Space sp. z o. o.
** Contact: http://n7space.com
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

#include "testgeneratorparamsprovider.h"

#include <projectexplorer/target.h>

#include "kitinformation.h"

using namespace Asn1Acn::Internal;
using namespace Asn1Acn::Internal::TestGenerator;

TestGeneratorParamsProvider::TestGeneratorParamsProvider(Settings::TestGeneratorConstPtr settings)
    : m_settings(settings)
{}

void TestGeneratorParamsProvider::setMainStructureName(const QString &name)
{
    m_mainStructureName = name;
}

void TestGeneratorParamsProvider::setOutputPath(const QString &path)
{
    m_outputPath = path;
}

QString TestGeneratorParamsProvider::asn1sccPath(const ProjectExplorer::Target *target) const
{
    return KitInformation::hasAsn1Exe(target->kit())
               ? KitInformation::asn1Exe(target->kit()).toString()
               : QString();
}

QString TestGeneratorParamsProvider::testGeneratorPath() const
{
    return m_settings->path();
}

QString TestGeneratorParamsProvider::outputPath() const
{
    return m_outputPath;
}

QString TestGeneratorParamsProvider::mainStructureName() const
{
    return m_mainStructureName;
}

QString TestGeneratorParamsProvider::asn1acnFiles() const
{
    return {};
}