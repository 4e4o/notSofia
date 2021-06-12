cmake_minimum_required(VERSION 3.5)

project(notSofia LANGUAGES CXX C)

add_subdirectory(notSofiaLib)

set(CMAKE_VERBOSE_MAKEFILE ON)

# used compiler:
# blabla/Hi3520D_SDK_V1.0.5.1/osdrv/toolchain/arm-hisiv100nptl-linux/install/opt/hisi-linux-nptl/arm-hisiv100-linux/bin/arm-hisiv100-linux-uclibcgnueabi-gcc

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} "")

file(GLOB_RECURSE PRJ_SRCS src/*.c src/*.cpp src/*.h src/*.hpp notSofiaLib/notSofia.astylerc)
target_sources(${PROJECT_NAME} PRIVATE ${PRJ_SRCS})

target_include_directories(${PROJECT_NAME} SYSTEM PUBLIC
    ${PROJECT_SOURCE_DIR}/src
    )

target_link_libraries(${PROJECT_NAME} PUBLIC notSofiaLib)

set(SYSTEM_NEW_TOOLCHAIN_LIBS_PATH "/usr/lib/notSofia")

# тулчёйн самосборный, либы все новые и их надо в отдельное место в системе положить
# и бинарнику сказать где искать это всё
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS
    "-Wl,-rpath,${SYSTEM_NEW_TOOLCHAIN_LIBS_PATH} -Wl,--dynamic-linker=${SYSTEM_NEW_TOOLCHAIN_LIBS_PATH}/ld-uClibc.so.1")
