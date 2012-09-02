TEMPLATE = subdirs
CONFIG += ordered
SUBDIRS = src

demos:SUBDIRS += demos
examples:SUBDIRS += examples
lessThan(QT_MAJOR_VERSION, 5) {
tests:SUBDIRS += tests
}

isEmpty(Q_COMPONENTS_SOURCE_TREE)|isEmpty(Q_COMPONENTS_BUILD_TREE) {
    error(Please run configure.)
}

features.files += $$Q_COMPONENTS_SOURCE_TREE/features/qmluiextensions.prf
features.files += $$Q_COMPONENTS_BUILD_TREE/features/qmluiextensions-config.prf
features.path = $$[QMAKE_MKSPECS]/features
INSTALLS += features

symbian {
    features.path ~= s/^[A-Za-z]:/ # strip drive letter
    BLD_INF_RULES.prj_exports += "features/qmluiextensions.prf $$features.path/qmluiextensions.prf"
    BLD_INF_RULES.prj_exports += "features/qmluiextensions-config.prf $$features.path/qmluiextensions-config.prf"
}

include(doc/doc.pri)
