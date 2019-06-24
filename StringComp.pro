QT += core
CONFIG += c++11
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    main.cpp

HEADERS += \
    ColorLog.hpp \
    StringComp.hpp \
    Tester.hpp

OTHER_FILES += README.md \
    .clang-format \
    LICENSE
