#include <iostream>
#include <vector>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string name;
    double balance;

public:
    BankAccount(int accNo, string holderName, double initialBalance) {
        accountNumber = accNo;
        name = holderName;
        balance = initialBalance;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful!\n";
        } else {
            cout << "Invalid amount!\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful!\n";
        } else {
            cout << "Insufficient balance or invalid amount!\n";
        }
    }

    void display() {
        cout << "\n--- Account Details ---\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << name << endl;
        cout << "Balance: $" << balance << endl;
    }
};

// Find account in list
BankAccount* findAccount(vector<BankAccount> &accounts, int accNo) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == accNo) {
            return &accounts[i];
        }
    }
    return nullptr;
}

int main() {
    vector<BankAccount> accounts;

    int choice;

    do {
        cout << "\n====== Bank Menu ======\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. View Account Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int accNo;
            string name;
            double balance;

            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Account Holder Name: ";
            cin >> name;
            cout << "Enter Initial Balance: ";
            cin >> balance;

            accounts.push_back(BankAccount(accNo, name, balance));
            cout << "Account created successfully!\n";
        }

        else if (choice == 2) {
            int accNo;
            double amount;

            cout << "Enter Account Number: ";
            cin >> accNo;

            BankAccount* acc = findAccount(accounts, accNo);

            if (acc != nullptr) {
                cout << "Enter deposit amount: ";
                cin >> amount;
                acc->deposit(amount);
            } else {
                cout << "Account not found!\n";
            }
        }

        else if (choice == 3) {
            int accNo;
            double amount;

            cout << "Enter Account Number: ";
            cin >> accNo;

            BankAccount* acc = findAccount(accounts, accNo);

            if (acc != nullptr) {
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                acc->withdraw(amount);
            } else {
                cout << "Account not found!\n";
            }
        }

        else if (choice == 4) {
            int accNo;

            cout << "Enter Account Number: ";
            cin >> accNo;

            BankAccount* acc = findAccount(accounts, accNo);

            if (acc != nullptr) {
                acc->display();
            } else {
                cout << "Account not found!\n";
            }
        }

        else if (choice == 5) {
            cout << "Exiting program...\n";
        }

        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}