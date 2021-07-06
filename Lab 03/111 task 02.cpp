#include<bits/stdc++.h>
using namespace std;
class RationalNumber
{
private:
    int numerator;
    int denominator;
public:
    void assign(int numerator,int denominator)
    {
        if(denominator==0)
        {
            cout<<"Error : undefined"<<endl;
            return;
        }
        RationalNumber::numerator=numerator;
        RationalNumber::denominator=denominator;

    }
    double convert()
    {
        double n=numerator,d=denominator,ans;
        ans=n/d;
        return ans;
    }
    void invert()
    {
        if(numerator==0)
        {
            cout<<"Error : Undefined"<<endl;
            return;
        }
       /* int temp;
        temp=denominator;
        denominator=numerator;
        numerator=temp;*/
        swap(numerator,denominator);
    }
    void print()
    {
        cout<<"The Rational Number is "<<numerator<<"/"<<denominator<<endl;
    }
};
int main()
{
    RationalNumber rn;
    int num,den;
    cin>>num>>den;
    rn.assign(num,den);
    cout<<"Before inverting: "<<endl;
    rn.print();
    cout<<"="<<rn.convert()<<endl;
    rn.invert();
     cout<<"After inverting: "<<endl;
    rn.print();
    cout<<"="<<rn.convert()<<endl;

}
