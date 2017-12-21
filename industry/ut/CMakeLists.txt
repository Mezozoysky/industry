set( MODULE_UT_TGT "${MODULE_NAME}-ut" )

set( MODULE_UT_ROOT ${CMAKE_CURRENT_SOURCE_DIR} )

set( MODULE_UT_HEADERS )
set( MODULE_UT_SOURCES )

# ===================================
# ==== ${MODULE_NAME}/ut group ====
# ===================================
set(GROUP_HEADERS
    ${MODULE_UT_ROOT}/HierarchyA.hpp
    )
set(GROUP_SOURCES
    ${MODULE_UT_ROOT}/main.cpp
	${MODULE_UT_ROOT}/tests_Factory.cpp
	${MODULE_UT_ROOT}/tests_Industry.cpp
    )
source_group( "${MODULE_NAME}\\ut" FILES ${GROUP_HEADERS} ${GROUP_SOURCES} )
set( MODULE_UT_HEADERS ${MODULE_UT_HEADERS} ${GROUP_HEADERS} )
set( MODULE_UT_SOURCES ${MODULE_UT_SOURCES} ${GROUP_SOURCES} )


#
# Build
#

include_directories(
    "${MODULE_ROOT}/include"
    "${Catch_INCLUDE_DIR}"
    )

add_executable( ${MODULE_UT_TGT} WIN32
    ${MODULE_UT_SOURCES}
    )

target_link_libraries( ${MODULE_UT_TGT}
    ${MODULE_TGT}
    )

install(
    TARGETS ${MODULE_UT_TGT}
	#RUNTIME DESTINATION share/${CMAKE_PROJECT_NAME}/ut/${MODULE_NAME}/
	RUNTIME DESTINATION share/${CMAKE_PROJECT_NAME}/ut/
    )
