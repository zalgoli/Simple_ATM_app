// Tobedeleted.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "ATM.h"

ATM::ATM()
{
	balance = 0;
}


double ATM::getBalance() const
{
	return balance;
}

double ATM::deposit(double amount /* 100 */)
{
	balance += amount;
	return balance;
}

double ATM::withdraw(double amount /* 100 */)
{
	balance = (balance - amount > 0) ? balance - amount : 0;
	return balance;
}

int main()
{
    ATM myATM;
    char user_input;

    while (true) {
        std::cout << "Input 'A' to view balance, 'B' to deposit or 'C' to withdraw. Enter Q to Quit.";
        std::cin >> user_input;

        switch (user_input) {
        case 'A':
            std::cout << "Your balance is " << myATM.getBalance() << std::endl;
            break;
        case 'B':
            int deposit_choice;
            std::cout << "Would you like to deposit the standard amount? Input 1 if yes, 0 if you would like a custom amount." << std::endl;
            std::cin >> deposit_choice;
            if (deposit_choice == 1) {
                myATM.deposit(100);
                std::cout << "You have deposited 100. Your new balance is " << myATM.getBalance() << std::endl;
            }
            else if (deposit_choice == 0) {
                double deposit_amount;
                std::cout << "Please define the amount to deposit." << std::endl;
                std::cin >> deposit_amount;
                myATM.deposit(deposit_amount);
                std::cout << "You have deposited " << deposit_amount << ". Your new balance is " << myATM.getBalance() << std::endl;
            }
            else {
                std::cout << "Invalid input. Returning to menu." << std::endl;
            }
            break;
        case 'C':
            int withdrawal_choice;
            std::cout << "Would you like to withdraw the standard amount? Input 1 if yes, 0 if you would like a custom amount." << std::endl;
            std::cin >> withdrawal_choice;
            if (withdrawal_choice == 1) {
                myATM.withdraw(100);
                std::cout << "You have withdrawn 100. Your new balance is " << myATM.getBalance() << std::endl;
            }
            else if (withdrawal_choice == 0) {
                double withdrawal_amount;
                std::cout << "Provide the amount to withdraw." << std::endl;
                std::cin >> withdrawal_amount;
                myATM.withdraw(withdrawal_amount);
                std::cout << "You have successfully withdrawn " << withdrawal_amount << ". Your new balance is " << myATM.getBalance() << std::endl;
            }
            else {
                std::cout << "Invalid input. Returning to menu." << std::endl;
            }
            break;
        case 'Q':
            std::cout << "Quitting program." << std::endl;
            return 0;
        default:
            std::cout << "Invalid input. Try again." << std::endl;
            break;
        }
    }
}

