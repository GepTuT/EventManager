#pragma once
#include <iostream>

class CreditCard { 
public: 
	bool GetMoney(unsigned int sum) {
		
		if (m_creditcard_balance >= sum) {
			m_creditcard_balance -= sum;
			return true;
		}
		else return false;
	}
	void PutMoney(unsigned int sum) {
		m_creditcard_balance += sum;
	}
private: 
	unsigned char* m_bankName; 
	unsigned int m_creditcard_balance; 



};