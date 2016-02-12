//
// Copyright 2016 by WillyMillsLLC 2/2/16.
//

#ifndef TRAFFIC_RUSHHOUR_H
#define TRAFFIC_RUSHHOUR_H


#include "Vehicle.h"
#include "Garage.h"
#include "Car.h"
#include "VerticalCar.h"
#include "VerticalTruck.h"
#include "Truck.h"

class RushHour {
protected:
    // cars
    static Car RedCar;
    static VerticalCar RedVerticalCar;
    static Car PinkCar;
    static VerticalCar PinkVerticalCar;
    static Car PastelGreenCar;
    static VerticalCar PastelGreenVerticalCar;
    static Car OrangeCar;
    static VerticalCar OrangeVerticalCar;
    static Car CyanCar;
    static VerticalCar CyanVerticalCar;
    static Car YellowCar;
    static VerticalCar YellowVerticalCar;
    static Car GreenCar;
    static VerticalCar GreenVerticalCar;
    static Car OliveCar;
    static VerticalCar OliveVerticalCar;
    static Car BrownCar;
    static VerticalCar BrownVerticalCar;
    static Car TanCar;
    static VerticalCar TanVerticalCar;
    static Car BlackCar;
    static VerticalCar BlackVerticalCar;
    static Car PurpleCar;
    static VerticalCar PurpleVerticalCar;

    // trucks
    static Truck GreenTruck;
    static VerticalTruck GreenVerticalTruck;
    static Truck VioletTruck;
    static VerticalTruck VioletVerticalTruck;
    static Truck BlueTruck;
    static VerticalTruck BlueVerticalTruck;
    static Truck YellowTruck;
    static VerticalTruck YellowVerticalTruck;
public:
    static Garage create_puzzle(int number);
};


#endif //TRAFFIC_RUSHHOUR_H
