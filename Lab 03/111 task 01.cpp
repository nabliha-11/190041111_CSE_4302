#include<bits/stdc++.h>
using namespace std;
class Counter
{
private:
    int count=0;
    int increment_step;
public:
    void setIncrementStep(int step_val)
    {
        increment_step=step_val;
    }
    int getCount()
    {
        return count;
    }
    void increment()
    {
        count+=increment_step;
    }
    void resetCount()
    {
        count=0;
    }
};
int main()
{
    Counter c;
    int v;
    cout<<"Before increment : "<<c.getCount()<<endl;
    cout<<"Input value of Increment step: ";
    cin>>v;
    c.setIncrementStep(v);
    c.increment();
    cout<<"After increment : "<<c.getCount()<<endl;
    return 0;


}

