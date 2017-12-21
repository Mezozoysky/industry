cmake_minimum_required( VERSION 3.1.0 )

set( CMAKE_BUILD_TYPE "Debug" CACHE STRING "Project build type" )
set( CMAKE_INSTALL_PREFIX "/usr/local" CACHE PATH "Install prefix. Use something like '/usr/local' for system-wide installation." )
set( EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin" )
set( LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib" )
set( CMAKE_MACOSX_RPATH ON )
set( CMAKE_VERBOSE_MAKEFILE ON )


set_property( GLOBAL PROPERTY USE_FOLDERS ON )
set_property( GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake" )
list( APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules" )

#
# Third-party config vars
#
if( "$ENV{CATCH_HOME}" STREQUAL "" )
    set( ENV{CATCH_HOME} "${CMAKE_SOURCE_DIR}/deps/Catch/" )
endif()
set( Catch_HOME $ENV{CATCH_HOME} CACHE PATH "Path to Catch" )

#
# Project
#
project( industry C CXX )

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD_REQURED ON )


option( BUILD_UT "Build unit-tests"  ON )
find_package( Doxygen )
option( BUILD_DOCS "Build the HTML based documentation (requires Doxygen)" ${DOXYGEN_FOUND} )



if ( ${CMAKE_SYSTEM_NAME} MATCHES "Linux" )
    set( HOST_OS_LINUX TRUE )
elseif ( ${CMAKE_SYSTEM_NAME} MATCHES "Darwin" )
    set( HOST_OS_OSX TRUE )
elseif ( ${CMAKE_SYSTEM_NAME} MATCHES "Windows" )
    set( HOST_OS_WINDOWS TRUE )
else ()
    set( HOST_OS_UNKNOWN )
    message( WARNING "UNKNOWN HOST OS! Let us hope for the best!" )
endif ()

message( "System name: ${CMAKE_SYSTEM_NAME}" )
message( "System version: ${CMAKE_SYSTEM_VERSION}" )

message( "Compiler name: ${CMAKE_CXX_COMPILER_ID}" )
message( "Compiler version: ${CMAKE_CXX_COMPILER_VERSION}" )

if ( BUILD_UT )
    set( Catch_USE_SINGLE_INCLUDE TRUE )
    find_package( Catch REQUIRED )
endif ( BUILD_UT )

#
# Modules
#
add_subdirectory( "industry" )
if ( BUILD_DOCS )
    add_subdirectory( "doc" )
endif()
