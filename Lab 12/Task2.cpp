#include <iostream>
#include<bits/stdc++.h>
using namespace std;


 template<class S>
 S amax(S *a,int size,int n)
 {
    sort(a,a+size,greater<int>());
    return a[n-1];
 }
 int main()
 {
     int arr[]={1,2,3,4,5};
     cout<<amax(arr,5,3)<<endl;

     double darr[]={1.2,1.5,2.5,4.5};
     cout<<amax(darr,4,2)<<endl;

     char carr[]={'a','b','c'};
     cout<<amax(carr,3,2);
 }
