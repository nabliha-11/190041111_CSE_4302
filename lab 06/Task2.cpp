#include<iostream>
using namespace std;

class FLOAT
{
    float data;

public:
    FLOAT():data(0) {}
    FLOAT(float d):data(d) {}
    // friend FLOAT operator + (float f1,FLOAT f);
    //friend FLOAT operator - (float f1,FLOAT f);
    //friend     FLOAT operator * (float f1,FLOAT f);
    //friend FLOAT operator / (FLOAT f,float f1);
    operator int();
    FLOAT operator +(float f1)
    {
        return FLOAT(data+f1);
    }
    FLOAT operator - (float f1)
    {
        return FLOAT(data-f1);
    }
    FLOAT operator * (float f1)
    {
        return FLOAT(f1*data);
    }
    FLOAT operator / (float f1)
    {
        if(data==0)
        {
            cout<<"Invalid"<<endl;
            return FLOAT(data);
        }
        return FLOAT(data/f1);
    }
    float getData()
    {
        return data;
    }



};
FLOAT::operator int()
{
    return data;
}
/*FLOAT operator + (float f1,FLOAT f)
{
    return FLOAT(f1+f.data);
}*/

int main()
{
    FLOAT f1,f3;
    FLOAT f2(2.00);
    cout<<f1.getData()<<endl;
    cout<<f2.getData()<<endl;
    f3=5+f2;
    cout<<f3.getData()<<endl;
    f3=6-f2;

    cout<<f3.getData()<<endl;
    f3=3*f2;

    cout<<f3.getData()<<endl;
    f3=f2/2;

    cout<<f3.getData()<<endl;
    float f4(3.56);
    int i=f4;
    cout<<i;
}
