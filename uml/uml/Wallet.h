#pragma once
#include <iostream>


class Wallet {
public:
	bool GetMoney(unsigned int sum) {

		if (m_wallet_balance >= sum) {
			m_wallet_balance -= sum;
			return true;
		}
		else return false;
	}
	void PutMoney(unsigned int sum) {
		m_wallet_balance += sum;
	}
private:
	unsigned int m_wallet_balance;
};