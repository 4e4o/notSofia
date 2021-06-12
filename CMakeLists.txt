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

set_elf_rpath_and_ld_path(${PROJECT_NAME})
