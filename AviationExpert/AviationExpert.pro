TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    distancedb.cpp \
    iatadb.cpp \
        main.cpp \
    distance.cpp \
    iata.cpp \
    schedule.cpp \
    scheduledb.cpp \
    time.cpp

HEADERS += \
    distance.h \
    distancedb.h \
    iata.h \
    iatadb.h \
    schedule.h \
    scheduledb.h \
    time.h
