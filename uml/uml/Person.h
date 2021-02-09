#pragma once
#include <iostream>
#include <list>
#include <string>

class Person {

public:
	
	bool m_CreditCardOrWalletPay;
	virtual ~Person() {}
	virtual void Payment()=0;
private:
	std::string m_First_name;
	std::string m_Last_name;
	std::string m_Passport;
	std::string m_Phone_number;


};