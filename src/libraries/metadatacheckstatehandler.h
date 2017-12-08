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

#include <QHash>
#include <QModelIndex>

namespace Asn1Acn {
namespace Internal {
namespace Libraries {

class MetadataModel;

class MetadataCheckStateHandler
{
public:
    using States = QHash<QModelIndex, Qt::CheckState>;
    using Conflict = QPair<QString, QString>;

    MetadataCheckStateHandler(const MetadataModel *model);

    bool changeCheckStates(const QModelIndex &index, const Qt::CheckState state);

    States &changedIndexes();
    Conflict &conflict();

private:
    bool uncheck(const QModelIndex &index);
    bool check(const QModelIndex &index, const Qt::CheckState state);

    bool updateChildren(const QModelIndex &index, const Qt::CheckState state);
    bool updateParent(const QModelIndex &index, const Qt::CheckState childState);

    bool handleRelatives(const QModelIndex &index, const Qt::CheckState state);

    bool noConflicts(const QModelIndex &index);
    bool checkRequired(const QModelIndex &index, const Qt::CheckState state);

    QModelIndex findIndexByName(const QModelIndex &parent, const QString &name) const;
    Qt::CheckState parentState(const QModelIndex &index, const Qt::CheckState state) const;

    States m_changedIndexes;
    Conflict m_conflict;

    const MetadataModel *m_model;
};

} // namespace Libraries
} // namespace Internal
} // namespace Asn1Acn