cmake_minimum_required(VERSION 3.28)
project(AOE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(AOE main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        qcanvas.cpp
        qcanvas.h
        Shape.cpp
        Shape.h
        Line.cpp
        Line.h
        Dialog.cpp
        Dialog.h
        AOE.cpp
        AOE.h
)
target_link_libraries(AOE
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

