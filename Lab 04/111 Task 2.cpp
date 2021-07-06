#include<iostream>
using namespace std;

class BankAccount
{
private:
    int no;
    string name;
    string type;
    double balance;
    double minbalance;
public:
    BankAccount():balance(0),minbalance(0)
    {
    }
    void getData(int n,string nm,string tp,double bl)
    {
         no=n;
        name=nm;
        type=tp;
        balance=bl;
        deposit(bl);
        //minbalance=mb;

    }

    void showBalance()
    {
        cout<<"Account of "<<name<<" with account no "<<no<<" has balance "<<balance<<" BDT"<<endl;

    }
    void deposit(double b)
    {
    balance+=b;
    }
    double get_minbalance(double mb=0)
    {
        minbalance=mb;
        if(minbalance==0)
        {
        if (type=="Current")
            minbalance=500;
        else
            minbalance=1000;
        }
        return minbalance;
    }

    void withdrawal(double amount)
    {
        if(balance-amount<minbalance)
        {
            cout<<"Not sufficient Amount present"<<endl;
            return;
        }
        else
        {
            balance-=amount;
        }
    }
    double giveInterest(double rate=2.5)
    {
        double intrst=balance*rate/100;
        double resultant=intrst*.9;
        deposit(resultant);
    }
    ~BankAccount()
    {
        cout<<"Account of "<<name<<" with account no "<<no<<" is destroyed  with a balance BDT"<<balance<<endl;

    }

};
int main()
{

    BankAccount b1,b2;
    b1.getData(1,"abc","Current",5000);

    b1.get_minbalance(700);
    b1.withdrawal(500);
      b1.showBalance();
    b1.giveInterest();
    b1.showBalance();


    b2.getData(2,"efg","Savings",1500);
    b2.get_minbalance();
    b2.withdrawal(1000);
    b2.showBalance();
    b2.giveInterest(5);
    b2.showBalance();

}
