cmake_minimum_required(VERSION 3.2)


set(PLUGIN_NAME "file_handle")

set(INCLUDE_DIRS "${INCLUDE_DIRS};${CMAKE_CURRENT_SOURCE_DIR}/src")

file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c*")

set(DEPENDENCIES "rtf_model" "rtf_selectors" "rtf_services" "rtf_types" "rtf_serialization" "rtf_common")

create_plugin("${PLUGIN_NAME}" "${SOURCES}" "${INCLUDES}" "${DEPENDENCIES}")
