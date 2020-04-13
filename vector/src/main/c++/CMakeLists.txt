cmake_minimum_required(VERSION 3.2)

# Base root directory
set(BASE_TOP "$ENV{CODAC_ROOT}" CACHE PATH "Path to the directory containing the RTF tools and CMake modules.")

# RTF CMake modules path.
include("${BASE_TOP}/cmake_modules/Includes.cmake")

# Project configuration.
set(PROJECT "rtf_vector")
set(${PROJECT}_VERSION "${PLUGIN_VERSION}" CACHE STRING "Project ${PROJECT} version.")
set(SUBDIRS "rtf_vector")

create_project("${PROJECT}" "${${PROJECT}_VERSION}" "${SUBDIRS}")
