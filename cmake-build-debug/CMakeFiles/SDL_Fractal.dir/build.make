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
CMAKE_SOURCE_DIR = "/Users/sv/ucu/Semester 1/cpp/project/SDL_Fractal"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/sv/ucu/Semester 1/cpp/project/SDL_Fractal/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/SDL_Fractal.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SDL_Fractal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SDL_Fractal.dir/flags.make

CMakeFiles/SDL_Fractal.dir/src/main.cpp.o: CMakeFiles/SDL_Fractal.dir/flags.make
CMakeFiles/SDL_Fractal.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/sv/ucu/Semester 1/cpp/project/SDL_Fractal/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SDL_Fractal.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SDL_Fractal.dir/src/main.cpp.o -c "/Users/sv/ucu/Semester 1/cpp/project/SDL_Fractal/src/main.cpp"

CMakeFiles/SDL_Fractal.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL_Fractal.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/sv/ucu/Semester 1/cpp/project/SDL_Fractal/src/main.cpp" > CMakeFiles/SDL_Fractal.dir/src/main.cpp.i

CMakeFiles/SDL_Fractal.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL_Fractal.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/sv/ucu/Semester 1/cpp/project/SDL_Fractal/src/main.cpp" -o CMakeFiles/SDL_Fractal.dir/src/main.cpp.s

CMakeFiles/SDL_Fractal.dir/src/graphics.cpp.o: CMakeFiles/SDL_Fractal.dir/flags.make
CMakeFiles/SDL_Fractal.dir/src/graphics.cpp.o: ../src/graphics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/sv/ucu/Semester 1/cpp/project/SDL_Fractal/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SDL_Fractal.dir/src/graphics.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SDL_Fractal.dir/src/graphics.cpp.o -c "/Users/sv/ucu/Semester 1/cpp/project/SDL_Fractal/src/graphics.cpp"

CMakeFiles/SDL_Fractal.dir/src/graphics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL_Fractal.dir/src/graphics.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/sv/ucu/Semester 1/cpp/project/SDL_Fractal/src/graphics.cpp" > CMakeFiles/SDL_Fractal.dir/src/graphics.cpp.i

CMakeFiles/SDL_Fractal.dir/src/graphics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL_Fractal.dir/src/graphics.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/sv/ucu/Semester 1/cpp/project/SDL_Fractal/src/graphics.cpp" -o CMakeFiles/SDL_Fractal.dir/src/graphics.cpp.s

# Object files for target SDL_Fractal
SDL_Fractal_OBJECTS = \
"CMakeFiles/SDL_Fractal.dir/src/main.cpp.o" \
"CMakeFiles/SDL_Fractal.dir/src/graphics.cpp.o"

# External object files for target SDL_Fractal
SDL_Fractal_EXTERNAL_OBJECTS =

bin/SDL_Fractal: CMakeFiles/SDL_Fractal.dir/src/main.cpp.o
bin/SDL_Fractal: CMakeFiles/SDL_Fractal.dir/src/graphics.cpp.o
bin/SDL_Fractal: CMakeFiles/SDL_Fractal.dir/build.make
bin/SDL_Fractal: /usr/local/lib/libSDL2main.a
bin/SDL_Fractal: /usr/local/lib/libSDL2.dylib
bin/SDL_Fractal: /usr/local/lib/libSDL2_ttf.dylib
bin/SDL_Fractal: /usr/local/lib/libSDL2_ttf.dylib
bin/SDL_Fractal: /usr/local/lib/libSDL2_image.dylib
bin/SDL_Fractal: /usr/local/lib/libSDL2_mixer.dylib
bin/SDL_Fractal: CMakeFiles/SDL_Fractal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/sv/ucu/Semester 1/cpp/project/SDL_Fractal/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable bin/SDL_Fractal"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SDL_Fractal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SDL_Fractal.dir/build: bin/SDL_Fractal

.PHONY : CMakeFiles/SDL_Fractal.dir/build

CMakeFiles/SDL_Fractal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SDL_Fractal.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SDL_Fractal.dir/clean

CMakeFiles/SDL_Fractal.dir/depend:
	cd "/Users/sv/ucu/Semester 1/cpp/project/SDL_Fractal/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/sv/ucu/Semester 1/cpp/project/SDL_Fractal" "/Users/sv/ucu/Semester 1/cpp/project/SDL_Fractal" "/Users/sv/ucu/Semester 1/cpp/project/SDL_Fractal/cmake-build-debug" "/Users/sv/ucu/Semester 1/cpp/project/SDL_Fractal/cmake-build-debug" "/Users/sv/ucu/Semester 1/cpp/project/SDL_Fractal/cmake-build-debug/CMakeFiles/SDL_Fractal.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/SDL_Fractal.dir/depend

