cmake_minimum_required(VERSION 2.8)
project(demo)

set(CMAKE_CXX_STANDARD 14)
set(OpenCV_DIR /usr/local/opencv-3.4.1/share/OpenCV)
find_package( OpenCV REQUIRED )
include_directories(. /usr/local/freetype/include)
LINK_DIRECTORIES(/usr/local/freetype/lib)
add_executable(demo
        Cv310Text.cpp
        Cv310Text.h
        main.cpp)
target_link_libraries(demo freetype ${OpenCV_LIBS})
