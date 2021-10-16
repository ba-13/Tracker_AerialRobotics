cmake_minimum_required(VERSION 3.0.2)
project(csrt_tracker)

find_package(catkin REQUIRED)
add_definitions(-std=c++11)

find_package(catkin REQUIRED COMPONENTS 
  gazebo_msgs 
  geometry_msgs 
  mav_msgs 
  roscpp 
  sensor_msgs 
  cv_bridge 
  image_transport 
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS
    gazebo_msgs
    geometry_msgs
    mav_msgs
    cv_bridge
    roscpp
    image_transport
    sensor_msgs
    std_msgs
)

find_package(OpenCV REQUIRED)

include_directories( include
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

foreach(dir launch models)
   install(DIRECTORY ${dir}/
      DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/${dir})
endforeach(dir)

add_executable(ROI_handler src/ROI_handler.cpp)
target_link_libraries(ROI_handler ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
add_dependencies(ROI_handler ${catkin_EXPORTED_TARGETS})

add_executable(hovering_example src/hovering_example.cpp)
target_link_libraries(hovering_example ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
add_dependencies(hovering_example ${catkin_EXPORTED_TARGETS})

install(TARGETS ROI_handler
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
