#include<iostream>
#include<cmath>
using namespace std;

class shop_employee
{
protected:
    string ID;
    string name;
    double salary;
public:
    shop_employee()
    {

    }
    void set_ID(string id)
    {
        ID=id;
    }
    void set_name(string nm)
    {
        name=nm;
    }
    virtual void set_salary(double sal)
    {
        salary=sal;
    }
    virtual void get_info()=0;
};

class hourly_employee:public shop_employee
{
private:
 //   double hourly_rate;
    double hour;
    int period;
public:
    hourly_employee(string n="",string id=0,double Hour=8,int prd=14):hour(Hour),period(prd)
    {
        shop_employee::set_name(n);
        shop_employee::set_ID(id);

    }
    void set_salary(double sal)
    {
        int days=period-((period/7)*2);
        salary=sal*hour*days;
    }
    double get_salary()
    {
        return ceil(salary);
    }
    void get_info()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<ID<<endl;
        cout<<"Status: Hourly Employee"<<endl;
        cout<<"Salary in period "<<period<<" days is: "<<salary<<endl;
    }
};
class salary_employee:public shop_employee
{
private:

    double work_days;
    int period;
public:
    salary_employee(string n="",string id=0,double wday=260,int prd=14):work_days(wday),period(prd)
    {
        shop_employee::set_name(n);
        shop_employee::set_ID(id);
    }
    void set_salary(double sal)
    {
        double daily_salary=sal/work_days;
        int days=period-((period/7)*2);
        salary=daily_salary*days;

    }
    double get_salary()
    {
        return ceil(salary);
    }
    void get_info()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<ID<<endl;
        cout<<"Status: Salary Employee"<<endl;
        cout<<"Salary in period "<<period<<" days is: "<<salary<<endl;
    }
};

int main()
{
    shop_employee *s[5];
    s[1]=new hourly_employee("Timu","1894",8,14);
    s[2]=new salary_employee("Sumu","1930",260,14);

    s[1]->get_info();
    s[2]->get_info();

    s[1]->set_salary(9);
    s[2]->set_salary(60000);
    s[1]->get_info();
    s[2]->get_info();


}
