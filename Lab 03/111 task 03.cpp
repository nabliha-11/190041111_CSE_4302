#include<bits/stdc++.h>
using namespace std;
class Product
{
private:

    char name[30];
    double discountPercent=0.5;
    double unitPrice=10;
public:
    void assignName(char name[])
    {
    strcpy(Product::name,name);
    //puts(Product::name);
    }
    void setPrice(double price)
    {
        if(price<0)
        {
            cout<<"Invalid Price "<<endl;
            return;
        }
        unitPrice=price;
    }
    void setDiscPercent(double percent)
    {
        if(percent<0 || percent>10)
        {
            cout<<"Invalid Percentage"<<endl;
            return;
        }
        discountPercent=percent;
    }
    double getSellingPrice(int nos)
    {
        double sellingprice;
        sellingprice=unitPrice-(unitPrice*(discountPercent/100));
        //cout<<sellingprice<<endl;
        return (nos*sellingprice);

    }
    void display()
    {
       cout<<name<<" has a unit price BDT "<<unitPrice<<". Current discount "<<discountPercent<<"%"<<endl;
    }
};
int main()
{
    Product prd;
    char n[30];
    double per,unitp;
    int no;
    cout<<"Enter product name: ";
    cin>>n;
    prd.assignName(n);
    cout<<"Enter discount percentage and Per unit price :";
    cin>>per>>unitp;
    prd.setPrice(unitp);
    prd.setDiscPercent(per);
    prd.display();
    cout<<"Enter nos of products: ";
    cin>>no;
    cout<<prd.getSellingPrice(no)<<endl;

}
