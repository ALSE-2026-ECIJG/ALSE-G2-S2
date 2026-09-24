cmake_minimum_required(VERSION 3.10)

project(corte2_ent2_ac)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Twitter Twitter.cpp)

add_executable(Spreadsheet Spreadsheet.cpp)

add_executable(Robot Robot.cpp)

add_executable(QueenAttack QueenAttack.cpp)