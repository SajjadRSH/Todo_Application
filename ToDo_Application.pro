#-------------------------------------------------
#
# Project created by QtCreator 2022-06-05T17:55:00
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ToDo_Application
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        calender_window.cpp \
        edit_of_task.cpp \
        inputs_of_task.cpp \
        main.cpp \
        selection_tasks_calender_window.cpp \
        selectyearmonth_toshowcalender_window.cpp \
        sign_in_window.cpp \
        tasks_window.cpp

HEADERS += \
        calender_window.h \
        edit_of_task.h \
        inputs_of_task.h \
        selection_tasks_calender_window.h \
        selectyearmonth_toshowcalender_window.h \
        sign_in_window.h \
        tasks_window.h

FORMS += \
        calender_window.ui \
        edit_of_task.ui \
        inputs_of_task.ui \
        selection_tasks_calender_window.ui \
        selectyearmonth_toshowcalender_window.ui \
        sign_in_window.ui \
        tasks_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
