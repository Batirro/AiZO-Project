cmake_minimum_required(VERSION 3.16)
project(AiZO_Projekt1 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Werror)

# Ścieżki do nagłówków
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/libs/params/include
)

# Ścieżka do biblioteki .so prowadzącego
link_directories(${PROJECT_SOURCE_DIR}/libs/params/lib)

# Zbieranie wszystkich plików .cpp z src/
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(aizo ${SOURCES})

# Linkowanie z biblioteką prowadzącego
target_link_libraries(aizo params)
