cmake_minimum_required(VERSION 3.2)

set(TEST_NAME "test_mds_io")

set(INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/include")
file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
set(DEPENDENCIES "rtf_mds_io_plugin" "rtf_testing_framework" "rtf_model" "rtf_common" "rtf_containers" "rtf_types" "rtf_serialization")

create_tests("${TEST_NAME}" "${SOURCES}" "${INCLUDES}" "${DEPENDENCIES}")
