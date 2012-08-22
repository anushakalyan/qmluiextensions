TEMPLATE = subdirs
SUBDIRS = components
    SUBDIRS += meego
SUBDIRS += meego/extras
meego {
    SUBDIRS += meego
    extras:SUBDIRS += meego/extras
}

symbian3 {
    SUBDIRS += symbian
    extras:SUBDIRS += symbian/extras
}
