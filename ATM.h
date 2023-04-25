#pragma once

class ATM {

private:
	double balance;
public:
	ATM();
	double getBalance() const;
	double deposit(double amount = 100);
	double withdraw(double amount = 100);
};