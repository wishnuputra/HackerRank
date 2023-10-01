cmake_minimum_required(VERSION 2.8)
project( CPractice )
add_executable( CPractice hello.cpp )
target_link_libraries( CPractice ${OpenCV_LIBS} )
