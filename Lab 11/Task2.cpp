#include<fstream>
#include<iostream>
#include<typeinfo>
using namespace std;
#include<process.h>

const int LEN=20;

enum picture_type{tphotograph,tpainting};

class picture
{
private:
    char title[LEN];
    int price;
    unsigned long number;
    static int n; //current no of pictures;
    static picture* arrap[]; //array of ptrs to pics;
public:
    virtual void getdata()
    {
        cin.ignore(10,'\n');
        cout<<"Enter Title: ";cin>>title;
        cout<<"Enter Price: ";cin>>price;
        cout<<"Enter number: ";cin>>number;

    }
    virtual void putdata()
    {
        cout<<"\n Title: "<<title;
        cout<<"\n Price: "<<price;
        cout<<"\n Number: "<<number;
    }
    virtual picture_type get_type();
    static void add();
    static void display();
    static void read();
    static void write();
};
int picture::n;
picture* picture::arrap[50];

class photograph:public picture
{
private:
    char photographer[LEN];
    char camera[15];
    double speed;
    double aperture;
public:
    void getdata()
    {
        picture::getdata();
        cout<<"Enter name of photographer: ";cin>>photographer;
        cout<<"Enter Camera Model and Brand: ";cin>>camera;
        cout<<"Enter speed: ";cin>>speed;
        cout<<"Enter aperture: ";cin>>aperture;
    }
    void putdata()
    {
        picture::putdata();
        cout<<"\nPhotographer: "<<photographer;
        cout<<"\nCamera: "<<camera;
        cout<<"\nSpeed: "<<speed;
        cout<<"\nAperture: "<<aperture;
    }
};
class painting:public picture
{
private:
    char artist[LEN];
    char medium[10];
public:
    void getdata()
    {
        picture::getdata();
        cout<<"Name of Artist: ";cin>>artist;
        cout<<"Medium of painting: ";cin>>medium;

    }
    void putdata()
    {
        picture::putdata();
        cout<<"\nArtist: "<<artist;
        cout<<"\nMedium: "<<medium;
    }
};

void picture::add()
{
    char ch;
    cout<<"'1' to add photo\n'2' to add painting";
    cout<<"\nEnter choice:";
    cin>>ch;
    switch(ch)
    {
        case'1':arrap[n]=new photograph;
        break;
        case'2':arrap[n]=new painting;
        break;
        default:
            cout<<"Unknown\n";
            return;

    }
    arrap[n++]->getdata();
}
void picture::display()
{
    for(int j=0;j<n;j++)
    {
        cout<<(j+1);
        switch(arrap[j]->get_type())
        {
            case tphotograph:cout<<" Type:Photograph";break;
            case tpainting:cout<<" Type : Painting";break;
            default:
                cout<<"Unknown";
        }
        arrap[j]->putdata();
        cout<<endl;

    }
}

picture_type picture::get_type()
{
    if(typeid(*this)==typeid(photograph))
        return tphotograph;
    else if(typeid(*this)==typeid(painting))
        return tpainting;
    else
    {
        cerr<<"\nBad Pic type";exit(1);
        return tphotograph;
    }
}

    void picture::write()
    {
        int sz;
        cout<<"Writing "<<n<<" pictures.\n";
        ofstream of;
        picture_type pt;
        of.open("Picture.DAT",ios::trunc|ios::binary);
        if(!of)
        {
            cout<<"\nCan't open\n";
            return;
        }
        for(int j=0;j<n;j++)
        {
            pt=arrap[j]->get_type();
            of.write((char*)&pt,sizeof(pt));
            switch(pt)
            {
                case tphotograph: sz=sizeof(photograph);
                break;
                case tpainting:sz=sizeof(painting);
                break;
            }
            of.write((char*)(arrap[j]),sz);
            if(!of)
            {
                cout<<"\nCan't write\n";
                return;
            }
        }
    }

    void picture::read()
    {
        int sz;
        picture_type pt;
        ifstream in;
        in.open("Picture.DAT",ios::binary);
        if(!in)
        {
            cout<<"\nCan't open\n";
            return;
        }
        n=0;
        while(true)
        {
            in.read((char*)&pt,sizeof(pt));
            if(in.eof())
                break;
            if(!in)
            {
                cout<<"\nCan't read\n";
                return;
            }
            switch(pt)
            {
                case tphotograph:
                arrap[n]=new photograph;
                sz=sizeof(photograph);
                break;
                case tpainting:
                    arrap[n]=new painting;
                    sz=sizeof(painting);
                    break;
                default:
                    cout<<"\nUnknown\n";
                    return;


            }
            in.read((char*)arrap[n],sz);
            if(!in)
            {
                cout<<"\nCan't read\n";
                return;
            }
            n++;
        }
        cout<<"\nReading "<<n<<" pictures\n";

    }

    int main()
    {
        char ch;
        while(true)
        {
            cout << "'a'--add data for a picture"
    "\n' d'--display data for all pictures"
    "\n' w'--write all picture data to file"
    "\n' r'--read all picture data from file"
    "\n' x'--exit"
    "\nEnter selection: ";
    cin >> ch;
    switch (ch) {
    case 'a':
      picture::add();
      break;
    case 'd':
      picture::display();
      break;
    case 'w':
      picture::write();
      break;
    case 'r':
      picture::read();
      break;
    case 'x':
      exit(0); //exit program
    default:
      cout << "\nUnknown command";

        }
    }
}
