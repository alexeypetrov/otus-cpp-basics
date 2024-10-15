cmake_minimum_required(VERSION 3.5)

project(03.homework)

add_executable(
    guess_the_number
    guess_the_number.cpp
    game.cpp
    random_number.cpp
    high_scores.cpp
)

set_target_properties(guess_the_number PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
