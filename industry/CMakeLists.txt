# industry header-only library

set( MODULE_NAME "industry" )
set( MODULE_NSPATH "industry" )

set( MODULE_ROOT ${CMAKE_CURRENT_SOURCE_DIR} )

set( MODULE_HEADERS "" )

# ===============================================
# ==== ${MODULE_ROOT}/${MODULE_NSPATH} group ====
# ===============================================
set(GROUP_HEADERS
    ${MODULE_ROOT}/include/${MODULE_NSPATH}/Factory.hpp
    ${MODULE_ROOT}/include/${MODULE_NSPATH}/Industry.hpp
    )
source_group( "${MODULE_NAME}\\${MODULE_NSPATH}"
    FILES ${GROUP_HEADERS}
    )
set( MODULE_HEADERS ${MODULE_HEADERS} ${GROUP_HEADERS} )


add_library( ${MODULE_NAME} INTERFACE )

target_compile_definitions( ${MODULE_NAME} INTERFACE
    LIBRARY_HEADER_ONLY
    )

target_include_directories( ${MODULE_NAME} INTERFACE
    $<BUILD_INTERFACE:${MODULE_ROOT}/include>
    $<INSTALL_INTERFACE:include>
    )

install(
    FILES ${MODULE_HEADERS}
    DESTINATION include/${MODULE_NSPATH}
    )

if ( BUILD_UT )
    add_subdirectory( ${MODULE_ROOT}/ut )
endif ( BUILD_UT )
