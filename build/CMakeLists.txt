cmake_minimum_required(VERSION 3.1)
project( openCV )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( ../exe/tracking_CSRT ../src/tracking_CSRT.cpp)
target_link_libraries( ../exe/tracking_CSRT ${OpenCV_LIBS} )

add_executable( ../exe/tracking_KCF ../src/tracking_KCF.cpp)
target_link_libraries( ../exe/tracking_KCF ${OpenCV_LIBS} )


