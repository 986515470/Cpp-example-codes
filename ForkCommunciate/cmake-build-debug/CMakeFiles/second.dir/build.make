# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\c++\.vs\ForkCommunciate

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\c++\.vs\ForkCommunciate\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/second.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/second.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/second.dir/flags.make

CMakeFiles/second.dir/second.c.obj: CMakeFiles/second.dir/flags.make
CMakeFiles/second.dir/second.c.obj: ../second.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\c++\.vs\ForkCommunciate\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/second.dir/second.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\second.dir\second.c.obj -c C:\c++\.vs\ForkCommunciate\second.c

CMakeFiles/second.dir/second.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/second.dir/second.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\c++\.vs\ForkCommunciate\second.c > CMakeFiles\second.dir\second.c.i

CMakeFiles/second.dir/second.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/second.dir/second.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\c++\.vs\ForkCommunciate\second.c -o CMakeFiles\second.dir\second.c.s

# Object files for target second
second_OBJECTS = \
"CMakeFiles/second.dir/second.c.obj"

# External object files for target second
second_EXTERNAL_OBJECTS =

second.exe: CMakeFiles/second.dir/second.c.obj
second.exe: CMakeFiles/second.dir/build.make
second.exe: CMakeFiles/second.dir/linklibs.rsp
second.exe: CMakeFiles/second.dir/objects1.rsp
second.exe: CMakeFiles/second.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\c++\.vs\ForkCommunciate\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable second.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\second.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/second.dir/build: second.exe

.PHONY : CMakeFiles/second.dir/build

CMakeFiles/second.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\second.dir\cmake_clean.cmake
.PHONY : CMakeFiles/second.dir/clean

CMakeFiles/second.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\c++\.vs\ForkCommunciate C:\c++\.vs\ForkCommunciate C:\c++\.vs\ForkCommunciate\cmake-build-debug C:\c++\.vs\ForkCommunciate\cmake-build-debug C:\c++\.vs\ForkCommunciate\cmake-build-debug\CMakeFiles\second.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/second.dir/depend

