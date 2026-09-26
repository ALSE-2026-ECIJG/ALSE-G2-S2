cmake_minimum_required(VERSION 3.10)

project(Taller2_ALSE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ejercicios de LeetCode
add_library(design_twitter
    design_twitter/design_twitter.cpp
)

add_library(design_spreadsheet
    design_spreadsheet/design_spreadsheet.cpp
)

# Ejercicios de Exercism
add_library(robot_simulator
    robot_simulator/robot_simulator.cpp
)

add_library(queen_attack
    queen_attack/queen_attack.cpp
)

# Implementación de Sphere
add_executable(sphere
    sphere/main.cpp
    sphere/sphere.cpp
)
