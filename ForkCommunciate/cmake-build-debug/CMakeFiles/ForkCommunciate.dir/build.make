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
include CMakeFiles/ForkCommunciate.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ForkCommunciate.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ForkCommunciate.dir/flags.make

CMakeFiles/ForkCommunciate.dir/main.cpp.obj: CMakeFiles/ForkCommunciate.dir/flags.make
CMakeFiles/ForkCommunciate.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\c++\.vs\ForkCommunciate\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ForkCommunciate.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ForkCommunciate.dir\main.cpp.obj -c C:\c++\.vs\ForkCommunciate\main.cpp

CMakeFiles/ForkCommunciate.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ForkCommunciate.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\c++\.vs\ForkCommunciate\main.cpp > CMakeFiles\ForkCommunciate.dir\main.cpp.i

CMakeFiles/ForkCommunciate.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ForkCommunciate.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\c++\.vs\ForkCommunciate\main.cpp -o CMakeFiles\ForkCommunciate.dir\main.cpp.s

CMakeFiles/ForkCommunciate.dir/communciate.cpp.obj: CMakeFiles/ForkCommunciate.dir/flags.make
CMakeFiles/ForkCommunciate.dir/communciate.cpp.obj: ../communciate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\c++\.vs\ForkCommunciate\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ForkCommunciate.dir/communciate.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ForkCommunciate.dir\communciate.cpp.obj -c C:\c++\.vs\ForkCommunciate\communciate.cpp

CMakeFiles/ForkCommunciate.dir/communciate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ForkCommunciate.dir/communciate.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\c++\.vs\ForkCommunciate\communciate.cpp > CMakeFiles\ForkCommunciate.dir\communciate.cpp.i

CMakeFiles/ForkCommunciate.dir/communciate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ForkCommunciate.dir/communciate.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\c++\.vs\ForkCommunciate\communciate.cpp -o CMakeFiles\ForkCommunciate.dir\communciate.cpp.s

CMakeFiles/ForkCommunciate.dir/second.c.obj: CMakeFiles/ForkCommunciate.dir/flags.make
CMakeFiles/ForkCommunciate.dir/second.c.obj: ../second.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\c++\.vs\ForkCommunciate\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ForkCommunciate.dir/second.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ForkCommunciate.dir\second.c.obj -c C:\c++\.vs\ForkCommunciate\second.c

CMakeFiles/ForkCommunciate.dir/second.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ForkCommunciate.dir/second.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\c++\.vs\ForkCommunciate\second.c > CMakeFiles\ForkCommunciate.dir\second.c.i

CMakeFiles/ForkCommunciate.dir/second.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ForkCommunciate.dir/second.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\c++\.vs\ForkCommunciate\second.c -o CMakeFiles\ForkCommunciate.dir\second.c.s

CMakeFiles/ForkCommunciate.dir/two.cpp.obj: CMakeFiles/ForkCommunciate.dir/flags.make
CMakeFiles/ForkCommunciate.dir/two.cpp.obj: ../two.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\c++\.vs\ForkCommunciate\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ForkCommunciate.dir/two.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ForkCommunciate.dir\two.cpp.obj -c C:\c++\.vs\ForkCommunciate\two.cpp

CMakeFiles/ForkCommunciate.dir/two.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ForkCommunciate.dir/two.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\c++\.vs\ForkCommunciate\two.cpp > CMakeFiles\ForkCommunciate.dir\two.cpp.i

CMakeFiles/ForkCommunciate.dir/two.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ForkCommunciate.dir/two.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\c++\.vs\ForkCommunciate\two.cpp -o CMakeFiles\ForkCommunciate.dir\two.cpp.s

CMakeFiles/ForkCommunciate.dir/two.c.obj: CMakeFiles/ForkCommunciate.dir/flags.make
CMakeFiles/ForkCommunciate.dir/two.c.obj: ../two.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\c++\.vs\ForkCommunciate\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/ForkCommunciate.dir/two.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ForkCommunciate.dir\two.c.obj -c C:\c++\.vs\ForkCommunciate\two.c

CMakeFiles/ForkCommunciate.dir/two.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ForkCommunciate.dir/two.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\c++\.vs\ForkCommunciate\two.c > CMakeFiles\ForkCommunciate.dir\two.c.i

CMakeFiles/ForkCommunciate.dir/two.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ForkCommunciate.dir/two.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\c++\.vs\ForkCommunciate\two.c -o CMakeFiles\ForkCommunciate.dir\two.c.s

CMakeFiles/ForkCommunciate.dir/third.c.obj: CMakeFiles/ForkCommunciate.dir/flags.make
CMakeFiles/ForkCommunciate.dir/third.c.obj: ../third.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\c++\.vs\ForkCommunciate\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/ForkCommunciate.dir/third.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ForkCommunciate.dir\third.c.obj -c C:\c++\.vs\ForkCommunciate\third.c

CMakeFiles/ForkCommunciate.dir/third.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ForkCommunciate.dir/third.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\c++\.vs\ForkCommunciate\third.c > CMakeFiles\ForkCommunciate.dir\third.c.i

CMakeFiles/ForkCommunciate.dir/third.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ForkCommunciate.dir/third.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\c++\.vs\ForkCommunciate\third.c -o CMakeFiles\ForkCommunciate.dir\third.c.s

CMakeFiles/ForkCommunciate.dir/third.cpp.obj: CMakeFiles/ForkCommunciate.dir/flags.make
CMakeFiles/ForkCommunciate.dir/third.cpp.obj: ../third.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\c++\.vs\ForkCommunciate\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ForkCommunciate.dir/third.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ForkCommunciate.dir\third.cpp.obj -c C:\c++\.vs\ForkCommunciate\third.cpp

CMakeFiles/ForkCommunciate.dir/third.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ForkCommunciate.dir/third.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\c++\.vs\ForkCommunciate\third.cpp > CMakeFiles\ForkCommunciate.dir\third.cpp.i

CMakeFiles/ForkCommunciate.dir/third.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ForkCommunciate.dir/third.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\c++\.vs\ForkCommunciate\third.cpp -o CMakeFiles\ForkCommunciate.dir\third.cpp.s

# Object files for target ForkCommunciate
ForkCommunciate_OBJECTS = \
"CMakeFiles/ForkCommunciate.dir/main.cpp.obj" \
"CMakeFiles/ForkCommunciate.dir/communciate.cpp.obj" \
"CMakeFiles/ForkCommunciate.dir/second.c.obj" \
"CMakeFiles/ForkCommunciate.dir/two.cpp.obj" \
"CMakeFiles/ForkCommunciate.dir/two.c.obj" \
"CMakeFiles/ForkCommunciate.dir/third.c.obj" \
"CMakeFiles/ForkCommunciate.dir/third.cpp.obj"

# External object files for target ForkCommunciate
ForkCommunciate_EXTERNAL_OBJECTS =

ForkCommunciate.exe: CMakeFiles/ForkCommunciate.dir/main.cpp.obj
ForkCommunciate.exe: CMakeFiles/ForkCommunciate.dir/communciate.cpp.obj
ForkCommunciate.exe: CMakeFiles/ForkCommunciate.dir/second.c.obj
ForkCommunciate.exe: CMakeFiles/ForkCommunciate.dir/two.cpp.obj
ForkCommunciate.exe: CMakeFiles/ForkCommunciate.dir/two.c.obj
ForkCommunciate.exe: CMakeFiles/ForkCommunciate.dir/third.c.obj
ForkCommunciate.exe: CMakeFiles/ForkCommunciate.dir/third.cpp.obj
ForkCommunciate.exe: CMakeFiles/ForkCommunciate.dir/build.make
ForkCommunciate.exe: CMakeFiles/ForkCommunciate.dir/linklibs.rsp
ForkCommunciate.exe: CMakeFiles/ForkCommunciate.dir/objects1.rsp
ForkCommunciate.exe: CMakeFiles/ForkCommunciate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\c++\.vs\ForkCommunciate\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable ForkCommunciate.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ForkCommunciate.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ForkCommunciate.dir/build: ForkCommunciate.exe

.PHONY : CMakeFiles/ForkCommunciate.dir/build

CMakeFiles/ForkCommunciate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ForkCommunciate.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ForkCommunciate.dir/clean

CMakeFiles/ForkCommunciate.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\c++\.vs\ForkCommunciate C:\c++\.vs\ForkCommunciate C:\c++\.vs\ForkCommunciate\cmake-build-debug C:\c++\.vs\ForkCommunciate\cmake-build-debug C:\c++\.vs\ForkCommunciate\cmake-build-debug\CMakeFiles\ForkCommunciate.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ForkCommunciate.dir/depend

