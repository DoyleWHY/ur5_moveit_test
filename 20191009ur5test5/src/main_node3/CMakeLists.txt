cmake_minimum_required(VERSION 2.8.3)
project(main_node3)


find_package(catkin REQUIRED COMPONENTS message_generation std_msgs roscpp moveit_ros_planning_interface rviz_visual_tools gazebo_msgs geometry_msgs std_srvs)

## 消息声明：MsgTutorial.msg
add_message_files(FILES MsgTutorial.msg)
add_message_files(FILES blocks_poses.msg)
add_message_files(FILES Tracker.msg)
## 这是设置依赖性消息的选项。
## 如果未安装std_msgs，则在构建过程中会发生错误。
generate_messages(DEPENDENCIES std_msgs)
## catkin功能包选项，描述了库、catkin构建依赖项和系统依赖的功能包。

catkin_package(
    LIBRARIES ros_tutorials_topic rviz_visual_tools
    CATKIN_DEPENDS std_msgs roscpp
    LIBRARIES moveit_ros_planning_interface
)

find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

ADD_DEFINITIONS(${QT_DEFINITIONS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

#target_link_libraries(main_node2 Qt5::Widgets)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_HEADER_FILES
    gui/form.h
    ros_connect/simnode.h
    ros_connect/qnode.h
    ros_connect/tf_node.h
    )
set(QT_SOURCE_FILES
    gui/form.cpp
    ros_connect/simnode.cpp
    ros_connect/qnode.cpp
    ros_connect/tf_node.cpp
    ${MOC_FILES}
    )
set(QT_FORM_FILES
    gui/form.ui
    )

set(GLOBALS_SOURCE_FILES
    vars/cglobal.cpp
    )

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

include_directories($ {EIGEN3_INCLUDE_DIRS})

add_executable(main_88 src/main_node.cpp ${QT_SOURCE_FILES} ${QT_MOC_HPP} ${QT_FORMS_HPP} ${GLOBALS_SOURCE_FILES})
add_dependencies(main_88 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(main_88 Qt5::Widgets Qt5::Core Qt5::Gui ${QT_LIBRARIES} ${catkin_LIBRARIES})

add_executable(qnode_receive src/qnode_receive.cpp)
add_dependencies(qnode_receive ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(qnode_receive ${catkin_LIBRARIES} ${Boost_LIBRARIES})

add_executable(blocks_spawner env/blocks_spawner.cpp)
target_link_libraries(blocks_spawner ${catkin_LIBRARIES})

add_executable(tf_receive src/tf_receive.cpp)
target_link_libraries(tf_receive ${catkin_LIBRARIES})

