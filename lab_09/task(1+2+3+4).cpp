#include <iostream>
#include <string>
using namespace std;

enum class Material {Wood,Board,Steel,foam};
class Furniture
{
protected:
    double price;
    double discount;
    Material madeof;
    string ProdName;
public:

    Furniture()
    {
        //setPrice(p);
        //setDiscount(d);
        //setMadeof(m);
    }
    void setPrice(double val)
    {
        if(val>0)
            price=val;
    }
    void setDiscount(double val)
    {
        if(val<=price)
            discount=val;
    }
    void setDiscountPercentage(double v)
    {
        double final_d=getPrice()*(v/100);
        setDiscount(final_d);

    }
    double getPrice()
    {
        return price;
    }
    double getDiscountPrice()
    {
        return (price-discount);
    }
    void setMadeof(Material val)
    {
        madeof=val;
    }
    string getMadeof()
    {
        if(madeof==Material::Wood)
            return string("Wood");
        else if(madeof==Material::Board)
            return string("Board");
        else if(madeof==Material::Steel)
            return string("Steel");
        else
            return string("");
    }
    void setProductName(string s)
    {
        ProdName=s;
    }
    string getProductName()
    {
        return ProdName;
    }
    virtual void productDetails()=0;
};



enum class BedSize {Single,SemiDouble,Double};

class Bed:public Furniture
{
protected:
    BedSize BS;

public:
    Bed(double p,double dp,Material m,BedSize bs)
    {
        Furniture::setPrice(p);
        Furniture::setDiscount(dp);
        Furniture::setMadeof(m);
        setBedSize(bs);
    }
    void setBedSize(BedSize v)
    {
        BS=v;
    }
    string getBedSize()
    {
        if(BS==BedSize::Double)
            return string("Double");
        else if(BS==BedSize::SemiDouble)
            return string("SemiDouble");
        else if(BS==BedSize::Single)
            return string("Single");
        else
            return string("");

    }


    void productDetails()
    {
        cout<<"Regular Price: "<<getPrice()<<endl;
        cout<<"Discounted Price: "<<getDiscountPrice()<<endl;
        cout<<"Material: "<<getMadeof()<<endl;
        cout<<"Bed Size: "<<getBedSize()<<endl;
        cout<<"Product Name: "<<getProductName()<<endl;

    }
};
enum class SeatNumber {One,Two,Three,Four,Five};
class Sofa:public Furniture
{
protected:
    SeatNumber SN;

public:
    Sofa(double p,double dp,Material m,SeatNumber sn)
    {
        Furniture::setPrice(p);
        Furniture::setDiscount(dp);
        Furniture::setMadeof(m);
        setSeatNo(sn);
    }
    void setSeatNo(SeatNumber v)
    {
        SN=v;
    }
    string getSeatNo()
    {
        if(SN==SeatNumber::One)
            return string("One");
        else if(SN==SeatNumber::Two)
            return string("Two");
        else if(SN==SeatNumber::Three)
            return string("Three");
        else if(SN==SeatNumber::Four)
            return string("Four");
        else if(SN==SeatNumber::Five)
            return string("Five");

        else
            return string("");

    }


    void productDetails()
    {
        cout<<"Regular Price: "<<getPrice()<<endl;
        cout<<"Discounted Price: "<<getDiscountPrice()<<endl;
        cout<<"Material: "<<getMadeof()<<endl;
        cout<<"Seat Number: "<<getSeatNo()<<endl;
        cout<<"Product Name: "<<getProductName()<<endl;
    }
};
enum class door {Two,Three,Four};
class Almirah:public Furniture
{
protected:
    door DN;
    string ProdName;
public:
    Almirah(double p,double dp,Material m,door dn)
    {
        Furniture::setPrice(p);
        Furniture::setDiscount(dp);
        Furniture::setMadeof(m);
        setDoor(dn);
    }
    void setDoor(door v)
    {
        DN=v;
    }
    string getDoor()
    {
        if(DN==door::Two)
            return string("Two");
        else if(DN==door::Three)
            return string("Three");
        else if(DN==door::Four)
            return string("Four");

        else
            return string("");

    }


    void productDetails()
    {
        cout<<"Regular Price: "<<getPrice()<<endl;
        cout<<"Discounted Price: "<<getDiscountPrice()<<endl;
        cout<<"Material: "<<getMadeof()<<endl;
        cout<<"Door Number: "<<getDoor()<<endl;
        cout<<"Product Name: "<<getProductName()<<endl;

    }
};

/**task 4
sort_furniture_discount will sort the array in descending order based on their discount price.
You may need to add some member functions
**/
void sort_order(Furniture **f1,Furniture **f2)
{
    if ((*f1)->getDiscountPrice() < (*f2)->getDiscountPrice())
    {
        Furniture* temp = *f1;
        *f1 = *f2;
        *f2 = temp;
    }
}
    void sort_furniture_discount(Furniture **f,int no_of_furnitures)
    {
        for (int i = 0; i < no_of_furnitures - 1; ++i)
        {
            for (int j = i + 1; j < no_of_furnitures; ++j)
            {
                sort_order(f + i, f + j);
            }
        }

    }




    int main()
    {
        Furniture* f_list[100];

        /**
            task 1
        */
        f_list[0] = new Bed(10000,123,Material::Wood,BedSize::Single);
        f_list[1] = new Sofa(11000,234,Material::Steel,SeatNumber::Five);
        f_list[2] = new Almirah(13000,345,Material::Wood,door::Two);
        f_list[3] = new Bed(10090,123,Material::Wood,BedSize::Single);

        /**task 1 ends here*/

        /**
            task 2

            task 3 (Modify productDetails)
        */
        f_list[0]->setProductName("Bahari");
        f_list[1]->setProductName("Abc");
        f_list[2]->setProductName("Bcd");
        f_list[3]->setProductName("Cde");

         f_list[2]->setDiscountPercentage(30);
        for(int i=0; i<4; i++)
        {
            f_list[i]->productDetails();
            cout<<endl;
        }

        /**task 2 ends here*/
        /**task 3 ends here*/

        /**task 4
        */
        sort_furniture_discount(f_list,4);
        for(int i=0; i<4; i++)
        {
            f_list[i]->productDetails();
        }
        /**task 4 ends here*/

    }
