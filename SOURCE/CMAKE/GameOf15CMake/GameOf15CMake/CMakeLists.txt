# CMakeList.txt : CMake project for GameOf15CMake, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (GameOf15CMake "GameOf15CMake.cpp" "GameOf15CMake.h" "Matrix/OrtogonalNodes.h" "Matrix/MatrixComponents.h" "Matrix/Matrix.h" "Podium/Podium.cpp" "Podium/Podium.h" "Podium/PodiumDataSaver.h" "Podium/PodiumDataSaver.cpp" "Game/Game.h" "Game/Game.cpp" "Game/GameController.h" "Game/GameController.cpp" "Utils/Sorter.h")

# TODO: Add tests and install targets if needed.
