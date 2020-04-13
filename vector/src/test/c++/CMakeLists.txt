cmake_minimum_required(VERSION 3.2)

include("${BASE_TOP}/cmake_modules/Includes.cmake")

enable_testing()

# Find Google tests.
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(SUBDIRS "rtf_vector")

add_subdirectories("${SUBDIRS}")
