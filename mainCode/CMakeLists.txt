cmake_minimum_required(VERSION 3.5)

project(mainCode VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

set(TS_FILES mainCode_zh_CN.ts)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui

        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui

        login.h
        login.cpp
        login.ui

        register.h
        register.cpp
        register.ui

        mainwindow2.h
        mainwindow2.cpp
        mainwindow2.ui

        accountdetail.h
        accountdetail.cpp
        accountdetail.ui

        accountcontrol.h
        accountcontrol.cpp
        accountcontrol.ui

        preference.h
        preference.cpp
        preference.ui

        balance.h
        balance.cpp
        balance.ui

        orderinfo.h
        orderinfo.cpp
        orderinfo.ui

        productsearch.h
        productsearch.cpp
        productsearch.ui

        shoppingcart.h
        shoppingcart.cpp
        shoppingcart.ui

        paypage.h
        paypage.cpp
        paypage.ui

        productinfo.h
        productinfo.cpp
        productinfo.ui

        accountcontroladmin.h
        accountcontroladmin.cpp
        accountcontroladmin.ui

        orderinfoadmin.h
        orderinfoadmin.cpp
        orderinfoadmin.ui

        productsearchadmin.h
        productsearchadmin.cpp
        productsearchadmin.ui

        addproduct.h
        addproduct.cpp
        addproduct.ui

        mainwindow2admin.cpp
        mainwindow2admin.h
        mainwindow2admin.ui
        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(mainCode
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET mainCode APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(mainCode SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(mainCode
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(mainCode PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(mainCode PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS mainCode
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(mainCode)
endif()
