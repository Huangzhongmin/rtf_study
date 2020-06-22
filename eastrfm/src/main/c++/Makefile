#+======================================================================
#
# Project       : Real-Time Framework
#
# Description   : Makefile
#
# Author        : Anze Zagar, Cosylab
#
# Copyright (c) : 2017-2019 ITER Organization,
#                 CS 90 046
#                 13067 St. Paul-lez-Durance Cedex
#                 France
#
# This file is part of ITER CODAC software.
# For the terms and conditions of redistribution or use of this software
# refer to the file ITER-LICENSE.TXT located in the top level directory
# of the distribution package.
#
#-======================================================================

.PHONY: all listdeps

ifeq ($(COVERAGE),true)
BUILD_TYPE = Coverage
else
BUILD_TYPE = Release
endif

PLUGIN_VERSION = $(shell V=($$(sed -e 's/[^0-9.].*//' -e 's/\./ /g' <<< ${UNIT_VERSION})); echo -n $${V[0]:-0}; for i in {1..2}; do echo -n .$${V[$$i]:-0}; done)
CMAKE_FLAGS = -DPLUGIN_VERSION=${PLUGIN_VERSION} -DBASE_TOP=${CODAC_ROOT} -DCMAKE_BUILD_TYPE=${BUILD_TYPE} -DCMAKE_TOOLCHAIN_FILE=${CODAC_ROOT}/cmake_toolchains/codac-gcc.cmake

all:
	@mkdir -p build
	cmake3 -Bbuild -H. ${CMAKE_FLAGS}
	${MAKE} -C build ${MFLAGS} install

listdeps:
	@mkdir -p build
	cmake3 -Bbuild -H. ${CMAKE_FLAGS}
	${MAKE} -C build -j1 listdeps

