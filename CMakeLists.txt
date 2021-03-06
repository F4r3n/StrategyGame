cmake_minimum_required (VERSION 3.0.2)
project (StrategyGame)
include_directories(include)
file(GLOB SOURCES "src/*.cpp")
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++14" COMPILER_SUPPORTS_CXX14)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g -Wall")
elseif(COMPILER_SUPPORTS_CXX0X)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -g -Wall")
else()
	message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()
set(SFML_INCLUDE_DIR "/usr/include/SFML/")
set(SFML_LIBRARY_DIR "/usr/lib/x86_64-linux-gnu/")

include_directories(${SFML_INCLUDE_DIR})
link_directories(${SFML_LIBRARY_DIR})
add_executable(StrategyGame ${SOURCES})

target_link_libraries(StrategyGame sfml-system sfml-window sfml-graphics)
