# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = C:\Users\Deblur\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.4746.93\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Deblur\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.4746.93\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Deblur\CLionProjects\2021-OOP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Deblur\CLionProjects\2021-OOP\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OOP_2021.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/OOP_2021.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OOP_2021.dir/flags.make

CMakeFiles/OOP_2021.dir/hw1.cpp.obj: CMakeFiles/OOP_2021.dir/flags.make
CMakeFiles/OOP_2021.dir/hw1.cpp.obj: ../hw1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Deblur\CLionProjects\2021-OOP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OOP_2021.dir/hw1.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OOP_2021.dir\hw1.cpp.obj -c C:\Users\Deblur\CLionProjects\2021-OOP\hw1.cpp

CMakeFiles/OOP_2021.dir/hw1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP_2021.dir/hw1.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Deblur\CLionProjects\2021-OOP\hw1.cpp > CMakeFiles\OOP_2021.dir\hw1.cpp.i

CMakeFiles/OOP_2021.dir/hw1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP_2021.dir/hw1.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Deblur\CLionProjects\2021-OOP\hw1.cpp -o CMakeFiles\OOP_2021.dir\hw1.cpp.s

# Object files for target OOP_2021
OOP_2021_OBJECTS = \
"CMakeFiles/OOP_2021.dir/hw1.cpp.obj"

# External object files for target OOP_2021
OOP_2021_EXTERNAL_OBJECTS =

OOP_2021.exe: CMakeFiles/OOP_2021.dir/hw1.cpp.obj
OOP_2021.exe: CMakeFiles/OOP_2021.dir/build.make
OOP_2021.exe: CMakeFiles/OOP_2021.dir/linklibs.rsp
OOP_2021.exe: CMakeFiles/OOP_2021.dir/objects1.rsp
OOP_2021.exe: CMakeFiles/OOP_2021.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Deblur\CLionProjects\2021-OOP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable OOP_2021.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\OOP_2021.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OOP_2021.dir/build: OOP_2021.exe
.PHONY : CMakeFiles/OOP_2021.dir/build

CMakeFiles/OOP_2021.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\OOP_2021.dir\cmake_clean.cmake
.PHONY : CMakeFiles/OOP_2021.dir/clean

CMakeFiles/OOP_2021.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Deblur\CLionProjects\2021-OOP C:\Users\Deblur\CLionProjects\2021-OOP C:\Users\Deblur\CLionProjects\2021-OOP\cmake-build-debug C:\Users\Deblur\CLionProjects\2021-OOP\cmake-build-debug C:\Users\Deblur\CLionProjects\2021-OOP\cmake-build-debug\CMakeFiles\OOP_2021.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OOP_2021.dir/depend

