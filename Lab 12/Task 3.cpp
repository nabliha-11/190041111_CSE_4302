#include<bits/stdc++.h>
using namespace std;
const int size=5;

template <class T>
class Stack
{
private:
    int top;
    T s[size];
public:
    class FULL{};
    class EMPTY{};
    Stack()
    {
        top=-1;
    }
    void push(T n)
    {
        if(isfull())
        {
         //throw FULL();
         throw 1;
        }
        top++;
        s[top]=n;
    }
    T pop()
    {
        if(isempty())
        {
            throw EMPTY();
        }

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
    try{
    I.push(1);
    I.push(2);
    I.push(3);
    I.push(4);
    I.push(5);
    I.push(6);
    }
   /* catch(Stack<int>::FULL f)
    {
        cout<<"Stack overflow"<<endl;
    }*/
    catch(int e)
    {
        cout<<"Stack overflow"<<endl;
    }


    try{
    cout<<I.pop()<<endl;
    }
    catch(Stack<int>::EMPTY e)
    {
        cout<<"Stack underflow"<<endl;
    }
    cout<<I.peek()<<endl;

}
