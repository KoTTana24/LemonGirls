cmake_minimum_required(VERSION 3.20)

project(LemonGirls)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(CURL REQUIRED)


# =========================
# Main application
# =========================

add_executable(
        LemonGirls

        src/main.cpp

        src/core/Character.cpp
        src/core/OllamaClient.cpp
        src/core/Chat.cpp
        src/core/Memory.cpp
        src/core/ChatManager.cpp
        src/core/CharacterManager.cpp
)


target_include_directories(
        LemonGirls
        PRIVATE
        src
)


target_link_libraries(
        LemonGirls
        CURL::libcurl
)


# =========================
# Tests
# =========================

include(FetchContent)


FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)


# Для Windows (не обязательно, но полезно)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)


FetchContent_MakeAvailable(googletest)


enable_testing()


add_executable(
        LemonGirlsTests

        tests/CharacterTest.cpp

        src/core/Character.cpp
        src/core/Chat.cpp
        src/core/Memory.cpp
        src/core/OllamaClient.cpp
        src/core/ChatManager.cpp
        src/core/CharacterManager.cpp

)


target_include_directories(
        LemonGirlsTests
        PRIVATE
        src
)


target_link_libraries(
        LemonGirlsTests

        GTest::gtest_main

        CURL::libcurl
)


include(GoogleTest)


gtest_discover_tests(LemonGirlsTests)
