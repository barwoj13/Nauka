#include <iostream>
#include <string>

class BankAccount
{
private:
	std::string accountNumber;
	std::string ownerName;
	double balance;

public:
	BankAccount(std::string& accountNumber, std::string& ownerName, double balance = 0.0)
		: accountNumber(accountNumber), ownerName(ownerName), balance(balance) {
	}

	void deposit(double amount)
	{
		if (amount <= 0.0) return;
		balance += amount;
	}

	bool withdraw(double amount)
	{
		if (amount <= 0.0) return false;
		if (amount > balance) return false;
		balance -= amount;
		return true;
	}

	double getBalance() const 
	{
		return balance;
	}

	void printInfo() const
	{
		std::cout << accountNumber << " " << ownerName << " " << balance << std::endl;
	}


};


int main() 
{

}