cmake_minimum_required(VERSION 3.16)
project(AiZO_Projekt1 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Werror)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/libs/params/include
)

link_directories(${PROJECT_SOURCE_DIR}/libs/params/lib)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(aizo ${SOURCES})

target_link_libraries(aizo parameters)
