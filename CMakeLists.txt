cmake_minimum_required(VERSION 3.16)
project(BinaryTree C)

set(CMAKE_C_STANDARD 11)

add_executable(BinaryTree main.c tree/node.h user_type.h tree/tree.h tree/tree.c user_errors.h strategy/strategy.c strategy/strategy.h callback/callback.c callback/callback.h)