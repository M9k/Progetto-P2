#-------------------------------------------------
#
# Project created by QtCreator 2016-12-07T23:08:00
#
#-------------------------------------------------

QT += core gui
QT += widgets

TARGET = progetto
TEMPLATE = app
CONFIG += c++11
CONFIG += qt
QMAKE_CXXFLAGS += -std=c++11
RESOURCES = resource.qrc

SOURCES += MODEL/implementation/file_audio.cpp \
    MODEL/implementation/file_audiovideo.cpp \
    MODEL/implementation/file_multimedia.cpp \
    MODEL/implementation/file_raw.cpp \
    MODEL/implementation/file_video.cpp \
    MODEL/implementation/listUser.cpp \
    MODEL/implementation/size_of_file.cpp \
    MODEL/implementation/user.cpp \
    MODEL/implementation/user_admin.cpp \
    MODEL/implementation/user_editor.cpp \
    MODEL/implementation/user_moderator.cpp \
    MODEL/implementation/user_standard.cpp \
    GUI/implementation/login.cpp \
    GUI/implementation/main_dialog.cpp \
    main.cpp \
    MODEL/implementation/listFile.cpp \
    GUI/implementation/status_bar.cpp \
    GUI/implementation/admin_dialog.cpp \
    MODEL/implementation/common_functions.cpp \
    GUI/implementation/main_widget.cpp \
    GUI/implementation/admin_widget.cpp \
    GUI/implementation/admin_buttons.cpp \
    GUI/implementation/admin_list_users.cpp \
    MODEL/implementation/file_text.cpp \
    MODEL/implementation/file_plain_text.cpp \
    MODEL/implementation/file_epub.cpp \
    GUI/implementation/addeditfile.cpp \
    MODEL/implementation/file_base.cpp \
    GUI/implementation/view_file_base.cpp \
    GUI/implementation/factory_addedit_view.cpp \
    MODEL/implementation/factoryfile.cpp \
    GUI/implementation/view_file_text.cpp \
    GUI/implementation/view_file_epub.cpp \
    GUI/implementation/view_file_multimedia.cpp \
    GUI/implementation/view_file_audio.cpp \
    GUI/implementation/view_file_video.cpp \
    GUI/implementation/view_file_audiovideo.cpp

HEADERS  += MODEL/header/color_file.h \
    MODEL/header/file_audio.h \
    MODEL/header/file_audiovideo.h \
    MODEL/header/file_multimedia.h \
    MODEL/header/file_raw.h \
    MODEL/header/file_video.h \
    MODEL/header/mylist.h \
    MODEL/header/listUser.h \
    MODEL/header/size_of_file.h \
    MODEL/header/user.h \
    MODEL/header/user_admin.h \
    MODEL/header/user_editor.h \
    MODEL/header/user_moderator.h \
    MODEL/header/user_standard.h \
    GUI/header/login.h \
    GUI/header/main_dialog.h \
    MODEL/header/listFile.h \
    GUI/header/status_bar.h \
    GUI/header/admin_dialog.h \
    GUI/header/main_widget.h \
    MODEL/header/common_functions.h \
    GUI/header/admin_widget.h \
    GUI/header/admin_buttons.h \
    GUI/header/admin_list_users.h \
    MODEL/header/file_text.h \
    MODEL/header/file_plain_text.h \
    MODEL/header/file_epub.h \
    GUI/header/addeditfile.h \
    MODEL/header/factoryfile.h \
    MODEL/header/file_base.h \
    GUI/header/view_file_base.h \
    GUI/header/factory_addedit_view.h \
    GUI/header/view_file_raw.h \
    GUI/header/view_file_text.h \
    GUI/header/view_file_plain_text.h \
    GUI/header/view_file_epub.h \
    GUI/header/view_file_multimedia.h \
    GUI/header/view_file_audio.h \
    GUI/header/view_file_video.h \
    GUI/header/view_file_audiovideo.h
