#include <iostream>
#include <string>
using namespace std;
class BankAccount {
protected:
    string accountNumber;
    string accountHolderName;
private:
    double balance;

public:
    BankAccount(string accnum, string accholder, double bal): accountNumber(accnum), accountHolderName(accholder), balance(bal) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount <<"\n";
    }
    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount <<"\n";
        } else {
            cout << "Insufficient balance!\n";
        }
    }

    double getBalance() const {
        return balance;
    }

    virtual void displayAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual void calculateInterest() {
        cout << "No interest calculation for base account." << endl;
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(string accnum, string accholder, double bal, double rate)
        : BankAccount(accnum, accholder, bal), interestRate(rate) {}

    void calculateInterest() override {
        double interest = getBalance() * interestRate / 100;
        cout << "Interest earned: " << interest << endl;
    }

    void displayAccountInfo() const override {
        BankAccount::displayAccountInfo();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(string accnum, string accholder, double bal, double limit)
        : BankAccount(accnum, accholder, bal), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (getBalance() + overdraftLimit >= amount) {
            // Accessing private balance through public method
            BankAccount::withdraw(amount);
        } else {
            cout << "Withdrawal exceeds overdraft limit!" << endl;
        }
    }

    void checkOverdraft() {
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }

    void displayAccountInfo() const override {
        BankAccount::displayAccountInfo();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

class FixedDepositAccount : public BankAccount {
private:
    int term;
    double interestRate;

public:
    FixedDepositAccount(string accnum, string accholder, double bal, int t, double rate)
        : BankAccount(accnum, accholder, bal), term(t), interestRate(rate) {}

    void calculateInterest() override {
        double interest = getBalance() * interestRate * term / (12 * 100);
        cout << "Fixed Deposit Interest for " << term << " months: " << interest << endl;
    }

    void displayAccountInfo() const override {
        BankAccount::displayAccountInfo();
        cout << "Term: " << term << " months" << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

int main() {
    BankAccount* account = nullptr;
    int choice;

    do {
        cout << "\n--- Bank System Menu ---\n";
        cout << "1. Add Savings Account\n";
        cout << "2. Add Checking Account\n";
        cout << "3. Add Fixed Deposit Account\n";
        cout << "4. Deposit\n";
        cout << "5. Withdraw\n";
        cout << "6. Display Account Info\n";
        cout << "7. Calculate Interest\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        string accnum, accholder;
        double bal, rate, limit;
        int term, amt;

        switch (choice) {
        case 1:
            cout << "Enter Account Number: ";
            cin >> accnum;
            cout << "Enter Account Holder Name: ";
            cin >> accholder;
            cout << "Enter Initial Balance: ";
            cin >> bal;
            cout << "Enter Interest Rate: ";
            cin >> rate;
            account = new SavingsAccount(accnum, accholder, bal, rate);
            break;

        case 2:
            cout << "Enter Account Number: ";
            cin >> accnum;
            cout << "Enter Account Holder Name: ";
            cin >> accholder;
            cout << "Enter Initial Balance: ";
            cin >> bal;
            cout << "Enter Overdraft Limit: ";
            cin >> limit;
            account = new CheckingAccount(accnum, accholder, bal, limit);
            break;

        case 3:
            cout << "Enter Account Number: ";
            cin >> accnum;
            cout << "Enter Account Holder Name: ";
            cin >> accholder;
            cout << "Enter Initial Balance: ";
            cin >> bal;
            cout << "Enter Term (months): ";
            cin >> term;
            cout << "Enter Interest Rate: ";
            cin >> rate;
            account = new FixedDepositAccount(accnum, accholder, bal, term, rate);
            break;

        case 4:
            if (account) {
                cout << "Enter amount to deposit: ";
                cin >> amt;
                account->deposit(amt);
            } else {
                cout << "No account created yet.\n";
            }
            break;

        case 5:
            if (account) {
                cout << "Enter amount to withdraw: ";
                cin >> amt;
                account->withdraw(amt);
            } else {
                cout << "No account created yet.\n";
            }
            break;

        case 6:
            if (account) {
                account->displayAccountInfo();
            } else {
                cout << "No account created yet.\n";
            }
            break;

        case 7:
            if (account) {
                account->calculateInterest();
            } else {
                cout << "No account created yet.\n";
            }
            break;

        case 8:
            cout << "Thank you for using the Bank System.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 8);

    delete account;
    return 0;
}
