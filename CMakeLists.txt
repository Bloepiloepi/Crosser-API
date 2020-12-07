cmake_minimum_required(VERSION 3.17)
project(CrosserAPI VERSION 0.4)

set(CMAKE_CXX_STANDARD 17)

set(DEFAULT_BUILD_TYPE "Release")

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to '${DEFAULT_BUILD_TYPE}' as none was specified.")
    set(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}" CACHE STRING "Choose the type of build." FORCE)
endif()

include(GNUInstallDirs)

set(SOURCE_FILES src/events.cpp src/location.cpp)

add_library(CrosserAPI ${SOURCE_FILES})

target_include_directories(CrosserAPI PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE src)

set_target_properties(CrosserAPI PROPERTIES
        VERSION ${PROJECT_VERSION})

install(TARGETS CrosserAPI EXPORT CrosserAPIConfig
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(DIRECTORY include/ DESTINATION
        ${CMAKE_INSTALL_INCLUDEDIR}/CrosserAPI)

install(EXPORT CrosserAPIConfig DESTINATION share/CrosserAPI/cmake)

export(TARGETS CrosserAPI FILE CrosserAPIConfig.cmake)