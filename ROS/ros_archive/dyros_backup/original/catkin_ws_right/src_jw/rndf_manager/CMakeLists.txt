cmake_minimum_required(VERSION 2.8.3)
project(rndf_manager)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
  cmake_modules
)
find_package(Eigen REQUIRED)
##################################### QT ##########################################
find_package(Qt4 REQUIRED COMPONENTS QtCore QtGui)
set( QT_USE_QTOPENGL TRUE )
set( QT_USE_QTXML TRUE )
set( QT_USE_QTWEBKIT TRUE )

include(${QT_USE_FILE})

###################################################################################

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend and a run_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependencies might have been
##     pulled in transitively but can be declared for certainty nonetheless:
##     * add a build_depend tag for "message_generation"
##     * add a run_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
 add_service_files(
   DIRECTORY srv
   FILES
   srvHeightMap.srv
 )
## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
   std_msgs
 )

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS inc
#  LIBRARIES lib
  CATKIN_DEPENDS roscpp std_msgs
  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  ${catkin_INCLUDE_DIRS}
  ${Eigen_INCLUDE_DIRS}
)

## Declare a cpp library
# add_library(ompl_qt_pkg
#   src/${PROJECT_NAME}/ompl_qt_pkg.cpp
# )

######################## test_ui_node #################################

set( HDR_FILES_QT_UI_NODE1 inc/rndf_manager_main.h inc/RNDF_LIB/parse_rndf_mdf.h inc/RNDF_LIB/rndf_mdf_reader.h inc/MsgManagerThread.h inc/ShortestPath.h)
set( SRC_FILES_QT_UI_NODE1 src/rndf_manager_main.cpp src/RNDF_LIB/parse_rndf_mdf.cpp src/RNDF_LIB/rndf_mdf_reader.cpp  src/MsgManagerThread.cpp src/ShortestPath.cpp ${MOC_FILES})
set( FORM_FILES_QT_UI_NODE1 ui/rndf_manager_gui.ui)

QT4_WRAP_CPP(MOC_SRC_H_QT_UI_NODE1 ${HDR_FILES_QT_UI_NODE1})
QT4_WRAP_UI(MOC_GUI_H_QT_UI_NODE1 ${FORM_FILES_QT_UI_NODE1})

## Declare a cpp executable
add_executable(rndf_manager ${SRC_FILES_QT_UI_NODE1} ${HDR_FILES_QT_UI_NODE1} ${MOC_SRC_H_QT_UI_NODE1} ${MOC_GUI_H_QT_UI_NODE1})
                           
## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
# add_dependencies(ompl_qt_pkg_node ompl_qt_pkg_generate_messages_cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(rndf_manager
   ${QT_LIBRARIES}
   ${catkin_LIBRARIES}
   ${Eigen_LIBRARIES}
 )


FIND_PACKAGE(Boost)
if(EXISTS ${Boost_INCLUDE_DIR})
  include_directories(${Boost_INCLUDE_DIR})
else(EXISTS ${Boost_INCLUDE_DIR})
  MESSAGE(FATAL_ERROR "Could not find Boost")
endif(EXISTS ${Boost_INCLUDE_DIR})
if(EXISTS ${Boost_LIBRARY_DIRS})
  link_directories(${Boost_LIBRARY_DIRS})
else(EXISTS ${Boost_LIBRARY_DIRS})
  MESSAGE(FATAL_ERROR "Could not find Boost")
endif(EXISTS ${Boost_LIBRARY_DIRS})

#######################################################################


#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables and/or libraries for installation
# install(TARGETS ompl_qt_pkg ompl_qt_pkg_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_ompl_qt_pkg.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
