cmake_minimum_required(VERSION 3.25)

project(suntingYard C)

add_library(stack stack.c)

add_executable(shuntingYard shuntingYard.c)

target_link_libraries(shuntingYard PRIVATE stack)
