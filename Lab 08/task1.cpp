#include<iostream>
using namespace std;

class Account     //base(parent) class
{
private:
    string accountNo;
    string accountName;
    float balance;

public:
    Account()
    {

    }
     void setAccNo(string an)
    {
        accountNo=an;
    }
    void setaccName(string name)
    {
        accountName=name;
    }
    void setbalance(float bl)
    {
        balance=bl;
    }
    string getAccNo()
    {
        return accountNo;
    }
    string getAccName()
    {
        return accountName;
    }
    float getbalance()
    {
        return balance;
    }
};
class CurrentAccount:public Account               //Derived1 (child) class
{
private:
    const static int serviceCharge=100;
    const static int accountPrefix=100;
    static int nextAccount;

public:

    CurrentAccount(string n="", float b=0)
    {
        nextAccount++;              //increasing value of next account by one each time a new account(obj) is created;
        Account::setaccName(n);
        string s,a;                //converting prefix and next account from int to string;
       s=to_string(nextAccount);
       a=to_string(accountPrefix);
       Account::setAccNo(a+s);
        Account::setbalance(b);
    }

   void nextAccountNo(int an)
   {
       nextAccount=an;
   }
   int getServiceCharge()const
   {
       return serviceCharge;
   }
   int getAccountPrefix()const
   {
       return accountPrefix;
   }
   int getNextAcc()
   {
       return nextAccount;
   }
     string getAccTyp()
    {
        return string("Current Account");
    }
    void display()
    {
        cout<<"Account type: "<<getAccTyp()<<"\nAccount Name: "<<Account::getAccName()<<"\nAccount no: "<<Account::getAccNo()<<"\nBalance: "<<Account::getbalance();
        cout<<"\nService Charge: "<<getServiceCharge()<<endl;


    }

   ~CurrentAccount()
   {

   }
};
int CurrentAccount::nextAccount=0; //declaring static int nextAccount
class SavingAccount:public Account  //derived2 (child class)
{
private:
    float interestRate;
    float monthlyDepositAmount;
    const static int accountPrefix = 200;
    static int nextAccount;
public:
    SavingAccount(string name="", float mDA=500.00,float iR=2.00,float b=0):monthlyDepositAmount(mDA),interestRate(iR)
    {
        nextAccount++;
        Account::setaccName(name);
        string s,a;
       s=to_string(nextAccount);
       a=to_string(accountPrefix);
        Account::setAccNo(a+s);
        Account::setbalance(b);
    }
    void setInterestRate(float IR)
    {
        interestRate=IR;
    }
    void setMonthlyDepositAmount(float mda)
    {
        monthlyDepositAmount=mda;
    }
    float getInterestRate()
    {
        return interestRate;
    }
    float getMonthlyDepositAmount()
    {
        return monthlyDepositAmount;
    }
      string getAccTyp()
    {
        return string("Saving Account");
    }
  void display()
    {
        cout<<"Account type: "<<getAccTyp()<<"\nAccount Name: "<<Account::getAccName()<<"\nAccount no: "<<Account::getAccNo()<<"\nBalance: "<<Account::getbalance();
        cout<<"Monthly Deposit Amount: "<<getMonthlyDepositAmount()<<endl;
        cout<<"Interest Rate : "<<getInterestRate()<<endl;

    }

};
int SavingAccount::nextAccount=0; //declaring static int nextAccount
class MonthlyDepositScheme:public Account //derived3 (child) class
{
    float interestRate;
    float monthlyDepositAmount;
    const static int accountPrefix = 300;

public:
    static int nextAccount;       //not private to access from derived class.
    MonthlyDepositScheme()
    {
        nextAccount++;
    }
    void setInterestRate(float ir)
    {
        interestRate=ir;
    }
    void setMonthlyDepositAmount(float mda)
    {
        monthlyDepositAmount=mda;
    }
    float getInterestRate()
    {
        return interestRate;
    }
    float getMonthlyDepositAmount()
    {
        return monthlyDepositAmount;
    }

    string getAccountNo()
    {
        string t;
        string s,a;
       s=to_string(nextAccount);
       a=to_string(accountPrefix);
       t=a+s;
       return t;
    }

    ~MonthlyDepositScheme()
    {

    }
};
int MonthlyDepositScheme::nextAccount=0; //declaring static int nextAccount
class TwoYearMDS: public MonthlyDepositScheme //grandchild class of Account derived from MonthlyDepositScheme
{
private:
    float maxInterest;
public:
    TwoYearMDS(string name="",float ir=2,float mda=500,float maxIr=12,float b=500):maxInterest(maxIr)
    {

        Account::setaccName(name);
        Account::setAccNo(MonthlyDepositScheme::getAccountNo());
        Account::setbalance(b);
        MonthlyDepositScheme::setInterestRate(ir);
        MonthlyDepositScheme::setMonthlyDepositAmount(mda);

    }
    void setMaximumInterest(float mir)
    {
        maxInterest=mir;
    }
    float getMaxInterest()
    {
        return maxInterest;
    }
    string getAccTyp()
    {
        return string("Two Year Deposit Scheme ");
    }
    void display()
    {
        cout<<"Account type: "<<getAccTyp()<<"\nAccount Name: "<<Account::getAccName()<<"\nAccount no: "<<Account::getAccNo()<<"\nBalance: "<<Account::getbalance()<<endl;
        cout<<"Monthly Deposit Amount: "<<MonthlyDepositScheme::getMonthlyDepositAmount()<<endl;
        cout<<"Interest Rate : "<<MonthlyDepositScheme::getInterestRate()<<endl;
        cout<<"Max Interest Rate: "<<getMaxInterest()<<endl;
    }
};
class FiveYearMDS: public MonthlyDepositScheme //grandchild class of Account derived from MonthlyDepositScheme
{
private:
    float maxInterest;
public:
    FiveYearMDS(string name="",float ir=5,float mda=500,float maxIr=15,float b=500):maxInterest(maxIr)
    {

        Account::setaccName(name);
        Account::setAccNo(MonthlyDepositScheme::getAccountNo());
        Account::setbalance(b);
        MonthlyDepositScheme::setInterestRate(ir);
        MonthlyDepositScheme::setMonthlyDepositAmount(mda);

    }
    void setMaximumInterest(float mir)
    {
        maxInterest=mir;
    }
    float getMaxInterest()
    {
        return maxInterest;
    }
    string getAccTyp()
    {
        return string("Five Year Deposit Scheme");
    }
    void display()
    {
        cout<<"Account type: "<<getAccTyp()<<"\nAccount Name: "<<Account::getAccName()<<"\nAccount no: "<<Account::getAccNo()<<"\nBalance: "<<Account::getbalance()<<endl;
        cout<<"Monthly Deposit Amount: "<<MonthlyDepositScheme::getMonthlyDepositAmount()<<endl;
        cout<<"Interest Rate : "<<MonthlyDepositScheme::getInterestRate()<<endl;
        cout<<"Max Interest Rate: "<<getMaxInterest()<<endl;
    }
};
class InitialDepositMDS: public MonthlyDepositScheme //grandchild class of Account derived from MonthlyDepositScheme
{
private:
    float maxInterest;
    float initialDepositAmount;
public:
    InitialDepositMDS(string name=" ",float ir=2,float mda=500,float maxIr=12,float b=500,float ida=500):maxInterest(maxIr),initialDepositAmount(ida)
    {

        Account::setaccName(name);
        Account::setAccNo(MonthlyDepositScheme::getAccountNo());
        Account::setbalance(b);
        MonthlyDepositScheme::setInterestRate(ir);
        MonthlyDepositScheme::setMonthlyDepositAmount(mda);

    }
    void setMaximumInterest(float mir)
    {
        maxInterest=mir;
    }
    float getMaxInterest()
    {
        return maxInterest;
    }
    string getAccTyp()
    {
        return string("Initial Deposit Scheme ");
    }
    void setInitialDepositAmount(float ida)
    {
        initialDepositAmount=ida;
    }
    float getInitialDepoamount()
    {
        return initialDepositAmount;
    }

    void display()
    {
        cout<<"Account type: "<<getAccTyp()<<"\nAccount Name: "<<Account::getAccName()<<"\nAccount no: "<<Account::getAccNo()<<"\nBalance: "<<Account::getbalance()<<endl;
        cout<<"Monthly Deposit Amount: "<<MonthlyDepositScheme::getMonthlyDepositAmount()<<endl;
        cout<<"Interest Rate : "<<MonthlyDepositScheme::getInterestRate()<<endl;
        cout<<"Max Interest Rate: "<<getMaxInterest()<<endl;
        cout<<"Initial Deposit: "<<getInitialDepoamount()<<endl;
    }
};
class Loan:public Account //derived4(child) class
{
private:
    float interestRate;
    float monthlyDepositAmount;
    const static int accountPrefix = 900;
    static int nextAccount;
public:
    Loan(string name="",float ir=2,float mda=500,float b=0):interestRate(ir),monthlyDepositAmount(mda)
    {
        nextAccount++;
        Account::setaccName(name);
        string s,a;
       s=to_string(nextAccount);
       a=to_string(accountPrefix);
        Account::setAccNo(a+s);
        Account::setbalance(b);

    }
    void setInterestRate(float ir)
    {
        interestRate=ir;
    }
    void setMonthlyDepAmount(float mda)
    {
        monthlyDepositAmount=mda;
    }
    float getInterestRate()
    {
        return interestRate;
    }
    float getMonthlyDepAmount()
    {
        return monthlyDepositAmount;
    }
    string getAccTyp()
    {
        return string("Loan Account");
    }
    void display()
    {
        cout<<"Account type: "<<getAccTyp()<<"\nAccount Name: "<<Account::getAccName()<<"\nAccount no: "<<Account::getAccNo()<<"\nBalance: "<<Account::getbalance()<<endl;
        cout<<"Monthly Deposit Amount: "<<getMonthlyDepAmount()<<endl;
        cout<<"Interest Rate : "<<getInterestRate()<<endl;

    }
};
int Loan::nextAccount=0; //static int nextAccount of Loan;
int main()
{
    CurrentAccount c("abc",500);
    c.display();
    CurrentAccount c2("www",1000);
    c2.display();
    SavingAccount s("bcd",500,2,1000);
    s.display();
    TwoYearMDS t("cde",2,500,12,1000);
    t.display();
    FiveYearMDS f("def",5,500,15,1000);
    f.display();
    InitialDepositMDS i("efg",2,500,12,1500,1000);
    i.display();
    Loan l("fgh",2,500,1000);
    l.display();
}
