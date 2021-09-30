# CMakeList.txt: CMake-Projekt für "CMakeProject2". Schließen Sie die Quelle ein, und definieren Sie
# projektspezifische Logik hier.
#
cmake_minimum_required (VERSION 3.8)



# find includes in the corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# run moc automatically
set(CMAKE_AUTOMOC ON)
# if you're using Widgets and editing .ui forms in Designer
set(CMAKE_AUTOUIC ON)

message("Looking for Qt...")
# Qt modules (https://doc.qt.io/qt-5/qtmodules.html) you're using in your application
find_package(Qt5 REQUIRED Widgets)
if (${Qt5_FOUND})
    message("Found Qt " ${Qt5_VERSION})
else()
    message("Couldn't find Qt")
endif()
find_package(Qt5 COMPONENTS Widgets REQUIRED)


# Fügen Sie der ausführbaren Datei dieses Projekts eine Quelle hinzu.
add_executable (PersoPassGen "qtwidgetsapplication1.ui" "qtwidgetsapplication1.h" "qtwidgetsapplication1.cpp" "qtwidgetsapplication1.qrc" "stdafx.cpp" "stdafx.h" "PersoPassGen.cpp" "PersoPassGen.h")



# TODO: Fügen Sie bei Bedarf Tests hinzu, und installieren Sie Ziele.

if (MSVC)
    #do something
    message(STATUS ">>> MSVC")
    target_link_libraries(PersoPassGen crypt32.lib "C:\\Users\\user\\cpp\\PersoPassGen\\PersoPassGen\\lib\\workflowLibrary.lib" Qt5::Widgets)
endif (MSVC)

if (UNIX)
    #do something
    message(STATUS ">>> UNIX")
    target_link_libraries(PersoPassGen "/home/user/projects/workflowLibraryLinux/bin/x64/Release/libworkflowLibraryLinux.a" ssl crypto pthread Qt5::Widgets) 
endif (UNIX)


