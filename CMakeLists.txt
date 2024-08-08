cmake_minimum_required(VERSION 3.8...3.14)
project(motivatio)

set(CMAKE_CXX_STANDARD 17)

# nlohmann_json
include(FetchContent)
FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.9.1
)
FetchContent_MakeAvailable(nlohmann_json)


add_executable(motivatio main.cpp)

target_link_libraries(motivatio nlohmann_json::nlohmann_json)
