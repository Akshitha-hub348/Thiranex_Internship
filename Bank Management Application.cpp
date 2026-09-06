#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string name;
    double balance;

public:
    BankAccount()
    {
        accountNumber = 0;
        name = "";
        balance = 0;
    }

    void createAccount()
    {
        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cin.ignore();
        cout << "Enter Account Holder Name: ";
        getline(cin, name);

        cout << "Enter Initial Balance: ";
        cin >> balance;

        cout << "\nAccount created successfully!\n";
    }

    void deposit()
    {
        double amount;

        cout << "Enter amount to deposit: ";
        cin >> amount;

        if (amount > 0)
        {
            balance += amount;
            cout << "Amount deposited successfully.\n";
        }
        else
        {
            cout << "Invalid amount.\n";
        }
    }

    void withdraw()
    {
        double amount;

        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid amount.\n";
        }
        else if (amount > balance)
        {
            cout << "Insufficient balance.\n";
        }
        else
        {
            balance -= amount;
            cout << "Amount withdrawn successfully.\n";
        }
    }

    void displayBalance()
    {
        cout << "\nAccount Number : " << accountNumber;
        cout << "\nAccount Holder : " << name;
        cout << "\nBalance        : " << balance << endl;
    }

    void saveToFile()
    {
        ofstream file("bank.txt");

        if (file.is_open())
        {
            file << accountNumber << endl;
            file << name << endl;
            file << balance << endl;

            file.close();
        }
    }

    bool loadFromFile()
    {
        ifstream file("bank.txt");

        if (!file)
            return false;

        file >> accountNumber;
        file.ignore();
        getline(file, name);
        file >> balance;

        file.close();
        return true;
    }
};

int main()
{
    BankAccount account;
    int choice;

    if (account.loadFromFile())
        cout << "Previous account data loaded.\n";

    do
    {
        cout << "\n========== BANK MANAGEMENT SYSTEM ==========\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Save and Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            account.createAccount();
            break;

        case 2:
            account.deposit();
            account.saveToFile();
            break;

        case 3:
            account.withdraw();
            account.saveToFile();
            break;

        case 4:
            account.displayBalance();
            break;

        case 5:
            account.saveToFile();
            cout << "Account data saved. Thank you!\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
