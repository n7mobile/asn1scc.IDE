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

#include "asnhighlighter.h"
#include <QTextDocument>

using namespace Asn1Acn::Internal;
using namespace TextEditor;

AsnHighlighter::AsnHighlighter(QTextDocument *document) :
    SyntaxHighlighter(document)
{
    static const QVector<TextStyle> categories({
        C_TYPE,
        C_COMMENT,
    });
    setTextFormatCategories(categories);

    QStringList keywords;
    keywords << "\\bSEQUENCE OF\\b"
             << "\\bCHOICE\\b"
             << "\\bSEQUENCE\\b"
             << "\\bOPTIONAL\\b"
             << "\\bOCTET STRING\\b"
             << "\\bENUMERATED\\b"
             << "\\bBIT STRING\\b"
             << "\\bBOOLEAN\\b"
             << "\\bINTEGER\\b"
             << "\\bIA5String\\b"
             << "\\bNULL\\b";

    foreach (const QString &pattern, keywords)
        m_keywordPatterns.append(QRegularExpression(pattern));

    m_commentPattern.setPattern("--");
}

void AsnHighlighter::highlightBlock(const QString &text)
{
    foreach (const QRegularExpression &pattern, m_keywordPatterns) {
        int offset = 0;
        while (offset < text.size()) {
            QRegularExpressionMatch regExpMatch = pattern.match(text, offset);

            if (!regExpMatch.hasMatch())
                break;

            setFormat(regExpMatch.capturedStart(), regExpMatch.capturedLength(),
                      formatForCategory(AsnTypeFormat));
            offset = regExpMatch.capturedEnd();
        }
    }

    int ret = 0;
    do {
        ret = highlightComment(text, ret);
    } while (ret != 0);
}

int AsnHighlighter::highlightComment(const QString &text, int offset)
{
    /**
     * This function shall return 0 in case no more comments are expected, or
     * offset of the first character after the end of the code block newly highlighted as comment.
     **/

    QRegularExpressionMatch beginComment = m_commentPattern.match(text, offset);
    if (!beginComment.hasMatch())
        return 0;

    QRegularExpressionMatch endComment = m_commentPattern.match(text,
                                                                beginComment.capturedEnd());
    if (!endComment.hasMatch()) {
        setFormat(beginComment.capturedStart(),
                  text.length() - beginComment.capturedStart(),
                  formatForCategory(AsnCommentFormat));
        return 0;
    }

    setFormat(beginComment.capturedStart(),
              endComment.capturedEnd() - beginComment.capturedStart(),
              formatForCategory(AsnCommentFormat));

    return endComment.capturedEnd();
}
