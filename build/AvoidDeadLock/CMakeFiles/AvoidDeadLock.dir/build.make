# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lzr/ProgramFiles/cplusplus/MultiThread

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lzr/ProgramFiles/cplusplus/MultiThread/build

# Include any dependencies generated for this target.
include AvoidDeadLock/CMakeFiles/AvoidDeadLock.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include AvoidDeadLock/CMakeFiles/AvoidDeadLock.dir/compiler_depend.make

# Include the progress variables for this target.
include AvoidDeadLock/CMakeFiles/AvoidDeadLock.dir/progress.make

# Include the compile flags for this target's objects.
include AvoidDeadLock/CMakeFiles/AvoidDeadLock.dir/flags.make

AvoidDeadLock/CMakeFiles/AvoidDeadLock.dir/main.cpp.o: AvoidDeadLock/CMakeFiles/AvoidDeadLock.dir/flags.make
AvoidDeadLock/CMakeFiles/AvoidDeadLock.dir/main.cpp.o: ../AvoidDeadLock/main.cpp
AvoidDeadLock/CMakeFiles/AvoidDeadLock.dir/main.cpp.o: AvoidDeadLock/CMakeFiles/AvoidDeadLock.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lzr/ProgramFiles/cplusplus/MultiThread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object AvoidDeadLock/CMakeFiles/AvoidDeadLock.dir/main.cpp.o"
	cd /home/lzr/ProgramFiles/cplusplus/MultiThread/build/AvoidDeadLock && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT AvoidDeadLock/CMakeFiles/AvoidDeadLock.dir/main.cpp.o -MF CMakeFiles/AvoidDeadLock.dir/main.cpp.o.d -o CMakeFiles/AvoidDeadLock.dir/main.cpp.o -c /home/lzr/ProgramFiles/cplusplus/MultiThread/AvoidDeadLock/main.cpp

AvoidDeadLock/CMakeFiles/AvoidDeadLock.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AvoidDeadLock.dir/main.cpp.i"
	cd /home/lzr/ProgramFiles/cplusplus/MultiThread/build/AvoidDeadLock && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lzr/ProgramFiles/cplusplus/MultiThread/AvoidDeadLock/main.cpp > CMakeFiles/AvoidDeadLock.dir/main.cpp.i

AvoidDeadLock/CMakeFiles/AvoidDeadLock.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AvoidDeadLock.dir/main.cpp.s"
	cd /home/lzr/ProgramFiles/cplusplus/MultiThread/build/AvoidDeadLock && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lzr/ProgramFiles/cplusplus/MultiThread/AvoidDeadLock/main.cpp -o CMakeFiles/AvoidDeadLock.dir/main.cpp.s

# Object files for target AvoidDeadLock
AvoidDeadLock_OBJECTS = \
"CMakeFiles/AvoidDeadLock.dir/main.cpp.o"

# External object files for target AvoidDeadLock
AvoidDeadLock_EXTERNAL_OBJECTS =

AvoidDeadLock/AvoidDeadLock: AvoidDeadLock/CMakeFiles/AvoidDeadLock.dir/main.cpp.o
AvoidDeadLock/AvoidDeadLock: AvoidDeadLock/CMakeFiles/AvoidDeadLock.dir/build.make
AvoidDeadLock/AvoidDeadLock: AvoidDeadLock/CMakeFiles/AvoidDeadLock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lzr/ProgramFiles/cplusplus/MultiThread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AvoidDeadLock"
	cd /home/lzr/ProgramFiles/cplusplus/MultiThread/build/AvoidDeadLock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AvoidDeadLock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
AvoidDeadLock/CMakeFiles/AvoidDeadLock.dir/build: AvoidDeadLock/AvoidDeadLock
.PHONY : AvoidDeadLock/CMakeFiles/AvoidDeadLock.dir/build

AvoidDeadLock/CMakeFiles/AvoidDeadLock.dir/clean:
	cd /home/lzr/ProgramFiles/cplusplus/MultiThread/build/AvoidDeadLock && $(CMAKE_COMMAND) -P CMakeFiles/AvoidDeadLock.dir/cmake_clean.cmake
.PHONY : AvoidDeadLock/CMakeFiles/AvoidDeadLock.dir/clean

AvoidDeadLock/CMakeFiles/AvoidDeadLock.dir/depend:
	cd /home/lzr/ProgramFiles/cplusplus/MultiThread/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lzr/ProgramFiles/cplusplus/MultiThread /home/lzr/ProgramFiles/cplusplus/MultiThread/AvoidDeadLock /home/lzr/ProgramFiles/cplusplus/MultiThread/build /home/lzr/ProgramFiles/cplusplus/MultiThread/build/AvoidDeadLock /home/lzr/ProgramFiles/cplusplus/MultiThread/build/AvoidDeadLock/CMakeFiles/AvoidDeadLock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : AvoidDeadLock/CMakeFiles/AvoidDeadLock.dir/depend

