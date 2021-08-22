#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Building;
class Lab
{
private:
    string labname;
    int capacity;
public:

    Lab(string ln,int c):labname(ln),capacity(c)
    {

    }
    Lab()
    {

    }
     static vector<Lab*> labs;
    void setLabName(string lab)
    {
     labname=lab;
    }
    void setCapacity(int cap)
    {
        capacity=cap;
    }
    string getLabname()
    {
        return labname;
    }
    int getCapacity()
    {
        return capacity;
    }

};
class Lecturer_Room
{
private:
    string roomName;
    int roomNo,capacity;

public:
    Lecturer_Room(string rname,int rn,int cap):roomName(rname),roomNo(rn),capacity(cap)
    {

    }
    Lecturer_Room()
    {

    }
    static vector<Lecturer_Room*> lrooms;
    void setRoomName(string name)
    {
        roomName=name;
    }
    void setRoomNo(int no)
    {
        roomNo=no;
    }
    void setCapacity(int c)
    {
        capacity=c;
    }
    string getRoomName()
    {
        return roomName;
    }
    int getRoomNo()
    {
        return roomNo;
    }
    int getCapacity()
    {
        return capacity;
    }

};
class Building
{
private:
    Lab L;
    Lecturer_Room LR;

public:
    Building()
    {

    }



    void showallLabs()
    {
        vector<Lab*>::iterator i=L.labs.begin();
        cout<<"Showing all Labs: "<<endl;
        while(i!=L.labs.end())
        {
        cout<<"Lab "<<(*i)->getLabname()<<" "<<(*i)->getCapacity()<<" Capacity"<<endl;
        ++i;
        }
        cout<<endl;
    }

    void showAllLectureRooms()
    {
        cout<<"Showing all Lecturer_Rooms: "<<endl;
        vector<Lecturer_Room*>::iterator i=LR.lrooms.begin();
        while(i!=LR.lrooms.end())
        {
      cout<<(*i)->getRoomName()<<" "<<(*i)->getRoomNo()<<" "<<(*i)->getCapacity()<<" Capacity"<<endl;
        ++i;
        }
        cout<<endl;
    }

};
vector<Lab*> Lab::labs;
vector<Lecturer_Room*> Lecturer_Room::lrooms;
int main()
{
  Lab::labs.push_back(new Lab("M28",50));
  Lab::labs.push_back(new Lab("M27",52));
  Lab::labs.push_back(new Lab("M29",53));
  Lecturer_Room::lrooms.push_back(new Lecturer_Room("abc",201,4));
  Lecturer_Room::lrooms.push_back(new Lecturer_Room("bce",202,3));
  Lecturer_Room::lrooms.push_back(new Lecturer_Room("dca",203,5));
  Building x;
  x.showallLabs();
  x.showAllLectureRooms();


}
