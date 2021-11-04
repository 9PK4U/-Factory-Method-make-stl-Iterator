cmake_minimum_required(VERSION 3.1)

project(Lab1)

set(CMAKE_CXX_STANDARD 17)
add_executable(Lab1 main.cpp ParserPlantElement.cpp ParserPlantElement.h PlantElement.cpp PlantElement.h Parser.cpp Parser.h Plants.h ListPlants.cpp ListPlants.h RingList.h Iterator.h)
