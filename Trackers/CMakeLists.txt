cmake_minimum_required(VERSION 2.8)
PROJECT(Trackers)
find_package(OpenCV REQUIRED)
include_directories( ${OPENCV_INCLUDE_DIRS} )


add_executable( kcfTracker kcfTracker.cpp )
target_link_libraries( kcfTracker ${OpenCV_LIBS} )