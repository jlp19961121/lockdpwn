# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/build

# Include any dependencies generated for this target.
include arduino_test/CMakeFiles/arduino_test.dir/depend.make

# Include the progress variables for this target.
include arduino_test/CMakeFiles/arduino_test.dir/progress.make

# Include the compile flags for this target's objects.
include arduino_test/CMakeFiles/arduino_test.dir/flags.make

arduino_test/CMakeFiles/arduino_test.dir/src/arduino_test.cpp.o: arduino_test/CMakeFiles/arduino_test.dir/flags.make
arduino_test/CMakeFiles/arduino_test.dir/src/arduino_test.cpp.o: /home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/src/arduino_test/src/arduino_test.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object arduino_test/CMakeFiles/arduino_test.dir/src/arduino_test.cpp.o"
	cd /home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/build/arduino_test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/arduino_test.dir/src/arduino_test.cpp.o -c /home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/src/arduino_test/src/arduino_test.cpp

arduino_test/CMakeFiles/arduino_test.dir/src/arduino_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arduino_test.dir/src/arduino_test.cpp.i"
	cd /home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/build/arduino_test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/src/arduino_test/src/arduino_test.cpp > CMakeFiles/arduino_test.dir/src/arduino_test.cpp.i

arduino_test/CMakeFiles/arduino_test.dir/src/arduino_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arduino_test.dir/src/arduino_test.cpp.s"
	cd /home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/build/arduino_test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/src/arduino_test/src/arduino_test.cpp -o CMakeFiles/arduino_test.dir/src/arduino_test.cpp.s

arduino_test/CMakeFiles/arduino_test.dir/src/arduino_test.cpp.o.requires:
.PHONY : arduino_test/CMakeFiles/arduino_test.dir/src/arduino_test.cpp.o.requires

arduino_test/CMakeFiles/arduino_test.dir/src/arduino_test.cpp.o.provides: arduino_test/CMakeFiles/arduino_test.dir/src/arduino_test.cpp.o.requires
	$(MAKE) -f arduino_test/CMakeFiles/arduino_test.dir/build.make arduino_test/CMakeFiles/arduino_test.dir/src/arduino_test.cpp.o.provides.build
.PHONY : arduino_test/CMakeFiles/arduino_test.dir/src/arduino_test.cpp.o.provides

arduino_test/CMakeFiles/arduino_test.dir/src/arduino_test.cpp.o.provides.build: arduino_test/CMakeFiles/arduino_test.dir/src/arduino_test.cpp.o

# Object files for target arduino_test
arduino_test_OBJECTS = \
"CMakeFiles/arduino_test.dir/src/arduino_test.cpp.o"

# External object files for target arduino_test
arduino_test_EXTERNAL_OBJECTS =

/home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/devel/lib/arduino_test/arduino_test: arduino_test/CMakeFiles/arduino_test.dir/src/arduino_test.cpp.o
/home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/devel/lib/arduino_test/arduino_test: arduino_test/CMakeFiles/arduino_test.dir/build.make
/home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/devel/lib/arduino_test/arduino_test: /opt/ros/indigo/lib/libroscpp.so
/home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/devel/lib/arduino_test/arduino_test: /usr/lib/arm-linux-gnueabihf/libboost_signals.so
/home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/devel/lib/arduino_test/arduino_test: /usr/lib/arm-linux-gnueabihf/libboost_filesystem.so
/home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/devel/lib/arduino_test/arduino_test: /opt/ros/indigo/lib/librosconsole.so
/home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/devel/lib/arduino_test/arduino_test: /opt/ros/indigo/lib/librosconsole_log4cxx.so
/home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/devel/lib/arduino_test/arduino_test: /opt/ros/indigo/lib/librosconsole_backend_interface.so
/home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/devel/lib/arduino_test/arduino_test: /usr/lib/liblog4cxx.so
/home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/devel/lib/arduino_test/arduino_test: /usr/lib/arm-linux-gnueabihf/libboost_regex.so
/home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/devel/lib/arduino_test/arduino_test: /opt/ros/indigo/lib/libxmlrpcpp.so
/home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/devel/lib/arduino_test/arduino_test: /opt/ros/indigo/lib/libroscpp_serialization.so
/home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/devel/lib/arduino_test/arduino_test: /opt/ros/indigo/lib/librostime.so
/home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/devel/lib/arduino_test/arduino_test: /usr/lib/arm-linux-gnueabihf/libboost_date_time.so
/home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/devel/lib/arduino_test/arduino_test: /opt/ros/indigo/lib/libcpp_common.so
/home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/devel/lib/arduino_test/arduino_test: /usr/lib/arm-linux-gnueabihf/libboost_system.so
/home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/devel/lib/arduino_test/arduino_test: /usr/lib/arm-linux-gnueabihf/libboost_thread.so
/home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/devel/lib/arduino_test/arduino_test: /usr/lib/arm-linux-gnueabihf/libpthread.so
/home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/devel/lib/arduino_test/arduino_test: /usr/lib/arm-linux-gnueabihf/libconsole_bridge.so
/home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/devel/lib/arduino_test/arduino_test: arduino_test/CMakeFiles/arduino_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/devel/lib/arduino_test/arduino_test"
	cd /home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/build/arduino_test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/arduino_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
arduino_test/CMakeFiles/arduino_test.dir/build: /home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/devel/lib/arduino_test/arduino_test
.PHONY : arduino_test/CMakeFiles/arduino_test.dir/build

arduino_test/CMakeFiles/arduino_test.dir/requires: arduino_test/CMakeFiles/arduino_test.dir/src/arduino_test.cpp.o.requires
.PHONY : arduino_test/CMakeFiles/arduino_test.dir/requires

arduino_test/CMakeFiles/arduino_test.dir/clean:
	cd /home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/build/arduino_test && $(CMAKE_COMMAND) -P CMakeFiles/arduino_test.dir/cmake_clean.cmake
.PHONY : arduino_test/CMakeFiles/arduino_test.dir/clean

arduino_test/CMakeFiles/arduino_test.dir/depend:
	cd /home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/src /home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/src/arduino_test /home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/build /home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/build/arduino_test /home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/build/arduino_test/CMakeFiles/arduino_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : arduino_test/CMakeFiles/arduino_test.dir/depend

