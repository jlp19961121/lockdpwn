# Install script for directory: /home/dyros-vehicle/gitrepo/lockdpwn/ROS/catkin_ws/src/torcs_ros/torcs_ros_drive_ctrl

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/dyros-vehicle/gitrepo/lockdpwn/ROS/catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/dyros-vehicle/gitrepo/lockdpwn/ROS/catkin_ws/build/torcs_ros/torcs_ros_drive_ctrl/catkin_generated/installspace/torcs_ros_drive_ctrl.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/torcs_ros_drive_ctrl/cmake" TYPE FILE FILES
    "/home/dyros-vehicle/gitrepo/lockdpwn/ROS/catkin_ws/build/torcs_ros/torcs_ros_drive_ctrl/catkin_generated/installspace/torcs_ros_drive_ctrlConfig.cmake"
    "/home/dyros-vehicle/gitrepo/lockdpwn/ROS/catkin_ws/build/torcs_ros/torcs_ros_drive_ctrl/catkin_generated/installspace/torcs_ros_drive_ctrlConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/torcs_ros_drive_ctrl" TYPE FILE FILES "/home/dyros-vehicle/gitrepo/lockdpwn/ROS/catkin_ws/src/torcs_ros/torcs_ros_drive_ctrl/package.xml")
endif()
