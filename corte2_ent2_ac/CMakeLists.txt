cmake_minimum_required(VERSION 3.10)

project(corte2_ent2_ac)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Twitter OBJECT Twitter.cpp)
add_library(Spreadsheet OBJECT Spreadsheet.cpp)
add_library(Robot OBJECT Robot.cpp)
add_library(QueenAttack OBJECT QueenAttack.cpp)