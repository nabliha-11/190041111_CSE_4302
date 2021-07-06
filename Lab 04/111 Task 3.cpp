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
    ZooAnimal()
    {

    }
    void getData()
    {
        cin>>nameofAnimal>>yob>>cn>>weight>>height;
    }
    string getName()
    {
       return nameofAnimal;
    }
    void setName(string name)
    {
        nameofAnimal=name;
    }
    int getYob()
    {
        return yob;
    }
    void setYob(int y=2021)
    {
        yob=y;
    }
    int getCn()
    {
        return cn;
    }
    void setCn(int c)
    {
        cn=c;
    }
    float getweight()
    {
        return weight;
    }
    void setweight(float w)
    {
        weight=w;
    }
    int getheight()
    {
        return height;
    }
   void setheight(int h)
    {

        height=h;
    }
    int getAge()
    {
        int age=2021-yob;
        return age;

    }
    void getInformation()
    {
        cout<<"Displaying info: "<<endl;
        cout<<"Name of animal: "<<nameofAnimal<<endl;
        cout<<"Birth year: "<<yob<<endl;
        cout<<"Cage no: "<<cn<<endl;
        cout<<"weight :"<<weight<<endl;
        cout<<"height : "<<height<<endl;
        cout<<"Age :"<<getAge()<<endl;
    }
};
int main()
{
    ZooAnimal a;
    a.setName("Panda");
    a.setYob(2019);
    a.setCn(1);
    a.setweight(10);
    a.setheight(12);
    a.getInformation();
}

