#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[5];
    set<int>s;
    for(int i=0;i<10;i++)
    {
        if(i%2==1)
            s.insert(i);
        else
            a[i/2]=i;

    }
    vector<int>v(10);

    merge(a,a+5,s.begin(),s.end(),v.begin());
     for (auto i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    return 0;
}
