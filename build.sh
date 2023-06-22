#!/bin/sh

set -xe

# -Wall -Wextra -fsanitize=address
# g++ -Wall -Wextra -std=c++20 -o app Word_Comparison.cpp
g++ -Wall -Wextra -std=c++20 -o app src/main.cpp src/font.cpp src/game.cpp 
