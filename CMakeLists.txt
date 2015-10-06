project (bcrypt)

cmake_minimum_required(VERSION 2.8)

remove_definitions(-std=c++11)

include(CheckIncludeFiles)
include(CheckLibraryExists)

check_library_exists(c arc4random_buf "" HAVE_ARC4RANDOM_IN_LIB_C)

if (${HAVE_ARC4RANDOM_IN_LIB_C})
    check_include_files("sys/bsd.h" HAVE_SYS_BSD_H)
    if (${HAVE_SYS_BSD_H})
        check_library_exists(bsd arc4random_buf "" HAVE_ARC4RANDOM_IN_LIB_BSD)
    endif ()
endif ()

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    add_definitions(-DBCRYPT_WINDOWS)
endif ()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(bcrypt_SRCS
    bcrypt.c
    platform.c)

add_library(bcrypt STATIC ${bcrypt_SRCS})

if (thing_tests)
    add_test(bcrypt_test bcrypt_test)

    add_executable(bcrypt_test test.c)
    target_link_libraries(bcrypt_test bcrypt)
endif()
