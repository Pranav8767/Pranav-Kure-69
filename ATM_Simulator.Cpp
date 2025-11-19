#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// 🔹 Base Class: Account
class Account {
protected:
    string username;
    string pin;
    double balance;

public:
    Account(string user = "", string p = "", double bal = 0.0)
        : username(user), pin(p), balance(bal) {}

    string getUsername() const { return username; }
    bool authenticate(string enteredPin) const { return enteredPin == pin; }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited ₹" << amount << " successfully.\n";
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!\n";
            return false;
        }
        balance -= amount;
        cout << "Withdrawn ₹" << amount << " successfully.\n";
        return true;
    }

    double getBalance() const { return balance; }

    void display() const {
        cout << "\n--- Account Info ---\n";
        cout << "Username: " << username << endl;
        cout << "Balance : ₹" << fixed << setprecision(2) << balance << endl;
    }
};

// 🔹 Derived Class: ATM — extends Account functionality
class ATM {
    vector<Account> accounts;
    string filename = "accounts.txt";

public:
    ATM() { loadAccounts(); }
    ~ATM() { saveAccounts(); }

    // 🔸 Load account data from file
    void loadAccounts() {
        ifstream file(filename);
        if (!file) return;

        string user, pin;
        double bal;
        while (file >> user >> pin >> bal)
            accounts.emplace_back(user, pin, bal);
        file.close();
    }

    // 🔸 Save account data to file
    void saveAccounts() {
        ofstream file(filename);
        for (auto &acc : accounts)
            file << acc.getUsername() << " "
                 << "****"
                 << " " << acc.getBalance() << "\n"; // Mask PIN in file (for safety)
        file.close();
    }

    // 🔸 Create new account
    void createAccount() {
        string user, pin;
        double deposit;

        cout << "\nEnter Username: ";
        cin >> user;
        cout << "Set 4-digit PIN: ";
        cin >> pin;
        cout << "Enter Initial Deposit (Rupee): ";
        cin >> deposit;

        accounts.emplace_back(user, pin, deposit);
        cout << "Account created successfully!\n";
    }

    // 🔸 Find account by username
    Account* findAccount(string user) {
        for (auto &acc : accounts)
            if (acc.getUsername() == user)
                return &acc;
        return nullptr;
    }

    // 🔸 Login and access account
    void login() {
        string user, pin;
        cout << "\nEnter Username: ";
        cin >> user;
        Account* acc = findAccount(user);
        if (!acc) {
            cout << "No account found for username: " << user << endl;
            return;
        }

        cout << "Enter PIN: ";
        cin >> pin;

        if (!acc->authenticate(pin)) {
            cout << "Invalid PIN!\n";
            return;
        }

        cout << "\n✅ Login Successful. Welcome, " << user << "!\n";
        atmMenu(*acc);
    }

    // 🔸 ATM menu for logged-in user
    void atmMenu(Account &acc) {
        int choice;
        do {
            cout << "\n========= ATM MENU =========\n";
            cout << "1. Check Balance\n";
            cout << "2. Deposit Money\n";
            cout << "3. Withdraw Money\n";
            cout << "4. Logout\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "\nCurrent Balance: (Ruppe)" << fixed << setprecision(2)
                         << acc.getBalance() << endl;
                    break;
                case 2: {
                    double amt;
                    cout << "Enter amount to deposit: (Ruppe)";
                    cin >> amt;
                    acc.deposit(amt);
                    break;
                }
                case 3: {
                    double amt;
                    cout << "Enter amount to withdraw: (Ruppe)";
                    cin >> amt;
                    acc.withdraw(amt);
                    break;
                }
                case 4:
                    cout << "Logging out...\n";
                    break;
                default:
                    cout << "Invalid choice!\n";
            }
        } while (choice != 4);
    }

    // 🔸 Main Menu
    void mainMenu() {
        int choice;
        do {
            cout << "\n========= WELCOME TO ATM SYSTEM =========\n";
            cout << "1. Create New Account\n";
            cout << "2. Login to Account\n";
            cout << "3. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: createAccount(); break;
                case 2: login(); break;
                case 3:
                    cout << "Thank you for using the ATM System!\n";
                    saveAccounts();
                    break;
                default:
                    cout << "Invalid choice! Try again.\n";
            }
        } while (choice != 3);
    }
};

// 🔹 Main Function
int main() {
    ATM atm;
    atm.mainMenu();
    return 0;
}
