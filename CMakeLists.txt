# SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
#
# SPDX-License-Identifier: MIT-0

cmake_minimum_required(VERSION 3.16.3)
project(HackerRank LANGUAGES CXX)

if(POLICY CMP0135)
  cmake_policy(SET CMP0135 NEW)
endif()

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "No build type selected, default to Release")
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    Debug Release MinSizeRel RelWithDebInfo)
endif()


set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Algorithms
add_executable(diagonal-difference algorithms/warm-up/diagonal-difference.cpp)
add_executable(plus-minus algorithms/warm-up/plus-minus.cpp)
add_executable(mini-max-sum algorithms/warm-up/mini-max-sum.cpp)
add_executable(time-conversion algorithms/warm-up/time-conversion.cpp)

add_executable(caesar-cipher algorithms/strings/caesar-cipher.cpp)
add_executable(palindrome-index algorithms/strings/palindrome-index.cpp)

add_executable(counting-sort-1 algorithms/sorting/counting-sort-1.cpp)
add_executable(find-median algorithms/sorting/find-median.cpp)

add_executable(pairs algorithms/search/pairs.cpp)

add_executable(grid-challenge algorithms/greedy/grid-challenge.cpp)

add_executable(flipping-matrix algorithms/constructive/flipping-matrix.cpp)
add_executable(new-year-chaos algorithms/constructive/new-year-chaos.cpp)

add_executable(lonely-integer algorithms/bit-manipulation/lonely-integer.cpp)

add_executable(recursive-digit-sum algorithms/recursion/recursive-digit-sum.cpp)

add_executable(tower-breakers algorithms/game-theory/tower-breakers.cpp)


# Data structures
add_executable(merge-two-linked-lists data-structures/linked-lists/merge-two-linked-lists.cpp)

add_executable(balanced-brackets data-structures/stacks/balanced-brackets.cpp)

add_executable(queue-using-two-stacks data-structures/queues/queue-using-two-stacks.cpp)
add_executable(truck-tour data-structures/queues/truck-tour.cpp)
