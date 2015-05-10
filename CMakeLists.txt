cmake_minimum_required(VERSION 2.8)

set(OpenCV_DIR ~/Documents/OpenCV//)

set(CMAKE_CXX_FLAGS "-std=c++11")

project( DroneProject )
find_package( OpenCV REQUIRED )

add_executable( DroneProject 
	main.cpp 
	tools.cpp 
	RecognitionLearning.cpp 
	PeopleRecognition.cpp
	Initialization.cpp
	)

target_link_libraries( DroneProject ${OpenCV_LIBS} )
