#include<bits/stdc++.h>
using namespace std;
const int size=10;

template <class T>
class Stack
{
private:
    int top;
    T s[size];
public:
    Stack()
    {
        top=-1;
    }
    void push(T n)
    {
        if(isfull())
        {
            cout<<"Stack Overflow"<<endl;
        }
        top++;
        s[top]=n;
    }
    T pop()
    {
       T temp=s[top];
       top--;
       return temp;
    }
    T peek()
    {
        return s[top];
    }
    bool isempty()
    {
        if(top==-1)
            return true;
        return false;
    }
    bool isfull()
    {
        if(top==(size-1))
            return true;
        return false;
    }
};

int main()
{
    Stack<int>I;
    I.push(1);
    I.push(2);
    I.push(3);
    I.push(4);
    I.push(5);

    cout<<I.pop()<<endl;
    cout<<I.peek()<<endl;

    Stack<double>D;
    D.push(1.5);
    D.push(2.5);
    D.push(4.5);
    D.push(5.57);

    cout<<D.pop()<<endl;
    cout<<D.peek();



}
