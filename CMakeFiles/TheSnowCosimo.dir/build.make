# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/bitrey/TheSnowCosimo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bitrey/TheSnowCosimo

# Include any dependencies generated for this target.
include CMakeFiles/TheSnowCosimo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TheSnowCosimo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TheSnowCosimo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TheSnowCosimo.dir/flags.make

CMakeFiles/TheSnowCosimo.dir/main.cpp.o: CMakeFiles/TheSnowCosimo.dir/flags.make
CMakeFiles/TheSnowCosimo.dir/main.cpp.o: main.cpp
CMakeFiles/TheSnowCosimo.dir/main.cpp.o: CMakeFiles/TheSnowCosimo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bitrey/TheSnowCosimo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TheSnowCosimo.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TheSnowCosimo.dir/main.cpp.o -MF CMakeFiles/TheSnowCosimo.dir/main.cpp.o.d -o CMakeFiles/TheSnowCosimo.dir/main.cpp.o -c /home/bitrey/TheSnowCosimo/main.cpp

CMakeFiles/TheSnowCosimo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TheSnowCosimo.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bitrey/TheSnowCosimo/main.cpp > CMakeFiles/TheSnowCosimo.dir/main.cpp.i

CMakeFiles/TheSnowCosimo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TheSnowCosimo.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bitrey/TheSnowCosimo/main.cpp -o CMakeFiles/TheSnowCosimo.dir/main.cpp.s

CMakeFiles/TheSnowCosimo.dir/backend/components/map/chunk/Chunk.cpp.o: CMakeFiles/TheSnowCosimo.dir/flags.make
CMakeFiles/TheSnowCosimo.dir/backend/components/map/chunk/Chunk.cpp.o: backend/components/map/chunk/Chunk.cpp
CMakeFiles/TheSnowCosimo.dir/backend/components/map/chunk/Chunk.cpp.o: CMakeFiles/TheSnowCosimo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bitrey/TheSnowCosimo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TheSnowCosimo.dir/backend/components/map/chunk/Chunk.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TheSnowCosimo.dir/backend/components/map/chunk/Chunk.cpp.o -MF CMakeFiles/TheSnowCosimo.dir/backend/components/map/chunk/Chunk.cpp.o.d -o CMakeFiles/TheSnowCosimo.dir/backend/components/map/chunk/Chunk.cpp.o -c /home/bitrey/TheSnowCosimo/backend/components/map/chunk/Chunk.cpp

CMakeFiles/TheSnowCosimo.dir/backend/components/map/chunk/Chunk.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TheSnowCosimo.dir/backend/components/map/chunk/Chunk.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bitrey/TheSnowCosimo/backend/components/map/chunk/Chunk.cpp > CMakeFiles/TheSnowCosimo.dir/backend/components/map/chunk/Chunk.cpp.i

CMakeFiles/TheSnowCosimo.dir/backend/components/map/chunk/Chunk.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TheSnowCosimo.dir/backend/components/map/chunk/Chunk.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bitrey/TheSnowCosimo/backend/components/map/chunk/Chunk.cpp -o CMakeFiles/TheSnowCosimo.dir/backend/components/map/chunk/Chunk.cpp.s

CMakeFiles/TheSnowCosimo.dir/backend/components/map/Level.cpp.o: CMakeFiles/TheSnowCosimo.dir/flags.make
CMakeFiles/TheSnowCosimo.dir/backend/components/map/Level.cpp.o: backend/components/map/Level.cpp
CMakeFiles/TheSnowCosimo.dir/backend/components/map/Level.cpp.o: CMakeFiles/TheSnowCosimo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bitrey/TheSnowCosimo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TheSnowCosimo.dir/backend/components/map/Level.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TheSnowCosimo.dir/backend/components/map/Level.cpp.o -MF CMakeFiles/TheSnowCosimo.dir/backend/components/map/Level.cpp.o.d -o CMakeFiles/TheSnowCosimo.dir/backend/components/map/Level.cpp.o -c /home/bitrey/TheSnowCosimo/backend/components/map/Level.cpp

CMakeFiles/TheSnowCosimo.dir/backend/components/map/Level.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TheSnowCosimo.dir/backend/components/map/Level.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bitrey/TheSnowCosimo/backend/components/map/Level.cpp > CMakeFiles/TheSnowCosimo.dir/backend/components/map/Level.cpp.i

CMakeFiles/TheSnowCosimo.dir/backend/components/map/Level.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TheSnowCosimo.dir/backend/components/map/Level.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bitrey/TheSnowCosimo/backend/components/map/Level.cpp -o CMakeFiles/TheSnowCosimo.dir/backend/components/map/Level.cpp.s

CMakeFiles/TheSnowCosimo.dir/backend/components/entity/Entity.cpp.o: CMakeFiles/TheSnowCosimo.dir/flags.make
CMakeFiles/TheSnowCosimo.dir/backend/components/entity/Entity.cpp.o: backend/components/entity/Entity.cpp
CMakeFiles/TheSnowCosimo.dir/backend/components/entity/Entity.cpp.o: CMakeFiles/TheSnowCosimo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bitrey/TheSnowCosimo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TheSnowCosimo.dir/backend/components/entity/Entity.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TheSnowCosimo.dir/backend/components/entity/Entity.cpp.o -MF CMakeFiles/TheSnowCosimo.dir/backend/components/entity/Entity.cpp.o.d -o CMakeFiles/TheSnowCosimo.dir/backend/components/entity/Entity.cpp.o -c /home/bitrey/TheSnowCosimo/backend/components/entity/Entity.cpp

CMakeFiles/TheSnowCosimo.dir/backend/components/entity/Entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TheSnowCosimo.dir/backend/components/entity/Entity.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bitrey/TheSnowCosimo/backend/components/entity/Entity.cpp > CMakeFiles/TheSnowCosimo.dir/backend/components/entity/Entity.cpp.i

CMakeFiles/TheSnowCosimo.dir/backend/components/entity/Entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TheSnowCosimo.dir/backend/components/entity/Entity.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bitrey/TheSnowCosimo/backend/components/entity/Entity.cpp -o CMakeFiles/TheSnowCosimo.dir/backend/components/entity/Entity.cpp.s

# Object files for target TheSnowCosimo
TheSnowCosimo_OBJECTS = \
"CMakeFiles/TheSnowCosimo.dir/main.cpp.o" \
"CMakeFiles/TheSnowCosimo.dir/backend/components/map/chunk/Chunk.cpp.o" \
"CMakeFiles/TheSnowCosimo.dir/backend/components/map/Level.cpp.o" \
"CMakeFiles/TheSnowCosimo.dir/backend/components/entity/Entity.cpp.o"

# External object files for target TheSnowCosimo
TheSnowCosimo_EXTERNAL_OBJECTS =

TheSnowCosimo: CMakeFiles/TheSnowCosimo.dir/main.cpp.o
TheSnowCosimo: CMakeFiles/TheSnowCosimo.dir/backend/components/map/chunk/Chunk.cpp.o
TheSnowCosimo: CMakeFiles/TheSnowCosimo.dir/backend/components/map/Level.cpp.o
TheSnowCosimo: CMakeFiles/TheSnowCosimo.dir/backend/components/entity/Entity.cpp.o
TheSnowCosimo: CMakeFiles/TheSnowCosimo.dir/build.make
TheSnowCosimo: /usr/lib/x86_64-linux-gnu/libcurses.so
TheSnowCosimo: /usr/lib/x86_64-linux-gnu/libform.so
TheSnowCosimo: CMakeFiles/TheSnowCosimo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bitrey/TheSnowCosimo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable TheSnowCosimo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TheSnowCosimo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TheSnowCosimo.dir/build: TheSnowCosimo
.PHONY : CMakeFiles/TheSnowCosimo.dir/build

CMakeFiles/TheSnowCosimo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TheSnowCosimo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TheSnowCosimo.dir/clean

CMakeFiles/TheSnowCosimo.dir/depend:
	cd /home/bitrey/TheSnowCosimo && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bitrey/TheSnowCosimo /home/bitrey/TheSnowCosimo /home/bitrey/TheSnowCosimo /home/bitrey/TheSnowCosimo /home/bitrey/TheSnowCosimo/CMakeFiles/TheSnowCosimo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TheSnowCosimo.dir/depend
