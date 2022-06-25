
cmake_minimum_required(VERSION 3.13)

# project name
project(fdg) 

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(gameprocedures)

target_link_libraries(fdg gameprocedures)


