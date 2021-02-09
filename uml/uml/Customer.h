#pragma once
#include <iostream>
#include "Person.h"
#include "CreditCard.h"
#include "Wallet.h"
#include "Vehicle.h"
#include "Service.h"

class Customer : Person {

public:
	Customer(CreditCard* card) {
		m_CustomerCard = card;
	}
	Customer(Wallet* cash) {
		m_Cash = cash;
	}
	virtual void Payment(Service* service, unsigned int price)
	{
		Vehicle* m_CustomerVehicle;
		if (m_CreditCardOrWalletPay) {
			service->MakeService(this, m_CustomerVehicle, m_CustomerCard->GetMoney(price));
		}
		else {
			service->MakeService(this, m_CustomerVehicle, m_Cash->GetMoney(price));
		}
		m_CustomerService.push_back(service);
	}

private:
	CreditCard* m_CustomerCard; 
	Wallet* m_Cash;
	Vehicle* m_CustomerVehicle;
	std::list<Service*> m_CustomerService;

};