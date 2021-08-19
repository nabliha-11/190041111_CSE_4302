#include<iostream>
#include<cmath>
using namespace std;

class Coordinate
{
private:
    float abscissa,ordinate;
public:
    Coordinate(float x,float y):abscissa(x),ordinate(y)
    {

    }
    float getDistance(Coordinate c)
    {
        return sqrt(((c.abscissa-abscissa)*(c.abscissa-abscissa))+((c.ordinate-ordinate)*(c.ordinate-ordinate)));
    }
    float getDistance()
    {
        return sqrt(((abscissa)*(abscissa))+(ordinate)*(ordinate));
    }
    void move_x(float val)
    {
        abscissa+=val;
    }
    void move_y(float val)
    {
        ordinate+-val;
    }
    void move(float val)
    {
        move_x(val);
        move_y(val);
    }
   friend bool operator < (Coordinate a,Coordinate b)
    {
        return a.getDistance()<b.getDistance();

    }
 friend bool operator >(Coordinate a,Coordinate b)
    {
        return a.getDistance()>b.getDistance();
    }
    friend bool operator <=(Coordinate a,Coordinate b)
    {
        return a.getDistance()<=b.getDistance();
    }
   friend bool operator >=(Coordinate a,Coordinate b)
    {
        return a.getDistance()>=b.getDistance();
    }
   friend bool operator ==(Coordinate a,Coordinate b)
    {
        return a.getDistance()==b.getDistance();
    }
    friend bool operator !=(Coordinate a,Coordinate b)
    {
        return a.getDistance()!=b.getDistance();
    }
    Coordinate &operator =(Coordinate &c)
    {
        abscissa=c.abscissa;
        ordinate=c.ordinate;

    //return Coordinate;
    }
    Coordinate operator++()
    {
        return Coordinate(abscissa++,ordinate++);
        //move(1);
        //return Coordinate;
    }
    Coordinate operator++(int)
    {
       Coordinate temp(abscissa,ordinate);
       abscissa++;
       ordinate++;
       return temp;
               return temp;

        //Coordinate temp;
     //   move(1);
        //return;
    }
     Coordinate operator--()
    {
        return Coordinate(abscissa--,ordinate--);

        //move(-1);
        //return;
    }
     Coordinate operator--(int)
    {
        Coordinate temp(abscissa,ordinate);
        abscissa--;
        ordinate--;
        return temp;

        //move(-1);
        //return;
    }

    void getData()
    {
        cout<<"("<<abscissa<<","<<ordinate<<")"<<endl;
    }
    ~Coordinate()
    {

    }
    };

int main()
{
    Coordinate a(1,2);
    cout<<a.getDistance()<<endl;
    a++;
    a.getData();
    ++a;
    a.getData();

    Coordinate b(3,4);
    b--;
    b.getData();
    cout<<(a==b)<<endl;
    cout<<(a<b)<<endl;
    cout<<(a>b)<<endl;

}







