#include<bits/stdc++.h>
using namespace std;
// Online Banking System
class Account {
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
  Account(const string& accountNumber, const string& accountHolder)
        : accountNumber(accountNumber), accountHolder(accountHolder), balance(0.0) {}

    string getAccountNumber() const {
        return accountNumber;
    }

    string getAccountHolder() const {
        return accountHolder;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " into account " << accountNumber << ". New balance: $" << balance <<  endl;
        }
         else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew $" << amount << " from account " << accountNumber << ". New balance: $" << balance <<  endl;
        } 
        else {
            cout << "Invalid withdrawal amount or insufficient funds!" <<  endl;
        }
    }

    void transfer(Account& toAccount, double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            toAccount.balance += amount;
             cout << "Transferred $" << amount << " from account " << accountNumber << " to account " << toAccount.accountNumber <<  endl;
        } else {
             cout << "Invalid transfer amount or insufficient funds!" <<  endl;
        }
    }
};

class Bank {
private:
     unordered_map< string, Account> accounts;

public:
    void createAccount(const  string& accountNumber, const  string& accountHolder) {
        if (accounts.find(accountNumber) == accounts.end()) {
            accounts[accountNumber] = Account(accountNumber, accountHolder);
             cout << "Account created successfully for " << accountHolder << " with account number " << accountNumber <<  endl;
        }
         else {
             cout << "Account number already exists!" <<  endl;
        }
    }

    Account* getAccount(const  string& accountNumber) {
        if (accounts.find(accountNumber) != accounts.end()) {
            return &accounts[accountNumber];
        } else {
             cout << "Account not found!" <<  endl;
            return nullptr;
        }
    }
};

void showMenu() {
     cout << "------ Online Banking System ------" <<  endl;
     cout << "1. Create Account" <<  endl;
     cout << "2. Deposit" <<  endl;
     cout << "3. Withdraw" <<  endl;
     cout << "4. Transfer" <<  endl;
     cout << "5. Check Balance" <<  endl;
     cout << "6. Exit" <<  endl;
     cout << "-----------------------------------" <<  endl;
     cout << "Enter your choice: ";
}

int main() {
    Bank bank;
    int choice;
     string accountNumber, accountHolder, toAccountNumber;
    double amount;
    do {
        showMenu();
         cin >> choice;
        switch (choice) {
            case 1:
                 cout << "Enter account number: ";
                 cin >> accountNumber;
                 cout << "Enter account holder name: ";
                 cin >> accountHolder;
                bank.createAccount(accountNumber, accountHolder);
                break;
            case 2:
                 cout << "Enter account number: ";
                 cin >> accountNumber;
                 cout << "Enter amount to deposit: ";
                 cin >> amount;
                if (Account* acc = bank.getAccount(accountNumber)) {
                    acc->deposit(amount);
                }
                break;
            case 3:
                 cout << "Enter account number: ";
                 cin >> accountNumber;
                 cout << "Enter amount to withdraw: ";
                 cin >> amount;
                if (Account* acc = bank.getAccount(accountNumber)) {
                    acc->withdraw(amount);
                }
                break;
            case 4:
                 cout << "Enter from account number: ";
                 cin >> accountNumber;
                 cout << "Enter to account number: ";
                 cin >> toAccountNumber;
                 cout << "Enter amount to transfer: ";
                 cin >> amount;
                if (Account* fromAcc = bank.getAccount(accountNumber)) {
                    if (Account* toAcc = bank.getAccount(toAccountNumber)) {
                        fromAcc->transfer(*toAcc, amount);
                    }
                }
                break;
            case 5:
                 cout << "Enter account number: ";
                 cin >> accountNumber;
                if (Account* acc = bank.getAccount(accountNumber)) {
                     cout << "Account balance for " << acc->getAccountHolder() << ": $" << acc->getBalance() <<  endl;
                }
                break;
            case 6:
                 cout << "Exiting the system." <<  endl;
                break;
            default:
                 cout << "Invalid choice! Please try again." <<  endl;
                break;
        }
    }
    while(choice!=6);

    return 0;
}
