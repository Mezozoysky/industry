# FindIndustry
# Module: locating Industry library with cmake
# Author: Stanislav Demyanovich <mezozoysky@gmail.com>
#
# Usage:
#	set( Industry_HOME /path/to/Industry )
#	find_package( Industry REQUIRED )
#
# Defines:
# Industry_INCLUDE_DIR	   path to Industry includes or single include
# Industry_FOUND		   true if susa includes or single include were found

set( Industry_LOCATION_PREFIX_HINTS
    "${Industry_HOME}"
	"$ENV{INDUSTRY_HOME}"
    /usr/local
)

set( Industry_FIND_NAMES "include/industry/Industry.hpp" )

if( NOT Industry_LOCATION_PREFIX )
    find_path( Industry_LOCATION_PREFIX
        NAMES ${Industry_FIND_NAMES}
        HINTS ${Industry_LOCATION_PREFIX_HINTS}
        DOC "Top-level directory"
    )
endif()

if( NOT Industry_LOCATION_PREFIX )
    if( Industry_FIND_REQUIRED )
        message( STATUS "HINTS: ${Industry_LOCATION_PREFIX_HINTS}" )
        message( STATUS "NAMES: ${Industry_FIND_NAMES}" )
        message( STATUS "PREFIX: ${Industry_LOCATION_PREFIX}" )
        message( FATAL_ERROR "Cant find Industry location" )
    endif()
    if( NOT Industry_FIND_QUIETLY )
        message( STATUS "Cant find Industry location" )
    endif()
    return()
else()
    message( STATUS "Found Industry location prefix: ${Industry_LOCATION_PREFIX}" )
endif()

set( Industry_INCLUDE_DIR ${Industry_LOCATION_PREFIX}/include CACHE PATH "Path to Industry includes" )
message( STATUS "Found Industry include dir: ${Industry_INCLUDE_DIR}" )

if( Industry_INCLUDE_DIR )
    set( Industry_FOUND TRUE )
endif()
