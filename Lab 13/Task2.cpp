#include<bits/stdc++.h>
using namespace std;

namespace sample1
{
    int var=1;
}
namespace sample2
{
    int var=44;
}
int main()
{
    cout<<sample1::var<<endl;
    cout<<sample2::var;
}
