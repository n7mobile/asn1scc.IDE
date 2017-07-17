#############################################################################
##
## Copyright (C) 2017 N7 Mobile sp. z o. o.
## Contact: http://n7mobile.com/Space
##
## This file is part of ASN.1/ACN Plugin for QtCreator.
##
## Plugin was developed under a programme and funded by
## European Space Agency.
##
## This Plugin is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## This Plugin is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <http://www.gnu.org/licenses/>.
##
#############################################################################

# Qt Creator linking

IDE_SOURCE_TREE = $$QTC_SOURCE
isEmpty(IDE_SOURCE_TREE): IDE_SOURCE_TREE = "/opt/qt-creator-dev/qt-creator"

IDE_BUILD_TREE = $$QTC_BUILD
isEmpty(IDE_BUILD_TREE): IDE_BUILD_TREE = "/opt/qt-creator-dev/build-debug"

QTC_PLUGIN_NAME = Asn1Acn
QTC_LIB_DEPENDS += \
    utils

QTC_PLUGIN_DEPENDS += \
    texteditor \
    coreplugin \
    projectexplorer

QTC_PLUGIN_RECOMMENDS += \
    # optional plugin dependencies. nothing here at this time

include($$IDE_SOURCE_TREE/src/qtcreatorplugin.pri)

### Plugin ###

DEFINES += ASN1ACN_LIBRARY

# asn1acn plugin files

SOURCES += \
    asn1acn.cpp \
    asneditor.cpp \
    asndocument.cpp \
    asnautocompleter.cpp \
    asncompletionassist.cpp \
    outline.cpp \
    asnsnippetprovider.cpp \
    acneditor.cpp \
    acndocument.cpp \
    editor.cpp \
    overviewmodel.cpp \
    documentprocessor.cpp \
    parseddatastorage.cpp \
    parseddocument.cpp \
    structuresview.cpp \
    astxmlparser.cpp \
    modeltreenode.cpp \
    projectwatcher.cpp \
    overviewwidget.cpp \
    document.cpp \
    modeltree.cpp \
    asn1acnjsextension.cpp \
    asn1sccserviceprovider.cpp \
    parseddocumentbuilder.cpp \
    documentsourceinfo.cpp \
    projectcontenthandler.cpp \
    indenter.cpp \
    options-pages/general.cpp

HEADERS += \
    asn1acn_global.h \
    asn1acnconstants.h \
    asn1acn.h \
    asneditor.h \
    asndocument.h \
    asnautocompleter.h \
    asncompletionassist.h \
    outline.h \
    asnsnippetprovider.h \
    acneditor.h \
    acndocument.h \
    editor.h \
    overviewmodel.h \
    documentprocessor.h \
    parseddatastorage.h \
    parseddocument.h \
    structuresview.h \
    astxmlparser.h \
    data/sourcelocation.h \
    data/typeassignment.h \
    data/definitions.h \
    data/modules.h \
    modeltreenode.h \
    projectwatcher.h \
    overviewwidget.h \
    document.h \
    modeltree.h \
    asn1acnjsextension.h \
    asn1sccserviceprovider.h \
    parseddocumentbuilder.h \
    documentsourceinfo.h \
    projectcontenthandler.h \
    indenter.h \
    tr.h \
    options-pages/general.h

RESOURCES += \
    asn1acn.qrc

DISTFILES += \
    LICENSE \
    README.md

# test files

equals(TEST, 1) {

SOURCES += \
    tests/astxmlparser_tests.cpp

HEADERS += \
    tests/astxmlparser_tests.h

}

### Static files ###

STATIC_FILES += \
    snippets/asn.xml \
    generic-highlighter/asn1.xml \
    generic-highlighter/acn.xml \
    templates/wizards/files/acn/wizard.json \
    templates/wizards/files/acn/template.acn \
    templates/wizards/files/asn1/wizard.json \
    templates/wizards/files/asn1/template.asn

STATIC_BASE = $$PWD
STATIC_OUTPUT_BASE = $$IDE_DATA_PATH
STATIC_INSTALL_BASE = $$INSTALL_DATA_PATH

include($$IDE_SOURCE_TREE/qtcreatordata.pri)
