project (bcrypt)

cmake_minimum_required(VERSION 2.8)

remove_definitions(-std=c++11)

set(bcrypt_SRCS bcrypt.c)

add_library(bcrypt STATIC ${bcrypt_SRCS})

if (thing_tests)
    add_test(bcrypt_test bcrypt_test)

    add_executable(bcrypt_test test.c)
    target_link_libraries(bcrypt_test bcrypt)
endif()
