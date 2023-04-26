#pragma once

class ATM {

private:
	double balance;
public:
	ATM();
	double getBalance() const;
	double deposit(double amount = 100);
	bool withdraw(double amount = 100);
};