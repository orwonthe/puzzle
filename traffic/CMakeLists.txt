cmake_minimum_required(VERSION 3.3)
project(traffic)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Garage.cpp Garage.h Vehicle.cpp Vehicle.h VehiclePlacement.cpp VehiclePlacement.h RushHour.cpp RushHour.h Car.cpp Car.h VerticalCar.cpp VerticalCar.h VerticalVehicle.cpp VerticalVehicle.h HorizontalVehicle.cpp HorizontalVehicle.h Car.cpp Car.h Truck.cpp Truck.h VerticalTruck.cpp VerticalTruck.h PuzzleSolver.cpp PuzzleSolver.h Solution.cpp Solution.h ExplorationJournal.cpp ExplorationJournal.h BinarySearcher.cpp BinarySearcher.h SolveAndExplain.cpp SolveAndExplain.h)
add_executable(traffic ${SOURCE_FILES})