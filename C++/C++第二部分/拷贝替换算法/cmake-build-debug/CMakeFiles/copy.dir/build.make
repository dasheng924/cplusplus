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
CMAKE_SOURCE_DIR = /Users/sunguosheng/CLionProjects/拷贝替换算法

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sunguosheng/CLionProjects/拷贝替换算法/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/copy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/copy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/copy.dir/flags.make

CMakeFiles/copy.dir/main.cpp.o: CMakeFiles/copy.dir/flags.make
CMakeFiles/copy.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sunguosheng/CLionProjects/拷贝替换算法/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/copy.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/copy.dir/main.cpp.o -c /Users/sunguosheng/CLionProjects/拷贝替换算法/main.cpp

CMakeFiles/copy.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/copy.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sunguosheng/CLionProjects/拷贝替换算法/main.cpp > CMakeFiles/copy.dir/main.cpp.i

CMakeFiles/copy.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/copy.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sunguosheng/CLionProjects/拷贝替换算法/main.cpp -o CMakeFiles/copy.dir/main.cpp.s

# Object files for target copy
copy_OBJECTS = \
"CMakeFiles/copy.dir/main.cpp.o"

# External object files for target copy
copy_EXTERNAL_OBJECTS =

copy: CMakeFiles/copy.dir/main.cpp.o
copy: CMakeFiles/copy.dir/build.make
copy: CMakeFiles/copy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sunguosheng/CLionProjects/拷贝替换算法/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable copy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/copy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/copy.dir/build: copy

.PHONY : CMakeFiles/copy.dir/build

CMakeFiles/copy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/copy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/copy.dir/clean

CMakeFiles/copy.dir/depend:
	cd /Users/sunguosheng/CLionProjects/拷贝替换算法/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sunguosheng/CLionProjects/拷贝替换算法 /Users/sunguosheng/CLionProjects/拷贝替换算法 /Users/sunguosheng/CLionProjects/拷贝替换算法/cmake-build-debug /Users/sunguosheng/CLionProjects/拷贝替换算法/cmake-build-debug /Users/sunguosheng/CLionProjects/拷贝替换算法/cmake-build-debug/CMakeFiles/copy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/copy.dir/depend

