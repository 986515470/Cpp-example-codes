# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\c++\.vs\Source_Design

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\c++\.vs\Source_Design\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Tree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tree.dir/flags.make

CMakeFiles/Tree.dir/Tree.cpp.obj: CMakeFiles/Tree.dir/flags.make
CMakeFiles/Tree.dir/Tree.cpp.obj: ../Tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\c++\.vs\Source_Design\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tree.dir/Tree.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Tree.dir\Tree.cpp.obj -c C:\c++\.vs\Source_Design\Tree.cpp

CMakeFiles/Tree.dir/Tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tree.dir/Tree.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\c++\.vs\Source_Design\Tree.cpp > CMakeFiles\Tree.dir\Tree.cpp.i

CMakeFiles/Tree.dir/Tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tree.dir/Tree.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\c++\.vs\Source_Design\Tree.cpp -o CMakeFiles\Tree.dir\Tree.cpp.s

# Object files for target Tree
Tree_OBJECTS = \
"CMakeFiles/Tree.dir/Tree.cpp.obj"

# External object files for target Tree
Tree_EXTERNAL_OBJECTS =

Tree.exe: CMakeFiles/Tree.dir/Tree.cpp.obj
Tree.exe: CMakeFiles/Tree.dir/build.make
Tree.exe: CMakeFiles/Tree.dir/linklibs.rsp
Tree.exe: CMakeFiles/Tree.dir/objects1.rsp
Tree.exe: CMakeFiles/Tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\c++\.vs\Source_Design\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Tree.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Tree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tree.dir/build: Tree.exe

.PHONY : CMakeFiles/Tree.dir/build

CMakeFiles/Tree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Tree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Tree.dir/clean

CMakeFiles/Tree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\c++\.vs\Source_Design C:\c++\.vs\Source_Design C:\c++\.vs\Source_Design\cmake-build-debug C:\c++\.vs\Source_Design\cmake-build-debug C:\c++\.vs\Source_Design\cmake-build-debug\CMakeFiles\Tree.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tree.dir/depend

