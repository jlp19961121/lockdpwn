# Install script for directory: /home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/src

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/install")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
        file(MAKE_DIRECTORY "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
      endif()
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin")
        file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin" "")
      endif()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/install/_setup_util.py")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/install" TYPE PROGRAM FILES "/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/catkin_generated/installspace/_setup_util.py")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/install/env.sh")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/install" TYPE PROGRAM FILES "/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/catkin_generated/installspace/env.sh")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/install/setup.bash")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/install" TYPE FILE FILES "/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/catkin_generated/installspace/setup.bash")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/install/setup.sh")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/install" TYPE FILE FILES "/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/catkin_generated/installspace/setup.sh")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/install/setup.zsh")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/install" TYPE FILE FILES "/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/catkin_generated/installspace/setup.zsh")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/install/.rosinstall")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/install" TYPE FILE FILES "/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/catkin_generated/installspace/.rosinstall")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/gtest/cmake_install.cmake")
  INCLUDE("/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/chefbot_simulator/chefbot_gazebo/cmake_install.cmake")
  INCLUDE("/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/tortoisebot/cmake_install.cmake")
  INCLUDE("/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/cougarbot/cmake_install.cmake")
  INCLUDE("/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/cougarbot_moveit_config/cmake_install.cmake")
  INCLUDE("/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/followbot/cmake_install.cmake")
  INCLUDE("/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/mapping/cmake_install.cmake")
  INCLUDE("/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/stockroom_bot/cmake_install.cmake")
  INCLUDE("/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/basics/cmake_install.cmake")
  INCLUDE("/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/diff_wheeled_robot_control/cmake_install.cmake")
  INCLUDE("/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/mastering_ros_demo_pkg/cmake_install.cmake")
  INCLUDE("/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/chefbot_navig_cpp/cmake_install.cmake")
  INCLUDE("/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/pcl_ros_tutorial/cmake_install.cmake")
  INCLUDE("/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/my_controller_pkg/cmake_install.cmake")
  INCLUDE("/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/chefbot_bringup/cmake_install.cmake")
  INCLUDE("/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/wanderbot/cmake_install.cmake")
  INCLUDE("/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/chefbot_description/cmake_install.cmake")
  INCLUDE("/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/mastering_ros_robot_description_pkg/cmake_install.cmake")
  INCLUDE("/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/diff_wheeled_robot_gazebo/cmake_install.cmake")
  INCLUDE("/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/seven_dof_arm_config/cmake_install.cmake")
  INCLUDE("/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/seven_dof_arm_gazebo/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/home/dyros-vehicle/gitrepo/lockdpwn/ROS/rosbook_ws/build/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
