# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /snap/clion/129/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/129/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gunther/CLionProjects/KinderColoring

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gunther/CLionProjects/KinderColoring/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/KinderColoring.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/KinderColoring.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/KinderColoring.dir/flags.make

CMakeFiles/KinderColoring.dir/main.cpp.o: CMakeFiles/KinderColoring.dir/flags.make
CMakeFiles/KinderColoring.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gunther/CLionProjects/KinderColoring/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/KinderColoring.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/KinderColoring.dir/main.cpp.o -c /home/gunther/CLionProjects/KinderColoring/main.cpp

CMakeFiles/KinderColoring.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KinderColoring.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gunther/CLionProjects/KinderColoring/main.cpp > CMakeFiles/KinderColoring.dir/main.cpp.i

CMakeFiles/KinderColoring.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KinderColoring.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gunther/CLionProjects/KinderColoring/main.cpp -o CMakeFiles/KinderColoring.dir/main.cpp.s

# Object files for target KinderColoring
KinderColoring_OBJECTS = \
"CMakeFiles/KinderColoring.dir/main.cpp.o"

# External object files for target KinderColoring
KinderColoring_EXTERNAL_OBJECTS =

KinderColoring: CMakeFiles/KinderColoring.dir/main.cpp.o
KinderColoring: CMakeFiles/KinderColoring.dir/build.make
KinderColoring: CMakeFiles/KinderColoring.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gunther/CLionProjects/KinderColoring/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable KinderColoring"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/KinderColoring.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/KinderColoring.dir/build: KinderColoring

.PHONY : CMakeFiles/KinderColoring.dir/build

CMakeFiles/KinderColoring.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/KinderColoring.dir/cmake_clean.cmake
.PHONY : CMakeFiles/KinderColoring.dir/clean

CMakeFiles/KinderColoring.dir/depend:
	cd /home/gunther/CLionProjects/KinderColoring/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gunther/CLionProjects/KinderColoring /home/gunther/CLionProjects/KinderColoring /home/gunther/CLionProjects/KinderColoring/cmake-build-debug /home/gunther/CLionProjects/KinderColoring/cmake-build-debug /home/gunther/CLionProjects/KinderColoring/cmake-build-debug/CMakeFiles/KinderColoring.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/KinderColoring.dir/depend

