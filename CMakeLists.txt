cmake_minimum_required(VERSION 3.8...3.14)
project(motivatio)

set(CMAKE_CXX_STANDARD 17)
set(JSON_BuildTests OFF CACHE INTERNAL "")

if(WIN32)   # Check if we're on Windows
    set(RESOURCE_INSTALL_PATH ${CMAKE_BINARY_DIR} + "/quotes")
else()      # Assume we're on a POSIX-like system if not Windows
    set(RESOURCE_INSTALL_PATH "/usr/share/motivatio")
endif()


add_compile_definitions(JSON_BuildTest=Off)
add_definitions("-DRESOURCE_INSTALL_PATH=\"${RESOURCE_INSTALL_PATH}\"")

include(FetchContent)
FetchContent_Declare(
        nlohmann_json
            GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.10.0
)
FetchContent_MakeAvailable(nlohmann_json)

FetchContent_Declare(
        cxxopts
        GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git
        GIT_TAG v2.2.1
)

include(FetchContent)

FetchContent_Declare(
        termcolor
        GIT_REPOSITORY https://github.com/ikalnytskyi/termcolor.git
        GIT_TAG        v2.1.0  # adjust as needed
)
include(FetchContent)

FetchContent_MakeAvailable(termcolor)

FetchContent_GetProperties(cxxopts)
if(NOT cxxopts_POPULATED)
    FetchContent_Populate(cxxopts)
    add_subdirectory(${cxxopts_SOURCE_DIR} ${cxxopts_BINARY_DIR})
endif()

include(FetchContent)
FetchContent_Declare(
        cxxopts
        GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git
        GIT_TAG        v2.3.0
)

FetchContent_GetProperties(cxxopts)
if(NOT cxxopts_POPULATED)
    FetchContent_Populate(cxxopts)
endif()

add_executable(${PROJECT_NAME} main.cpp
        src/parser.cpp
        src/include/parser.h
        src/include/quotes.h
        src/quotes.cpp
        src/include/quote.h
        src/cli.cpp
        src/include/cli.h
        src/include/styles.h)


target_include_directories(${PROJECT_NAME} PRIVATE ${cxxopts_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${cxxopts_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME}  nlohmann_json::nlohmann_json)
target_link_libraries(${PROJECT_NAME} termcolor::termcolor)

install(DIRECTORY quotes DESTINATION ${RESOURCE_INSTALL_PATH})
install(TARGETS ${PROJECT_NAME} DESTINATION bin)