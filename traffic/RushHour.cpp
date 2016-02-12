//
// Copyright 2016 by WillyMillsLLC 2/2/16.
//

#include "RushHour.h"
#include "VerticalTruck.h"
#include "VerticalCar.h"
#include "Car.h"
#include "Truck.h"

Truck RushHour::BlueTruck = Truck('b', "blue");
VerticalTruck RushHour::BlueVerticalTruck = VerticalTruck('B', "blue");
Car RushHour::CyanCar = Car('c', "cyan");
VerticalCar RushHour::CyanVerticalCar = VerticalCar('C', "cyan");
Car RushHour::PastelGreenCar = Car('s', "pastel green");
VerticalCar RushHour::PastelGreenVerticalCar = VerticalCar('S', "pastel green");
Car RushHour::GreenCar = Car('g', "green");
VerticalCar RushHour::GreenVerticalCar = VerticalCar('G', "green");
Car RushHour::PinkCar = Car('i', "pink");
VerticalCar RushHour::PinkVerticalCar = VerticalCar('I', "pink");
Car RushHour::BlackCar = Car('k', "black");
VerticalCar RushHour::BlackVerticalCar = VerticalCar('K', "black");
Truck RushHour::YellowTruck = Truck('l', "yellow");
VerticalTruck RushHour::YellowVerticalTruck = VerticalTruck('L', "yellow");
Truck RushHour::GreenTruck = Truck('n', "green");
VerticalTruck RushHour::GreenVerticalTruck = VerticalTruck('N', "green");
Car RushHour::OrangeCar = Car('o', "orange");
VerticalCar RushHour::OrangeVerticalCar = VerticalCar('O', "orange");
Car RushHour::PurpleCar = Car('p', "purple");
VerticalCar RushHour::PurpleVerticalCar = VerticalCar('P', "purple");
Car RushHour::RedCar = Car('r', "red");
VerticalCar RushHour::RedVerticalCar = VerticalCar('R', "red");
Car RushHour::TanCar = Car('t', "tan");
VerticalCar RushHour::TanVerticalCar = VerticalCar('T', "tan");
Truck RushHour::VioletTruck = Truck('v', "violet");
VerticalTruck RushHour::VioletVerticalTruck = VerticalTruck('V', "violet");
Car RushHour::OliveCar = Car('e', "olive");
VerticalCar RushHour::OliveVerticalCar = VerticalCar('E', "olive");
Car RushHour::BrownCar = Car('w', "brown");
VerticalCar RushHour::BrownVerticalCar = VerticalCar('W', "brown");
Car RushHour::YellowCar = Car('y', "yellow");
VerticalCar RushHour::YellowVerticalCar = VerticalCar('Y', "yellow");

Garage RushHour::create_puzzle(int number) {
    Garage puzzle = Garage();
    switch (number) {
        case -99:
            puzzle.addVehicle(RedCar, 1, 2);
            puzzle.addVehicle(YellowVerticalTruck, 5, 3);
            puzzle.addVehicle(OrangeVerticalCar, 5, 1);
            break;
        case -98: // Note: has no solution.
            puzzle.addVehicle(RedCar, 0, 2);
            puzzle.addVehicle(YellowVerticalTruck, 5, 0);
            puzzle.addVehicle(BlueVerticalTruck, 5, 3);
            break;
        case -5:
            puzzle.addVehicle(RedCar, 1, 2);
            puzzle.addVehicle(YellowVerticalTruck, 5, 0);
            puzzle.addVehicle(BlueVerticalTruck, 3, 1);
            puzzle.addVehicle(CyanCar, 4, 4);
            break;
        case -4:
            puzzle.addVehicle(RedCar, 1, 2);
            puzzle.addVehicle(YellowVerticalTruck, 5, 0);
            puzzle.addVehicle(BlueVerticalTruck, 3, 1);
            break;
        case -3:
            puzzle.addVehicle(RedCar, 1, 2);
            puzzle.addVehicle(YellowVerticalTruck, 5, 0);
            puzzle.addVehicle(BlueVerticalTruck, 3, 1);
            break;
        case -2:
            puzzle.addVehicle(RedCar, 1, 2);
            puzzle.addVehicle(YellowVerticalTruck, 5, 0);
            break;
        case -1:
            puzzle.addVehicle(RedCar, 0, 2);
            break;
        case 0:
            puzzle.addVehicle(RedCar, 4, 2);
            break;
        case 1:
            puzzle.addVehicle(RedCar, 1, 2);
            puzzle.addVehicle(VioletVerticalTruck, 0, 1);
            puzzle.addVehicle(PastelGreenCar, 0, 0);
            puzzle.addVehicle(OrangeVerticalCar, 0, 4);
            puzzle.addVehicle(BlueVerticalTruck, 3, 1);
            puzzle.addVehicle(YellowVerticalTruck, 5, 0);
            puzzle.addVehicle(CyanCar, 4, 4);
            puzzle.addVehicle(GreenTruck, 2, 5);
            break;
        case 2:
            puzzle.addVehicle(RedCar, 0, 2);
            puzzle.addVehicle(PastelGreenVerticalCar, 0, 0);
            puzzle.addVehicle(BlueTruck, 0, 3);
            puzzle.addVehicle(GreenCar, 0, 5);
            puzzle.addVehicle(PinkVerticalCar, 2, 4);
            puzzle.addVehicle(YellowTruck, 3, 0);
            puzzle.addVehicle(OrangeVerticalCar, 3, 1);
            puzzle.addVehicle(BlackCar, 3, 5);
            puzzle.addVehicle(CyanVerticalCar, 4, 2);
            puzzle.addVehicle(PurpleCar, 4, 4);
            puzzle.addVehicle(VioletVerticalTruck, 5, 1);
            break;
        case 37:
            puzzle.addVehicle(GreenCar, 0, 0);
            puzzle.addVehicle(PinkCar, 0, 1);
            puzzle.addVehicle(BlueVerticalTruck, 0, 2);
            puzzle.addVehicle(BlackCar, 0, 5);
            puzzle.addVehicle(RedCar, 1, 2);
            puzzle.addVehicle(GreenTruck, 1, 3);
            puzzle.addVehicle(OrangeVerticalCar, 2, 0);
            puzzle.addVehicle(PurpleVerticalCar, 3, 4);
            puzzle.addVehicle(CyanCar, 4, 0);
            puzzle.addVehicle(YellowVerticalTruck, 4, 1);
            puzzle.addVehicle(GreenCar, 4, 4);
            puzzle.addVehicle(TanCar, 4, 5);
            puzzle.addVehicle(VioletVerticalTruck, 5, 1);
            break;
        case 38:
            puzzle.addVehicle(PastelGreenVerticalCar, 0, 0);
            puzzle.addVehicle(RedCar, 0, 2);
            puzzle.addVehicle(OrangeCar, 1, 1);
            puzzle.addVehicle(PinkVerticalCar, 2, 2);
            puzzle.addVehicle(GreenVerticalCar, 2, 4);
            puzzle.addVehicle(YellowTruck, 3, 0);
            puzzle.addVehicle(CyanVerticalCar, 3, 1);
            puzzle.addVehicle(PurpleCar, 3, 3);
            puzzle.addVehicle(BlackCar, 3, 4);
            puzzle.addVehicle(BlueTruck, 3, 5);
            puzzle.addVehicle(GreenVerticalTruck, 5, 2);
            break;
        case 39:
            puzzle.addVehicle(RedCar, 0, 2);
            puzzle.addVehicle(PinkCar, 0, 3);
            puzzle.addVehicle(GreenVerticalCar, 0, 4);
            puzzle.addVehicle(BlackVerticalCar, 1, 4);
            puzzle.addVehicle(PastelGreenVerticalCar, 2, 0);
            puzzle.addVehicle(CyanVerticalCar, 2, 2);
            puzzle.addVehicle(TanCar, 2, 4);
            puzzle.addVehicle(YellowCar, 2, 5);
            puzzle.addVehicle(YellowTruck, 3, 0);
            puzzle.addVehicle(OrangeVerticalCar, 3, 1);
            puzzle.addVehicle(PurpleCar, 3, 3);
            puzzle.addVehicle(GreenVerticalTruck, 5, 2);
            break;
        case 40:
            puzzle.addVehicle(YellowVerticalTruck, 0, 0);
            puzzle.addVehicle(BlueTruck, 0, 3);
            puzzle.addVehicle(TanCar, 0, 5);
            puzzle.addVehicle(GreenCar, 1, 0);
            puzzle.addVehicle(CyanVerticalCar, 1, 1);
            puzzle.addVehicle(PinkVerticalCar, 2, 1);
            puzzle.addVehicle(GreenVerticalCar, 2, 4);
            puzzle.addVehicle(RedCar, 3, 2);
            puzzle.addVehicle(PurpleVerticalCar, 3, 3);
            puzzle.addVehicle(YellowCar, 3, 5);
            puzzle.addVehicle(OrangeVerticalCar, 4, 0);
            puzzle.addVehicle(BlackCar, 4, 4);
            puzzle.addVehicle(VioletVerticalTruck, 5, 1);
            break;
    }

    return puzzle;
}
