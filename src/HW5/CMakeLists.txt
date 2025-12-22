cmake_minimum_required(VERSION 3.25)

project(balansPlus C)

add_library(stack stack.c)

add_executable(balansPlus balansPlus.c)

target_link_libraries(balansPlus PRIVATE stack)
