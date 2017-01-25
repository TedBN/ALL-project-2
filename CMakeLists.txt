cmake_minimum_required(VERSION 3.6)
project(ALL_project_2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        aTurnOf.h
        Country.h
        diplomacyRequest.h
        main.cpp
        Region.h)

add_executable(ALL_project_2 ${SOURCE_FILES})