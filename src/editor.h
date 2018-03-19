/****************************************************************************
**
** Copyright (C) 2017 N7 Space sp. z o. o.
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
#pragma once

#include <texteditor/texteditor.h>

#include <utils/uncommentselection.h>

namespace Asn1Acn {
namespace Internal {

class EditorOutline;

class EditorWidget : public TextEditor::TextEditorWidget
{
    Q_OBJECT

public:
    virtual void findUsages() = 0;

protected:
    void openFinishedSuccessfully() override;

    void finalizeInitialization() override;
    void finalizeInitializationAfterDuplication(TextEditorWidget *other) override;

    void mouseDoubleClickEvent(QMouseEvent *e) override;
    void contextMenuEvent(QContextMenuEvent *) override;

    Utils::CommentDefinition m_commentDefinition;

private slots:
    void onExtraSelectionsUpdated(const QList<QTextEdit::ExtraSelection> &selections);

private:
    void addOutlineCombo();
};

} // namespace Internal
} // namespace Asn1Acn
