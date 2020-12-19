cmake_minimum_required(VERSION 3.17)
project(CrosserAPI VERSION 1.2 DESCRIPTION "The API for Crosser.")

set(CMAKE_CXX_STANDARD 17)

set(DEFAULT_BUILD_TYPE "Release")

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to '${DEFAULT_BUILD_TYPE}' as none was specified.")
    set(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}" CACHE STRING "Choose the type of build." FORCE)
endif()

include(GNUInstallDirs)

set(SOURCE_FILES src/events.cpp src/location.cpp src/logger.cpp src/IGame.cpp)
add_library(CrosserAPI ${SOURCE_FILES})

#SFML Part
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)
target_link_libraries(CrosserAPI PUBLIC sfml-graphics sfml-window sfml-system)
#End SFML Part

target_include_directories(CrosserAPI PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE src)

set_target_properties(CrosserAPI PROPERTIES
        VERSION ${PROJECT_VERSION})
set_target_properties(CrosserAPI PROPERTIES
        DESCRIPTION ${PROJECT_DESCRIPTION})

configure_file(CrosserAPI.pc.in CrosserAPI.pc @ONLY)

install(TARGETS CrosserAPI EXPORT CrosserAPIConfig
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(DIRECTORY include/ DESTINATION
        ${CMAKE_INSTALL_INCLUDEDIR}/CrosserAPI)
install(FILES ${CMAKE_BINARY_DIR}/CrosserAPI.pc
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

install(EXPORT CrosserAPIConfig DESTINATION share/CrosserAPI/cmake)

export(TARGETS CrosserAPI FILE CrosserAPIConfig.cmake)