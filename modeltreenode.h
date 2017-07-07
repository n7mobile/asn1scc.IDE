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

#pragma once

#include <memory>

#include <QString>
#include <QVariant>
#include <QList>

#include "data/sourcelocation.h"

namespace Asn1Acn {
namespace Internal {

class ModelTreeNode
{
public:

    using ModelTreeNodePtr = std::shared_ptr<ModelTreeNode>;

    ModelTreeNode() = default;
    ModelTreeNode(const QString &id, const Data::SourceLocation location = Data::SourceLocation());

    int childrenCount() const;

    ModelTreeNodePtr childAt(int idx) const;
    ModelTreeNodePtr getChildByName(const QString &name) const;

    void addChild(ModelTreeNodePtr child);

    void removeChildByName(const QString &name);
    void removeChildren();

    QVariant data() const;
    QString id() const;
    const ModelTreeNode *parent() const;

    int columnCount() const;
    int row() const;

    const Data::SourceLocation &getSourceLocation() const;

private:
    QString m_id;

    ModelTreeNode *m_parent;
    QList<ModelTreeNodePtr> m_children;

    const Data::SourceLocation m_location;
};

} // namespace Internal
} // namespace Asn1Acn
