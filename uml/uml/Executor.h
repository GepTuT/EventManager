#pragma once
#include <iostream>
#include "Person.h"
#include "CreditCard.h"
#include "Wallet.h"
#include "Vehicle.h"
#include "Service.h"

class Executor : Person {
public:
	
	Executor() {

	}
	void TireFitting(Vehicle* CustomerVehicle, Service* service) {
		m_CustomerVehicle = CustomerVehicle;
			Wheel* wheels = CustomerVehicle->GetWheels();
			int VehicleWheelsCount = CustomerVehicle->GetWheelsCount();
			for (int i = 0; i < VehicleWheelsCount; i++) {
				if (wheels[i].GetTireDiskDurability() < 100.0) {
					wheels[i].ChangeTireDiskDurability();
					
				}

				if (wheels[i].GetTireTubeDurability() < 100.0) {
					wheels[i].ChangeTireDiskDurability();
				}

				if (wheels[i].GetTireWheelDurability() < 100.0) {
					wheels[i].ChangeTireDiskDurability();
				}
				m_ExecutorService.push_back(service);
			}
			
		

	}
private:

	std::list<Service*> m_ExecutorService;
	Vehicle* m_CustomerVehicle;
	
};