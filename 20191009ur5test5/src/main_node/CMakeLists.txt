cmake_minimum_required(VERSION 2.8.3)
project(main_node)

##############################################################################
# 1 CMake
##############################################################################
    cmake_minimum_required(VERSION 2.8.3)
    project(main_node)

    add_definitions(-std=c++11)

###############################################################################
## 2 Catkin
###############################################################################
#    ## catkin构建时需要的组件包。
#    ## 是依赖包，是message_generation、 std_msgs和roscpp。
#    ## 如果这些功能包不存在，在构建过程中会发生错误。
#    find_package(catkin REQUIRED COMPONENTS message_generation qt_build std_msgs roscpp urdf)

#    ## 消息声明：MsgTutorial.msg
#    add_message_files(FILES MsgTutorial.msg)
#    ## 这是设置依赖性消息的选项。
#    ## 如果未安装std_msgs，则在构建过程中会发生错误。
#    generate_messages(DEPENDENCIES std_msgs)
#    ## catkin功能包选项，描述了库、catkin构建依赖项和系统依赖的功能包。
#    catkin_package(
#    LIBRARIES ros_tutorials_topic
#    CATKIN_DEPENDS std_msgs roscpp urdf
#    )
#    ## 设置包含目录。
#    include_directories(${catkin_INCLUDE_DIRS})

###############################################################################
## 3 Qt Environment
###############################################################################
#    find_package(Qt4 COMPONENTS QtCore QtGui QtOpenGL REQUIRED)
#    set(QT_USE_QTOPENGL TRUE)

#    # OpenGL & GLEW library
#    # OpenGL
#    FIND_PACKAGE(OpenGL REQUIRED)
#    if(NOT OPENGL_FOUND)
#        message(ERROR " OPENGL not found!")
#    endif(NOT OPENGL_FOUND)
#    include_directories(${QT_QTOPENGL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR})

#    INCLUDE(${QT_USE_FILE})
#    ADD_DEFINITIONS(${QT_DEFINITIONS})
#    include_directories(${CMAKE_CURRENT_BINARY_DIR})

#    #Find includes in corresponding build directories
#    #set(CMAKE_INCLUDE_CURRENT_DIR ON)

#    # Instruct CMake to run moc automatically when needed.
#    #set(CMAKE_AUTOMOC ON)

###############################################################################
## 4.1 Sections for QT
###############################################################################
#    set(QT_HEADER_FILES
#        gui/test_gui.h
#        #ros_connect/rosconnect.h
#        ros_connect/qnode.h
#        ros_connect/simnode.h
#        kinematics/solvekinematics.h
#        gui/glgragh.h
#        )
#    set(QT_SOURCE_FILES
#        gui/test_gui.cpp
#        galil_servo/galilservo.cpp
#        #ros_connect/rosconnect.cpp
#        ros_connect/qnode.cpp
#        ros_connect/simnode.cpp
#        kinematics/solvekinematics.cpp
#        gui/glgragh.cpp
#        ${MOC_FILES}
#        )
#    set(QT_FORM_FILES
#        gui/test_gui.ui
#        )

##    file(GLOB QT_FORMS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ui/*.ui)
##    file(GLOB QT_RESOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} resources/*.qrc)
##    file(GLOB_RECURSE QT_MOC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS include/my_qt_gui_subscriber/*.hpp)

#    QT4_ADD_RESOURCES(QT_RESOURCES_CPP ${QT_RESOURCES})
#    QT4_WRAP_UI(QT_FORMS_HPP ${QT_FORM_FILES})
#    QT4_WRAP_CPP(QT_MOC_HPP ${QT_HEADER_FILES})

###############################################################################
## 4.2 Sections for GALIL
###############################################################################
#    set(GALIL_HEADER_FILES
#        galil/x_examples.h
#        )
#    set(GALIL_SOURCE_FILES
#        galil/x_arrays.cpp
#        galil/x_gcommand.cpp
#        galil/x_ginterrupt.cpp
#        galil/x_gmessage.cpp
#        galil/x_gmotioncomplete.cpp
#        galil/x_gread_gwrite.cpp
#        galil/x_grecord.cpp
#        galil/x_nonblocking.cpp
#        galil/x_programs.cpp
#        )
#    set(GALIL_LIB_FILES
#        /usr/lib/libgclib.so
#        /usr/lib/libgclibo.so
#        )

###############################################################################
## 4.3 Sections for GLOBALS
###############################################################################
#    set(GLOBALS_SOURCE_FILES
#        vars/cglobal.cpp
#        )

###############################################################################
## 4.4 Sections for ROS CONNECTIONS
###############################################################################
#    set(ROSCONNECT_HEADER_FILES
#        ros_connect/rosconnect.h
#        )
#    set(ROSCONNECT_SOURCE_FILES
#        ros_connect/rosconnect.cpp
#        ${MOC_FILES}
#        )
#    QT4_WRAP_CPP(ROSCONNECT_MOC_HPP ${ROSCONNECT_HEADER_FILES})

###############################################################################
## 4.5 Sections for Python CONNECTIONS
###############################################################################
#    include_directories(/usr/include/python3.5m)#添加头文件目录，相当于g++ -I参数
#    link_directories(/usr/lib/python3.5)#动态链接库或静态链接库的搜索路径，相当于gcc的-L参数



##############################################################################
# 5 Sources
##############################################################################
#    file(GLOB_RECURSE QT_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS src/*.cpp)

##############################################################################
# 6 Binaries
##############################################################################
#    ## topic_publisher节点的构建选项。
#    ## 配置可执行文件、目标链接库和其他依赖项。
#    add_executable(topic_publisher src/topic_publisher.cpp)
#    add_dependencies(topic_publisher ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
#    target_link_libraries(topic_publisher ${catkin_LIBRARIES})

#    ## topic_subscriber节点的构建选项。
#    add_executable(topic_subscriber src/topic_subscriber.cpp)
#    add_dependencies(topic_subscriber ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
#    target_link_libraries(topic_subscriber ${catkin_LIBRARIES})

#    ## main_gui节点的构建选项。
#    add_executable(main src/main.cpp ${QT_SOURCE_FILES} ${QT_MOC_HPP} ${QT_FORMS_HPP} ${GALIL_HEADER_FILES} ${GALIL_SOURCE_FILES} ${GLOBALS_SOURCE_FILES})
#    add_dependencies(main ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
#    target_link_libraries(main ${QT_LIBRARIES} ${OPENGL_LIBRARIES} ${catkin_LIBRARIES} ${GALIL_LIB_FILES} python3.5m)

#    ## joy_receive节点的构建选项。
#    add_executable(joy_receive src/joy_receive.cpp ${GLOBALS_SOURCE_FILES} ${ROSCONNECT_SOURCE_FILES} ${ROSCONNECT_MOC_HPP})
#    add_dependencies(joy_receive ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
#    target_link_libraries(joy_receive ${catkin_LIBRARIES} ${QT_LIBRARIES})
