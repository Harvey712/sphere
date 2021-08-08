cmake_minimum_required(VERSION 3.10)

project(Sphere)

add_executable(Sphere main.cpp sphere.cpp vector3.cpp)

target_link_libraries(Sphere PUBLIC ncurses)

target_compile_options(Sphere PRIVATE -Wall -Wextra)
