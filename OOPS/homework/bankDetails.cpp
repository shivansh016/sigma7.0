#include<iostream>
#include<string>
using namespace std;

class BankAccount{
    private:
   
    int accountNumber;
    int balance ;
    
    public:

    BankAccount( int accNum, int bal){
        accountNumber = accNum;
        balance = bal;
    }

    void deposit(int amount){
        balance = balance + amount;
        cout << "Deposited :" << amount << endl;
    }

    void withdraw(int amount){
        if (amount > balance){
            getBalance();
            cout << "Insufficient Balance to withdraw " << amount << endl;
        }
        else{
            balance = balance - amount;
            cout << "Withdrawn :"<< amount << endl;
        }
        }

    void getBalance(){
        cout << "Current Balance : " << balance << endl;
    }
    };


int main(){
    BankAccount acc1(987654321, 1000);
    acc1.getBalance();
    acc1.deposit(500);
    acc1.getBalance();
    acc1.withdraw(60000);
    acc1.withdraw(200);
    acc1.getBalance();
    return 0;
}
 