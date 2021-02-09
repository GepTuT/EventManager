#pragma once
#include <iostream>
#include "Vehicle.h"
#include "Customer.h"
#include "Executor.h"
#include "Manager.h"


class Service {
public:
	void MakeService(Customer* CustomerIn, Vehicle* CustomerVehicle, unsigned int price){
		m_CustomerIn = CustomerIn;
		m_carservice = CustomerVehicle;
		m_ManagerIn->RegCustomer(m_CustomerIn);
		CustomerVehicle->RegisterService(this);
		m_ExecutorIn = CustomerVehicle->GetExecutor();
		m_ExecutorIn->TireFitting(CustomerVehicle,this);
		m_ManagerIn->Payment(this, price);

	}

private:
	Manager* m_ManagerIn; 
	Executor* m_ExecutorIn;
	Customer* m_CustomerIn; 
	Vehicle* m_carservice;
};