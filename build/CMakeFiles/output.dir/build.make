# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/evheny/soft/cmake/cmake-3.30.3-linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/evheny/soft/cmake/cmake-3.30.3-linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/evheny/vsprojects/statistics/one-row-stat-linux-local

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/evheny/vsprojects/statistics/one-row-stat-linux-local/build

# Include any dependencies generated for this target.
include CMakeFiles/output.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/output.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/output.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/output.dir/flags.make

CMakeFiles/output.dir/lib/output.cpp.o: CMakeFiles/output.dir/flags.make
CMakeFiles/output.dir/lib/output.cpp.o: /home/evheny/vsprojects/statistics/one-row-stat-linux-local/lib/output.cpp
CMakeFiles/output.dir/lib/output.cpp.o: CMakeFiles/output.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/evheny/vsprojects/statistics/one-row-stat-linux-local/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/output.dir/lib/output.cpp.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/output.dir/lib/output.cpp.o -MF CMakeFiles/output.dir/lib/output.cpp.o.d -o CMakeFiles/output.dir/lib/output.cpp.o -c /home/evheny/vsprojects/statistics/one-row-stat-linux-local/lib/output.cpp

CMakeFiles/output.dir/lib/output.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/output.dir/lib/output.cpp.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/evheny/vsprojects/statistics/one-row-stat-linux-local/lib/output.cpp > CMakeFiles/output.dir/lib/output.cpp.i

CMakeFiles/output.dir/lib/output.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/output.dir/lib/output.cpp.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/evheny/vsprojects/statistics/one-row-stat-linux-local/lib/output.cpp -o CMakeFiles/output.dir/lib/output.cpp.s

# Object files for target output
output_OBJECTS = \
"CMakeFiles/output.dir/lib/output.cpp.o"

# External object files for target output
output_EXTERNAL_OBJECTS =

app/lib/static/liboutput.a: CMakeFiles/output.dir/lib/output.cpp.o
app/lib/static/liboutput.a: CMakeFiles/output.dir/build.make
app/lib/static/liboutput.a: CMakeFiles/output.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/evheny/vsprojects/statistics/one-row-stat-linux-local/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library app/lib/static/liboutput.a"
	$(CMAKE_COMMAND) -P CMakeFiles/output.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/output.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/output.dir/build: app/lib/static/liboutput.a
.PHONY : CMakeFiles/output.dir/build

CMakeFiles/output.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/output.dir/cmake_clean.cmake
.PHONY : CMakeFiles/output.dir/clean

CMakeFiles/output.dir/depend:
	cd /home/evheny/vsprojects/statistics/one-row-stat-linux-local/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/evheny/vsprojects/statistics/one-row-stat-linux-local /home/evheny/vsprojects/statistics/one-row-stat-linux-local /home/evheny/vsprojects/statistics/one-row-stat-linux-local/build /home/evheny/vsprojects/statistics/one-row-stat-linux-local/build /home/evheny/vsprojects/statistics/one-row-stat-linux-local/build/CMakeFiles/output.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/output.dir/depend

