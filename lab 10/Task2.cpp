#include<iostream>
using namespace std;

class House{
private:
    /*House(const House &house2):name(house2.name),strength(house2.strength),current_point(house2.current_point) //copy constructor;
    {

    }
    House operator = (const House &house2)      //copy assignment operator;
    {

       return *this;

    }*/
protected:
    string name;
    int strength;
    double current_point;

public:
    House()
    {

    }
    House(string nm,int s,double cp):name(nm),strength(s),current_point(cp)
    {

    }
    House(const House &house2):strength(house2.strength),current_point(house2.current_point) //copy constructor;
    {

    }
    House operator = (const House &house2)      //copy assignment operator;
    {
        strength=house2.strength;
        current_point=house2.current_point;
       // return House(name,strength,current_point);
       return *this;


    }
    void set_name(string nm)
    {
        name=nm;
    }
    void set_strength(int s)
   {
       strength=s;
   }
   void update_points(double p)
   {
       current_point+=p;
   }
    void show_data()
    {
        cout<<"House: "<<name<<endl;
        cout<<"Strength: "<<strength<<endl;
        cout<<"Current Points: "<<current_point<<endl;
        cout<<endl;
    }



};
int main()
{
    House h1;
    House h2("Slytherin",102,200);
    House h3(h2); //copy initialization;
    h1.set_name("Gryffindor");
    h3.set_name("Ravenclaw");
    h1=h2;
    House h4("Hufflepuff",103,130);
    h4=h3;
    h1.update_points(10);
    h1.show_data();
    h2.show_data();
    h3.show_data();
    h4.show_data();

}
