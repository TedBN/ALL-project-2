cmake_minimum_required(VERSION 3.6)
project(ALL_project_2)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)


set(MAIN_BUILD main)
set(SOURCE_FILES
        Country.h
        main.cpp
        Manager.h
        MilitaryUnit.h
        Region.h)
add_executable(${MAIN_BUILD} ${SOURCE_FILES})

set(TESTING_BUILD testing)
set(SOURCE_FILES_T
        Country.h
        testing/Testing.cpp
        Manager.h
        MilitaryUnit.h
        Region.h)
add_executable(${TESTING_BUILD} ${SOURCE_FILES_T})


target_link_libraries(${TESTING_BUILD} gtest gtest_main)