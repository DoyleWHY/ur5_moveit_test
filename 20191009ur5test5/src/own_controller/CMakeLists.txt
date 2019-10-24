##############################################################################
# 1 CMake
##############################################################################
    cmake_minimum_required(VERSION 2.8.3)
    project(own_controller)
    add_definitions(-std=c++11)

##############################################################################
# 2 Catkin
##############################################################################
    find_package(catkin REQUIRED COMPONENTS
      roscpp
      moveit_ros_planning_interface
      rviz_visual_tools
    )

    catkin_package(
        CATKIN_DEPENDS roscpp rviz_visual_tools
        LIBRARIES moveit_ros_planning_interface
    )

###########
## Build ##
###########

    include_directories(
        include
        ${catkin_INCLUDE_DIRS}
    )

    ## Declare a C++ library
#    add_library(${PROJECT_NAME}
#        ${catkin_INCLUDE_DIRS}
#        src/testmain.cpp
#        src/testmain2.cpp
#    )

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

include_directories($ {EIGEN3_INCLUDE_DIRS})

add_executable(testcontroller src/testmain.cpp)
add_dependencies(testcontroller ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(testcontroller ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#install(TARGETS testcontroller DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

add_executable(testcontroller2 src/testmain2.cpp)
add_dependencies(testcontroller2 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(testcontroller2 ${catkin_LIBRARIES} ${Boost_LIBRARIES})
#install(TARGETS testcontroller2 DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

#install(DIRECTORY launch DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
