#pragma once
#include <iostream>
#include "Wheel.h"
#include "TireFitting.h"

class Vehicle : public TireFitting, public Wheel{

public:
	Vehicle(int WheelsCount) {
		VehicleWheelsCount = WheelsCount;
		wheels = new Wheel[VehicleWheelsCount];
		std::cout << "All vehicle wheels Created\n";
		
	}
	~Vehicle() {
		delete[] wheels;
	}
	Wheel* GetWheels() {
		return wheels;
	}
	std::string GetVehicleName(){
		return VehicleName;
	}
	std::string GetVehicleNumber() {
		return VehicleNumber;
	}
	int GetWheelsCount() {
		return VehicleWheelsCount;
	}
	
private:
	std::string VehicleName;
	std::string VehicleNumber;
	Wheel* wheels;
	int VehicleWheelsCount;

};