# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.24.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.24.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/maddiewisinski/Documents/GitHub/game-project-impostor/joust-remake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/maddiewisinski/Documents/GitHub/game-project-impostor/build

# Include any dependencies generated for this target.
include CMakeFiles/joust-remake.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/joust-remake.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/joust-remake.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/joust-remake.dir/flags.make

CMakeFiles/joust-remake.dir/source/Game.cpp.o: CMakeFiles/joust-remake.dir/flags.make
CMakeFiles/joust-remake.dir/source/Game.cpp.o: /Users/maddiewisinski/Documents/GitHub/game-project-impostor/joust-remake/source/Game.cpp
CMakeFiles/joust-remake.dir/source/Game.cpp.o: CMakeFiles/joust-remake.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maddiewisinski/Documents/GitHub/game-project-impostor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/joust-remake.dir/source/Game.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/joust-remake.dir/source/Game.cpp.o -MF CMakeFiles/joust-remake.dir/source/Game.cpp.o.d -o CMakeFiles/joust-remake.dir/source/Game.cpp.o -c /Users/maddiewisinski/Documents/GitHub/game-project-impostor/joust-remake/source/Game.cpp

CMakeFiles/joust-remake.dir/source/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/joust-remake.dir/source/Game.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maddiewisinski/Documents/GitHub/game-project-impostor/joust-remake/source/Game.cpp > CMakeFiles/joust-remake.dir/source/Game.cpp.i

CMakeFiles/joust-remake.dir/source/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/joust-remake.dir/source/Game.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maddiewisinski/Documents/GitHub/game-project-impostor/joust-remake/source/Game.cpp -o CMakeFiles/joust-remake.dir/source/Game.cpp.s

CMakeFiles/joust-remake.dir/source/utils/u8names.cpp.o: CMakeFiles/joust-remake.dir/flags.make
CMakeFiles/joust-remake.dir/source/utils/u8names.cpp.o: /Users/maddiewisinski/Documents/GitHub/game-project-impostor/joust-remake/source/utils/u8names.cpp
CMakeFiles/joust-remake.dir/source/utils/u8names.cpp.o: CMakeFiles/joust-remake.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maddiewisinski/Documents/GitHub/game-project-impostor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/joust-remake.dir/source/utils/u8names.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/joust-remake.dir/source/utils/u8names.cpp.o -MF CMakeFiles/joust-remake.dir/source/utils/u8names.cpp.o.d -o CMakeFiles/joust-remake.dir/source/utils/u8names.cpp.o -c /Users/maddiewisinski/Documents/GitHub/game-project-impostor/joust-remake/source/utils/u8names.cpp

CMakeFiles/joust-remake.dir/source/utils/u8names.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/joust-remake.dir/source/utils/u8names.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maddiewisinski/Documents/GitHub/game-project-impostor/joust-remake/source/utils/u8names.cpp > CMakeFiles/joust-remake.dir/source/utils/u8names.cpp.i

CMakeFiles/joust-remake.dir/source/utils/u8names.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/joust-remake.dir/source/utils/u8names.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maddiewisinski/Documents/GitHub/game-project-impostor/joust-remake/source/utils/u8names.cpp -o CMakeFiles/joust-remake.dir/source/utils/u8names.cpp.s

CMakeFiles/joust-remake.dir/source/utils/lodepng.cpp.o: CMakeFiles/joust-remake.dir/flags.make
CMakeFiles/joust-remake.dir/source/utils/lodepng.cpp.o: /Users/maddiewisinski/Documents/GitHub/game-project-impostor/joust-remake/source/utils/lodepng.cpp
CMakeFiles/joust-remake.dir/source/utils/lodepng.cpp.o: CMakeFiles/joust-remake.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maddiewisinski/Documents/GitHub/game-project-impostor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/joust-remake.dir/source/utils/lodepng.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/joust-remake.dir/source/utils/lodepng.cpp.o -MF CMakeFiles/joust-remake.dir/source/utils/lodepng.cpp.o.d -o CMakeFiles/joust-remake.dir/source/utils/lodepng.cpp.o -c /Users/maddiewisinski/Documents/GitHub/game-project-impostor/joust-remake/source/utils/lodepng.cpp

CMakeFiles/joust-remake.dir/source/utils/lodepng.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/joust-remake.dir/source/utils/lodepng.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maddiewisinski/Documents/GitHub/game-project-impostor/joust-remake/source/utils/lodepng.cpp > CMakeFiles/joust-remake.dir/source/utils/lodepng.cpp.i

CMakeFiles/joust-remake.dir/source/utils/lodepng.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/joust-remake.dir/source/utils/lodepng.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maddiewisinski/Documents/GitHub/game-project-impostor/joust-remake/source/utils/lodepng.cpp -o CMakeFiles/joust-remake.dir/source/utils/lodepng.cpp.s

CMakeFiles/joust-remake.dir/source/path/path.cpp.o: CMakeFiles/joust-remake.dir/flags.make
CMakeFiles/joust-remake.dir/source/path/path.cpp.o: /Users/maddiewisinski/Documents/GitHub/game-project-impostor/joust-remake/source/path/path.cpp
CMakeFiles/joust-remake.dir/source/path/path.cpp.o: CMakeFiles/joust-remake.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maddiewisinski/Documents/GitHub/game-project-impostor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/joust-remake.dir/source/path/path.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/joust-remake.dir/source/path/path.cpp.o -MF CMakeFiles/joust-remake.dir/source/path/path.cpp.o.d -o CMakeFiles/joust-remake.dir/source/path/path.cpp.o -c /Users/maddiewisinski/Documents/GitHub/game-project-impostor/joust-remake/source/path/path.cpp

CMakeFiles/joust-remake.dir/source/path/path.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/joust-remake.dir/source/path/path.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maddiewisinski/Documents/GitHub/game-project-impostor/joust-remake/source/path/path.cpp > CMakeFiles/joust-remake.dir/source/path/path.cpp.i

CMakeFiles/joust-remake.dir/source/path/path.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/joust-remake.dir/source/path/path.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maddiewisinski/Documents/GitHub/game-project-impostor/joust-remake/source/path/path.cpp -o CMakeFiles/joust-remake.dir/source/path/path.cpp.s

CMakeFiles/joust-remake.dir/source/main.cpp.o: CMakeFiles/joust-remake.dir/flags.make
CMakeFiles/joust-remake.dir/source/main.cpp.o: /Users/maddiewisinski/Documents/GitHub/game-project-impostor/joust-remake/source/main.cpp
CMakeFiles/joust-remake.dir/source/main.cpp.o: CMakeFiles/joust-remake.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maddiewisinski/Documents/GitHub/game-project-impostor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/joust-remake.dir/source/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/joust-remake.dir/source/main.cpp.o -MF CMakeFiles/joust-remake.dir/source/main.cpp.o.d -o CMakeFiles/joust-remake.dir/source/main.cpp.o -c /Users/maddiewisinski/Documents/GitHub/game-project-impostor/joust-remake/source/main.cpp

CMakeFiles/joust-remake.dir/source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/joust-remake.dir/source/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maddiewisinski/Documents/GitHub/game-project-impostor/joust-remake/source/main.cpp > CMakeFiles/joust-remake.dir/source/main.cpp.i

CMakeFiles/joust-remake.dir/source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/joust-remake.dir/source/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maddiewisinski/Documents/GitHub/game-project-impostor/joust-remake/source/main.cpp -o CMakeFiles/joust-remake.dir/source/main.cpp.s

CMakeFiles/joust-remake.dir/source/Bird.cpp.o: CMakeFiles/joust-remake.dir/flags.make
CMakeFiles/joust-remake.dir/source/Bird.cpp.o: /Users/maddiewisinski/Documents/GitHub/game-project-impostor/joust-remake/source/Bird.cpp
CMakeFiles/joust-remake.dir/source/Bird.cpp.o: CMakeFiles/joust-remake.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maddiewisinski/Documents/GitHub/game-project-impostor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/joust-remake.dir/source/Bird.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/joust-remake.dir/source/Bird.cpp.o -MF CMakeFiles/joust-remake.dir/source/Bird.cpp.o.d -o CMakeFiles/joust-remake.dir/source/Bird.cpp.o -c /Users/maddiewisinski/Documents/GitHub/game-project-impostor/joust-remake/source/Bird.cpp

CMakeFiles/joust-remake.dir/source/Bird.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/joust-remake.dir/source/Bird.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maddiewisinski/Documents/GitHub/game-project-impostor/joust-remake/source/Bird.cpp > CMakeFiles/joust-remake.dir/source/Bird.cpp.i

CMakeFiles/joust-remake.dir/source/Bird.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/joust-remake.dir/source/Bird.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maddiewisinski/Documents/GitHub/game-project-impostor/joust-remake/source/Bird.cpp -o CMakeFiles/joust-remake.dir/source/Bird.cpp.s

# Object files for target joust-remake
joust__remake_OBJECTS = \
"CMakeFiles/joust-remake.dir/source/Game.cpp.o" \
"CMakeFiles/joust-remake.dir/source/utils/u8names.cpp.o" \
"CMakeFiles/joust-remake.dir/source/utils/lodepng.cpp.o" \
"CMakeFiles/joust-remake.dir/source/path/path.cpp.o" \
"CMakeFiles/joust-remake.dir/source/main.cpp.o" \
"CMakeFiles/joust-remake.dir/source/Bird.cpp.o"

# External object files for target joust-remake
joust__remake_EXTERNAL_OBJECTS =

joust-remake.app/Contents/MacOS/joust-remake: CMakeFiles/joust-remake.dir/source/Game.cpp.o
joust-remake.app/Contents/MacOS/joust-remake: CMakeFiles/joust-remake.dir/source/utils/u8names.cpp.o
joust-remake.app/Contents/MacOS/joust-remake: CMakeFiles/joust-remake.dir/source/utils/lodepng.cpp.o
joust-remake.app/Contents/MacOS/joust-remake: CMakeFiles/joust-remake.dir/source/path/path.cpp.o
joust-remake.app/Contents/MacOS/joust-remake: CMakeFiles/joust-remake.dir/source/main.cpp.o
joust-remake.app/Contents/MacOS/joust-remake: CMakeFiles/joust-remake.dir/source/Bird.cpp.o
joust-remake.app/Contents/MacOS/joust-remake: CMakeFiles/joust-remake.dir/build.make
joust-remake.app/Contents/MacOS/joust-remake: glfw-3.3.7/src/libglfw3.a
joust-remake.app/Contents/MacOS/joust-remake: libglad.a
joust-remake.app/Contents/MacOS/joust-remake: glfw-3.3.7/src/libglfw3.a
joust-remake.app/Contents/MacOS/joust-remake: CMakeFiles/joust-remake.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/maddiewisinski/Documents/GitHub/game-project-impostor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable joust-remake.app/Contents/MacOS/joust-remake"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/joust-remake.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/joust-remake.dir/build: joust-remake.app/Contents/MacOS/joust-remake
.PHONY : CMakeFiles/joust-remake.dir/build

CMakeFiles/joust-remake.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/joust-remake.dir/cmake_clean.cmake
.PHONY : CMakeFiles/joust-remake.dir/clean

CMakeFiles/joust-remake.dir/depend:
	cd /Users/maddiewisinski/Documents/GitHub/game-project-impostor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/maddiewisinski/Documents/GitHub/game-project-impostor/joust-remake /Users/maddiewisinski/Documents/GitHub/game-project-impostor/joust-remake /Users/maddiewisinski/Documents/GitHub/game-project-impostor/build /Users/maddiewisinski/Documents/GitHub/game-project-impostor/build /Users/maddiewisinski/Documents/GitHub/game-project-impostor/build/CMakeFiles/joust-remake.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/joust-remake.dir/depend

