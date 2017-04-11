// ConsoleApplication30.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
protected:
	int accountNumber;
	double monthlyInterest;
	double rateCategory;
	double noofMonths;
	double prevbalance;
	double balance;
	float amtEnterdD, amtEnterdW;
	int accTerm;
	string clientName;
	string accountType;

public:
	BankAccount ()
	{
		monthlyInterest = 0;
		noofMonths = 0;
		amtEnterdD= 0;
		amtEnterdW = 0;
		prevbalance = 0;
		balance = 0;
		rateCategory = 0;
	}

	virtual void depositMoney() = 0;
	virtual void withdrawMoney() = 0;
	virtual void calcInterest() = 0;
	virtual void purchaseCheck() = 0;
	virtual void displayNewAccountInfo() = 0;
	 
};

class Savings : public BankAccount
{
int withFee;
public:
	Savings (int withFee)
	{
		int withFee = 2;
	}

	void calcInterest()
	{
		cout << "Thank you loyal customer for saving with us. By placing money in your saving account, an variable interest is accrued and applied to your account balance." << endl;
		cout << "For your convienience, you may calculate your future balance with interest applied in a monthly basis . Please type the number of months you would like to see calculated. ";
		cin >> noofMonths;
		cin.clear();
		cin.ignore();

		if (prevbalance >= 10000)
		{
			rateCategory = 0.02;
		}
		else
		{
			rateCategory = 0.01;
		}

		for (int i = 1; i < ((noofMonths * 12) + 1); i++)
		{
			monthlyInterest = prevbalance*(rateCategory / 12);
			balance += monthlyInterest;
		}
	}

	void depositMoney()

	{
		cout << "Please enter the desired amount you want deposited to your savings account." << endl;
		cin >> amtEnterdD;
		balance += amtEnterdD;
	}

	void withdrawMoney()
	{
		cout << "Please enter your desired withdrawl amount from your savings account. (All withdrawls from savings account will result in an $2.00 fee deducted from your account)" << endl;
		cin >> amtEnterdW;
		cin.clear();
		cin.ignore();


		if (amtEnterdW >= 0)
		{
			int withFee = 2;
			balance = prevbalance - withFee;
			balance = balance - amtEnterdW;
		}
		else
		{
			cout << "INVALID ENTRY!!!, you may not complete this transaction due to insufficient funds." << endl;
		}
	}

	void displayAccountInfo()
	{
		cout << "Name:" << clientName << endl;
		cout << "Account #: " << accountNumber << endl;
		cout << "Account's Interest Rate" << rateCategory << endl;
		cout << "Account's Total Deposits:" << amtEnterdD << endl;
		cout << "Account's Total Withdrawls:" << amtEnterdW << endl;
		cout << "Previous Balance" << prevbalance << endl;
		cout << "Balance" << balance << endl;
	}

};
 
 class Checkings : public BankAccount
	{
	 int balanceFee;
	 public :
		 Checkings(int balanceFee)
		 {
			 balanceFee = 5;
		 }

		void calcInterest()

		{
			cout << "Sorry WestHills Banking customer, checking accounts from this establishment do not accrue interest!!!!" << endl;
			cout << "You may not calculate interest for the following checking account" << endl;

		}

		void depositMoney()

		{
			cin.ignore();
			cin.clear();
			cout << "Please enter the desired amount you want deposited to your checkings account." << endl;
			cin >> amtEnterdD;
			prevbalance += amtEnterdD;
			prevbalance = balance;
		}

		void withdrawMoney()
		{
			int balanceFee;
			if (prevbalance < 500)
			{
				balanceFee = 5;
				balance = prevbalance -balanceFee;
	
			}
			else
			{
				balanceFee = 0;
				balance = prevbalance;
			}

			cout << "Please enter your desired withdrawl amount from your checkings account." << endl;
			cin >> amtEnterdW;
			cin.clear();
			cin.ignore();

			if (amtEnterdW >= 0)
				balance = prevbalance - amtEnterdW;
			else
			{
				cout << "INVALID ENTRY!!!, you may not complete this transaction due to insufficient funds." << endl;
			}

		}

		void purchaseCheck()
		{
			char input;
			cout << "Would you like to purchase a check book? Type the letter (Y)es to Continue or Type the letter (N)o to discontinue" << endl;
			cin >> input;
			if (input == 'Y' || input == 'y')
			{
				balance = prevbalance - 15;
			}
		}

		void displayAccountInfo()
		{
			cout << "Name:" << clientName << endl;
			cout << "Account #: " << accountNumber << endl;
			cout << "Account's Interest Rate" << rateCategory << endl;
			cout << "Account's Total Deposits:" << amtEnterdD << endl;
			cout << "Account's Total Withdrawls:" << amtEnterdW << endl;
			cout << "Previous Balance" << prevbalance << endl;
			cout << "Balance" << balance << endl;
		}
 };

  class COD : public BankAccount
  {

	  double earlyFee;
  public:
	  COD(double earlyFee)
	  {
		  earlyFee = prevbalance * .1;
	  }
	  void calcInterest()

	  {

		  cin.ignore();
		  cout << "For a Certificate of Deposit account, we can hold your deposit in terms from one year to an infinite amount of years and an variable interest will be added to your account" << endl;
		  cout << "For your convienience, you may calculate your future balance with interest applied in a monthly basis . Please type the number of months you would like to see calculated. ";
		  cin >> noofMonths;
		  cout << "How many years was your account term ?" << endl;
		  cin >> accTerm;

		  if (accTerm < 5)
		  {
			  rateCategory = prevbalance * .05;
			  balance = +rateCategory;
		  }
		  else
		  {
			  rateCategory = prevbalance * .1;
			  balance = +rateCategory;
		  }

		  for (int i = 1; i < ((noofMonths * 12) + 1); i++)
		  {
			  monthlyInterest = noofMonths*(rateCategory / 12);
			  balance += monthlyInterest;
		  }
	  }

	  void depositMoney()
	  {
		  cin.clear();
		  cin.ignore();
		  cout << "Please enter the desired amount you want deposited to your checkings account." << endl;
		  cin >> amtEnterdD;
		  prevbalance += amtEnterdD;
		  prevbalance = balance;
	  }

	  void withdrawMoney()
	  {
		  cout << "Our records have shown that your Certificate of Deposit account term has not been completed." << endl;
		  cout << " Due to this, you will be charged an early withdrawl fee of 10% of your current account balance." << endl;
		  cout << "Please enter your desired withdrawl amount from your COD  account." << endl;
		  cin >> amtEnterdW;
		  cin.clear();
		  cin.ignore();

		  if (amtEnterdW >= 0)
		  {

			  balance -= earlyFee;
			  balance = balance - amtEnterdW;
		  }
		  else
		  {
			  cout << "INVALID ENTRY!!!, you may not complete this transaction due to insufficient funds." << endl;
		  }
	  }

	  void displayAccountInfo()
	  {
		  cout << "Name:" << clientName << endl;
		  cout << "Account #: " << accountNumber << endl;
		  cout << "Account's Interest Rate" << rateCategory << endl;
		  cout << "Account's Total Deposits:" << amtEnterdD << endl;
		  cout << "Account's Total Withdrawls:" << amtEnterdW << endl;
		  cout << "Previous Balance" << prevbalance << endl;
		  cout << "Balance" << balance << endl;
	  }
  };




  int main()
  {
	
	  BankAccount *c = &Checkings();
	  BankAccount *d = &COD();
	  BankAccount *s = &Savings();


	  char userInput;
	  int service;
	  double accountNumber;
	  double prevbalance;
	  cout << "Welcome to WestHills Banking Service!!!" << endl;
	  cout << "Please enter your first and last name: " << endl;
	  getline(cin, clientName);
	  cin.clear();
	  cin.ignore();
	  cout << "Please enter your account number: " << endl;
	  cin >> accountNumber;
	  cout << "Please enter your account balance: ";
	  cin >> prevbalance;
	  cin.ignore();
	  cout << "What type of account would you like to open?...Type the letter (s) for an Savings account, the letter (c) for Checkings Account or the letter (d) for Certificate of Deposit Account." << endl;
	  cin >> userInput;


	  if ((userInput == 'S') || (userInput == 's'))
	  {
		  s = &Savings();
		  cout << "What type of service would you like to perform on this account...Type the number (1) to to calculate interest for account, (2) to deposit, (3) to withdraw, (4) to purchase checkbook for account (5) to display account activities." << endl;
		  cin >> userInput;

		  if ((service == '1'))
		  {
			  s->calcInterest();
		  }
		  else if ((service == '2'))
		  {
			  s->depositMoney();
		  }
		  else if ((userInput == '3'))
		  {
			  s->withdrawMoney();
		  }
		  else if ((userInput == '4'))
		  {
			  s->displayNewAccountInfo();
		  }
	  }
	  else if ((userInput == 'C') || (userInput == 'c'))
	  {
		  c = &Checkings();
		  cout << "What type of service would you like to perform on this account...Type the number (1) to withdraw, (2) to deposit, (3) to calculate balance interest or (4) to purchase a checkbook or (5) to display account activities." << endl;
		  cin >> userInput;

		  if ((service == '1'))
		  {
			  c->calcInterest();
		  }
		  else if ((service == '2'))
		  {
			  c->depositMoney();
		  }
		  else if ((userInput == '3'))
		  {
			  c->withdrawMoney();
		  }
		  else if ((userInput == '4'))
		  {
			  c->purchaseCheck();
		  }
		  else if ((userInput == '5'))
		  {
			  c->displayNewAccountInfo();
		  }
	  }
	  else if ((userInput == 'D') || (userInput == 'd'))
	  {
		  d = &COD;
		  cout << "What type of service would you like to perform on this account...Type the number (1) to withdraw, (2) to deposit, (3) to calculate balance interest or (4) to display account activities." << endl;
		  cin >> userInput;

		  if ((service == '1'))
		  {
			  d->calcInterest();
		  }
		  else if ((service == '2'))
		  {
			  d->depositMoney();
		  }
		  else if ((userInput == '3'))
		  {
			  d->withdrawMoney();
		  }
		  else if ((userInput == '4'))
		  {
			  d->displayNewAccountInfo();
		  }
	  }

	  return 0;
  }