# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/Oscari/My Files/Git/ALL-project-2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/Oscari/My Files/Git/ALL-project-2/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ALL_project_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ALL_project_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ALL_project_2.dir/flags.make

CMakeFiles/ALL_project_2.dir/main.cpp.o: CMakeFiles/ALL_project_2.dir/flags.make
CMakeFiles/ALL_project_2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Oscari/My Files/Git/ALL-project-2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ALL_project_2.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ALL_project_2.dir/main.cpp.o -c "/Users/Oscari/My Files/Git/ALL-project-2/main.cpp"

CMakeFiles/ALL_project_2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ALL_project_2.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Oscari/My Files/Git/ALL-project-2/main.cpp" > CMakeFiles/ALL_project_2.dir/main.cpp.i

CMakeFiles/ALL_project_2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ALL_project_2.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Oscari/My Files/Git/ALL-project-2/main.cpp" -o CMakeFiles/ALL_project_2.dir/main.cpp.s

CMakeFiles/ALL_project_2.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/ALL_project_2.dir/main.cpp.o.requires

CMakeFiles/ALL_project_2.dir/main.cpp.o.provides: CMakeFiles/ALL_project_2.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ALL_project_2.dir/build.make CMakeFiles/ALL_project_2.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ALL_project_2.dir/main.cpp.o.provides

CMakeFiles/ALL_project_2.dir/main.cpp.o.provides.build: CMakeFiles/ALL_project_2.dir/main.cpp.o


# Object files for target ALL_project_2
ALL_project_2_OBJECTS = \
"CMakeFiles/ALL_project_2.dir/main.cpp.o"

# External object files for target ALL_project_2
ALL_project_2_EXTERNAL_OBJECTS =

ALL_project_2: CMakeFiles/ALL_project_2.dir/main.cpp.o
ALL_project_2: CMakeFiles/ALL_project_2.dir/build.make
ALL_project_2: lib/googletest-master/googlemock/gtest/libgtest.a
ALL_project_2: lib/googletest-master/googlemock/gtest/libgtest_main.a
ALL_project_2: lib/googletest-master/googlemock/gtest/libgtest.a
ALL_project_2: CMakeFiles/ALL_project_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/Oscari/My Files/Git/ALL-project-2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ALL_project_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ALL_project_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ALL_project_2.dir/build: ALL_project_2

.PHONY : CMakeFiles/ALL_project_2.dir/build

CMakeFiles/ALL_project_2.dir/requires: CMakeFiles/ALL_project_2.dir/main.cpp.o.requires

.PHONY : CMakeFiles/ALL_project_2.dir/requires

CMakeFiles/ALL_project_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ALL_project_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ALL_project_2.dir/clean

CMakeFiles/ALL_project_2.dir/depend:
	cd "/Users/Oscari/My Files/Git/ALL-project-2/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/Oscari/My Files/Git/ALL-project-2" "/Users/Oscari/My Files/Git/ALL-project-2" "/Users/Oscari/My Files/Git/ALL-project-2/cmake-build-debug" "/Users/Oscari/My Files/Git/ALL-project-2/cmake-build-debug" "/Users/Oscari/My Files/Git/ALL-project-2/cmake-build-debug/CMakeFiles/ALL_project_2.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ALL_project_2.dir/depend

