#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Account {
private:
    int accNumber;
    string accHolderName;
    double balance;
public:
    Account(int number, string name, double initial_balance) {
        accNumber = number;
        accHolderName = name;
        balance = initial_balance;
    }

    int getAccountNumber() const {
        return accNumber;
    }

    string getAccountHolderName() const {
        return accHolderName;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }
};

class Bank {
private:
    vector<Account> accounts;
public:
    void addAccount(Account acc) {
        accounts.push_back(acc);
    }

    Account* findAccount(int accNumber) {
        for (auto &acc : accounts) {
            if (acc.getAccountNumber() == accNumber) {
                return &acc;
            }
        }
        return nullptr;
    }

    void deposit(int accNumber, double amount) {
        Account* acc = findAccount(accNumber);
        if (acc != nullptr) {
            acc->deposit(amount);
            cout << "Deposit successful. Current balance: " << acc->getBalance() << endl;
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void withdraw(int accNumber, double amount) {
        Account* acc = findAccount(accNumber);
        if (acc != nullptr) {
            acc->withdraw(amount);
            cout << "Withdrawal successful. Current balance: " << acc->getBalance() << endl;
        } else {
            cout << "Account not found!" << endl;
        }
    }

    // void displayBalance(int accNumber) {
    //     Account* acc = findAccount(accNumber);
    //     if (acc != nullptr) {
    //         cout << "Account Holder Name: " << acc->getAccountHolderName() << endl;
    //         cout << "Current Balance: " << acc->getBalance() << endl;
    //     } else {
    //         cout << "Account not found!" << endl;
    //     }
    // }
};

int main() {
    Bank bank;

    // Sample usage
    Account acc1(1001, "John Doe", 1000);
    Account acc2(1002, "Jane Smith", 5000);

    bank.addAccount(acc1);
    bank.addAccount(acc2);

    int choice, accNumber;
    double amount;

    do {
        cout << "\nBank Management System\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter Account Number: ";
                cin >> accNumber;
                cout << "Enter Deposit Amount: ";
                cin >> amount;
                bank.deposit(accNumber, amount);
                break;
            case 2:
                cout << "Enter Account Number: ";
                cin >> accNumber;
                cout << "Enter Withdrawal Amount: ";
                cin >> amount;
                bank.withdraw(accNumber, amount);
                break;
            case 3:
                cout << "Enter Account Number: ";
                cin >> accNumber;
                bank.displayBalance(accNumber);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 4);

    return 0;
}
