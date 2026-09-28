find_package(Threads REQUIRED)
add_executable(bank_account main.cpp bank_account.cpp bank_account.h)
target_link_libraries(bank_account PRIVATE Threads::Threads)
