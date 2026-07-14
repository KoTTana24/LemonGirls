cmake_minimum_required(VERSION 3.20)

project(LemonGirls)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(CURL REQUIRED)


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