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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sunguosheng/CLionProjects/set的学习

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sunguosheng/CLionProjects/set的学习/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/set.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/set.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/set.dir/flags.make

CMakeFiles/set.dir/main.cpp.o: CMakeFiles/set.dir/flags.make
CMakeFiles/set.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sunguosheng/CLionProjects/set的学习/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/set.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/set.dir/main.cpp.o -c /Users/sunguosheng/CLionProjects/set的学习/main.cpp

CMakeFiles/set.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/set.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sunguosheng/CLionProjects/set的学习/main.cpp > CMakeFiles/set.dir/main.cpp.i

CMakeFiles/set.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/set.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sunguosheng/CLionProjects/set的学习/main.cpp -o CMakeFiles/set.dir/main.cpp.s

# Object files for target set
set_OBJECTS = \
"CMakeFiles/set.dir/main.cpp.o"

# External object files for target set
set_EXTERNAL_OBJECTS =

set: CMakeFiles/set.dir/main.cpp.o
set: CMakeFiles/set.dir/build.make
set: CMakeFiles/set.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sunguosheng/CLionProjects/set的学习/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable set"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/set.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/set.dir/build: set

.PHONY : CMakeFiles/set.dir/build

CMakeFiles/set.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/set.dir/cmake_clean.cmake
.PHONY : CMakeFiles/set.dir/clean

CMakeFiles/set.dir/depend:
	cd /Users/sunguosheng/CLionProjects/set的学习/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sunguosheng/CLionProjects/set的学习 /Users/sunguosheng/CLionProjects/set的学习 /Users/sunguosheng/CLionProjects/set的学习/cmake-build-debug /Users/sunguosheng/CLionProjects/set的学习/cmake-build-debug /Users/sunguosheng/CLionProjects/set的学习/cmake-build-debug/CMakeFiles/set.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/set.dir/depend

