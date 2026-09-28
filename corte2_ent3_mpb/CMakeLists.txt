cmake_minimum_required(VERSION 3.10)
project(Corte2Entrega3 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(design_authentication_manager)
add_subdirectory(design_exam_scores_tracker)
add_subdirectory(crypto_square)
add_subdirectory(bank_account)
