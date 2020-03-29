cmake_minimum_required(VERSION 3.2)

set(PLUGIN_NAME "mds_io")
set(INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/include")

set(INCLUDE_DIRS "${INCLUDE_DIRS};${CMAKE_CURRENT_SOURCE_DIR}/src")

file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c*")

set(DEPENDENCIES "rtf_model" "rtf_selectors" "MdsLib" "MdsShr" "c")
include_directories(/usr/local/mdsplus/include)
link_directories("/usr/local/mdsplus/lib")

create_plugin("${PLUGIN_NAME}" "${SOURCES}" "${INCLUDES}" "${DEPENDENCIES}")
