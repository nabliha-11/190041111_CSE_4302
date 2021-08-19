#include<iostream>
using namespace std;

class ZooAnimal
{
    string nameofAnimal;
    int yob;
    int cn;
    float weight;
    int height;
public:
    ZooAnimal(string a,int b,int c,float d,int e):nameofAnimal(a),yob(b),cn(c),weight(d),height(e)
    {

    }
    int operator == (int data)
    {
        if(weight==data)
            return 1;
        return 0;
    }
    void operator-= (int dec)
    {
        height-=dec;
        cout<<height;
    }
};
int main()
{
    ZooAnimal z("Panda",2019,1,25,10);
    int x=25;
    cout<<(z==x)<<endl;
    //int y=2;
    z-=2;


}


