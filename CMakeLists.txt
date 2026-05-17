cmake_minimum_required(VERSION 3.19)
project(hotelManagementQt LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(hotelManagementQt
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    room.h room.cpp
    hotel.h hotel.cpp
)

qt_add_resources(hotelManagementQt "resources"
    PREFIX "/"
    FILES
        images/hotel.png
)

target_link_libraries(hotelManagementQt
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS hotelManagementQt
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET hotelManagementQt
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
