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
CMAKE_SOURCE_DIR = /Users/sunguosheng/CLionProjects/STL案列--演讲比赛

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sunguosheng/CLionProjects/STL案列--演讲比赛/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/STL__.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/STL__.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/STL__.dir/flags.make

CMakeFiles/STL__.dir/main.cpp.o: CMakeFiles/STL__.dir/flags.make
CMakeFiles/STL__.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sunguosheng/CLionProjects/STL案列--演讲比赛/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/STL__.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/STL__.dir/main.cpp.o -c /Users/sunguosheng/CLionProjects/STL案列--演讲比赛/main.cpp

CMakeFiles/STL__.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/STL__.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sunguosheng/CLionProjects/STL案列--演讲比赛/main.cpp > CMakeFiles/STL__.dir/main.cpp.i

CMakeFiles/STL__.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/STL__.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sunguosheng/CLionProjects/STL案列--演讲比赛/main.cpp -o CMakeFiles/STL__.dir/main.cpp.s

# Object files for target STL__
STL___OBJECTS = \
"CMakeFiles/STL__.dir/main.cpp.o"

# External object files for target STL__
STL___EXTERNAL_OBJECTS =

STL__: CMakeFiles/STL__.dir/main.cpp.o
STL__: CMakeFiles/STL__.dir/build.make
STL__: CMakeFiles/STL__.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sunguosheng/CLionProjects/STL案列--演讲比赛/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable STL__"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/STL__.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/STL__.dir/build: STL__

.PHONY : CMakeFiles/STL__.dir/build

CMakeFiles/STL__.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/STL__.dir/cmake_clean.cmake
.PHONY : CMakeFiles/STL__.dir/clean

CMakeFiles/STL__.dir/depend:
	cd /Users/sunguosheng/CLionProjects/STL案列--演讲比赛/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sunguosheng/CLionProjects/STL案列--演讲比赛 /Users/sunguosheng/CLionProjects/STL案列--演讲比赛 /Users/sunguosheng/CLionProjects/STL案列--演讲比赛/cmake-build-debug /Users/sunguosheng/CLionProjects/STL案列--演讲比赛/cmake-build-debug /Users/sunguosheng/CLionProjects/STL案列--演讲比赛/cmake-build-debug/CMakeFiles/STL__.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/STL__.dir/depend

