cmake_minimum_required(VERSION 3.6)
project(ALL_project_2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Country.h
        main.cpp
        Manager.h
        MilitaryUnit.h
        Region.h Test/T1.h Test/T2.h Test/T3.h Test/T4.h)

add_executable(ALL_project_2 ${SOURCE_FILES})