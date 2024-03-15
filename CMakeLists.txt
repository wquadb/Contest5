cmake_minimum_required(VERSION 3.5)

project(taskA)
project(taskB)
project(taskC)
project(taskD)
project(taskE)

add_executable(taskA taskA/main.cpp)
add_executable(taskB taskB/main.cpp)
add_executable(taskC taskC/main.cpp)
add_executable(taskD taskD/main.cpp)
add_executable(taskE taskE/main.cpp taskE/main.h)

