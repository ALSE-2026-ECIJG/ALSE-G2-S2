cmake_minimum_required(VERSION 3.10)

project(EjerciciosCorte)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(AuthenticationManager AuthenticationManager.cpp)
add_executable(ExamTracker ExamTracker.cpp)
add_executable(CryptoSquare CryptoSquare.cpp)
add_executable(BankAccount BankAccount.cpp)