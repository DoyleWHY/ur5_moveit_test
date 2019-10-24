# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "main_node: 1 messages, 0 services")

set(MSG_I_FLAGS "-Imain_node:/home/doylewhy/efficient/moveit/20191009ur5test5/src/main_node/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(main_node_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/doylewhy/efficient/moveit/20191009ur5test5/src/main_node/msg/MsgTutorial.msg" NAME_WE)
add_custom_target(_main_node_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "main_node" "/home/doylewhy/efficient/moveit/20191009ur5test5/src/main_node/msg/MsgTutorial.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(main_node
  "/home/doylewhy/efficient/moveit/20191009ur5test5/src/main_node/msg/MsgTutorial.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/main_node
)

### Generating Services

### Generating Module File
_generate_module_cpp(main_node
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/main_node
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(main_node_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(main_node_generate_messages main_node_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/doylewhy/efficient/moveit/20191009ur5test5/src/main_node/msg/MsgTutorial.msg" NAME_WE)
add_dependencies(main_node_generate_messages_cpp _main_node_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(main_node_gencpp)
add_dependencies(main_node_gencpp main_node_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS main_node_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(main_node
  "/home/doylewhy/efficient/moveit/20191009ur5test5/src/main_node/msg/MsgTutorial.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/main_node
)

### Generating Services

### Generating Module File
_generate_module_eus(main_node
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/main_node
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(main_node_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(main_node_generate_messages main_node_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/doylewhy/efficient/moveit/20191009ur5test5/src/main_node/msg/MsgTutorial.msg" NAME_WE)
add_dependencies(main_node_generate_messages_eus _main_node_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(main_node_geneus)
add_dependencies(main_node_geneus main_node_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS main_node_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(main_node
  "/home/doylewhy/efficient/moveit/20191009ur5test5/src/main_node/msg/MsgTutorial.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/main_node
)

### Generating Services

### Generating Module File
_generate_module_lisp(main_node
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/main_node
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(main_node_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(main_node_generate_messages main_node_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/doylewhy/efficient/moveit/20191009ur5test5/src/main_node/msg/MsgTutorial.msg" NAME_WE)
add_dependencies(main_node_generate_messages_lisp _main_node_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(main_node_genlisp)
add_dependencies(main_node_genlisp main_node_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS main_node_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(main_node
  "/home/doylewhy/efficient/moveit/20191009ur5test5/src/main_node/msg/MsgTutorial.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/main_node
)

### Generating Services

### Generating Module File
_generate_module_nodejs(main_node
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/main_node
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(main_node_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(main_node_generate_messages main_node_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/doylewhy/efficient/moveit/20191009ur5test5/src/main_node/msg/MsgTutorial.msg" NAME_WE)
add_dependencies(main_node_generate_messages_nodejs _main_node_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(main_node_gennodejs)
add_dependencies(main_node_gennodejs main_node_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS main_node_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(main_node
  "/home/doylewhy/efficient/moveit/20191009ur5test5/src/main_node/msg/MsgTutorial.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/main_node
)

### Generating Services

### Generating Module File
_generate_module_py(main_node
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/main_node
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(main_node_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(main_node_generate_messages main_node_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/doylewhy/efficient/moveit/20191009ur5test5/src/main_node/msg/MsgTutorial.msg" NAME_WE)
add_dependencies(main_node_generate_messages_py _main_node_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(main_node_genpy)
add_dependencies(main_node_genpy main_node_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS main_node_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/main_node)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/main_node
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(main_node_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/main_node)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/main_node
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(main_node_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/main_node)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/main_node
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(main_node_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/main_node)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/main_node
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(main_node_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/main_node)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/main_node\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/main_node
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(main_node_generate_messages_py std_msgs_generate_messages_py)
endif()