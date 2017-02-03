cmake_minimum_required(VERSION 3.6)
project(ALL_project_2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Test/Test.h
        Test/Test1.h
        Army.h
        Country.h
        DiplomacyRequest.h
        main.cpp
        Manager.h
        MilitaryUnit.h
        Region.h)

add_executable(ALL_project_2 ${SOURCE_FILES})