cmake_minimum_required(VERSION 2.8)

set(OpenCV_DIR ~/Documents/OpenCV//)

set(CMAKE_CXX_FLAGS "-std=c++11")

project( DisplayImage )
find_package( OpenCV REQUIRED )

add_executable( DisplayImage main.cpp tools.cpp )

target_link_libraries( DisplayImage ${OpenCV_LIBS} )
