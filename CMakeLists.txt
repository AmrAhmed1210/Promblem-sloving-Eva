cmake_minimum_required(VERSION 3.16)
project(ProblemSolving LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/*.cpp)

foreach(source ${SOURCES})
    get_filename_component(name ${source} NAME_WE)
    get_filename_component(directory ${source} DIRECTORY)
    get_filename_component(folder ${directory} NAME)
    string(REGEX MATCH "^week_[0-9]+" week ${folder})
    add_executable(${week}_${name} ${source})
    target_include_directories(${week}_${name} PRIVATE ${directory})
endforeach()
