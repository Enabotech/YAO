cmake_minimum_required(VERSION 2.8.3)
project(enabot_control)

find_package(catkin REQUIRED COMPONENTS
  actionlib
  actionlib_msgs
  message_generation
  roscpp
  rospy
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES enabot_control
#  CATKIN_DEPENDS actionlib actionlib_msgs message_generation roscpp rospy std_msgs
  CATKIN_DEPENDS actionlib_msgs
)

include_directories(
  include ${catkin_INCLUDE_DIRS}
  include/enabot_control
  ${catkin_INCLUDE_DIRS} include/galil
)

link_directories(
  ${catkin_LIB_DIRS} lib/galil
)

add_executable(enabot_control
  src/galil_dmc_4060.cpp src/enabot_control.cpp src/enabot_comm.cpp src/galil_dmc_4060.cpp)
target_link_libraries(enabot_control ${catkin_LIBRARIES} libgclib.so libgclibo.so)

# add_executable(galil_dmc_4060 src/galil_dmc_4060.cpp)
# target_link_libraries(galil_dmc_4060 ${catkin_LIBRARIES} libgclib.so libgclibo.so)

