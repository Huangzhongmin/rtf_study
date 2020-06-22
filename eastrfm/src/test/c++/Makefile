.PHONY: all listdeps test

ifeq ($(COVERAGE),true)
BUILD_TYPE = Coverage
else
BUILD_TYPE = Release
endif

CMAKE_FLAGS = -DBASE_TOP=${CODAC_ROOT} -DCMAKE_BUILD_TYPE=${BUILD_TYPE} -DCMAKE_TOOLCHAIN_FILE=${CODAC_ROOT}/cmake_toolchains/codac-gcc.cmake

all:
	@mkdir -p build
	cmake3 -Bbuild -H. ${CMAKE_FLAGS}
	${MAKE} -C build ${MFLAGS}

listdeps:
	@mkdir -p build
	cmake3 -Bbuild -H. ${CMAKE_FLAGS}
	${MAKE} -C build -j1 listdeps

test:
	@cd build && ctest3 -V

