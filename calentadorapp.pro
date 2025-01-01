QT += core gui

CONFIG += c++17

# Incluir la configuración para la compilación de Qt
CONFIG += moc

SOURCES += src/main.cpp

HEADERS +=
FORMS +=

# Incluir directorios de encabezados de Qt
INCLUDEPATH += /usr/include/x86_64-linux-gnu/qt5
INCLUDEPATH += /usr/include/x86_64-linux-gnu/qt5/QtCore
INCLUDEPATH += /usr/include/x86_64-linux-gnu/qt5/QtGui
INCLUDEPATH += /usr/include/x86_64-linux-gnu/qt5/QtWidgets

# Enlazar las bibliotecas de Qt necesarias
LIBS += -L/usr/lib/x86_64-linux-gnu -lQt5Core -lQt5Gui -lQt5Widgets
