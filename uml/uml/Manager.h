#pragma once
#include "Person.h"
#include "Wallet.h"
#include "CreditCard.h"
#include "Service.h"

class Manager : Person {
public: 
	Manager(CreditCard* card) {
		m_PayTerminal = card;
	}
	Manager(Wallet* cash) {
		m_CashRegister = cash;
	}
	void RegCustomer(Customer* CustomerID) {
		CustomerId.push_back(CustomerID);
	}
virtual void Payment(Service* service, unsigned int price) 
	{ 

	if (m_CreditCardOrWalletPay) {
		m_PayTerminal->PutMoney(price);
	}
	else {
		m_CashRegister->PutMoney(price);
	}
	m_ManagerService.push_back(service); 
	CustomerId.pop_back();
} 


private: 
	CreditCard* m_PayTerminal; 
	Wallet* m_CashRegister;
	std::list<Service*> m_ManagerService;
	std::list<Customer*> CustomerId;
	




};
