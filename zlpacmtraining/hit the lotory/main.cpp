#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n;

int main()
{
    scanf("%d",&n);
    int t100=n/100;
    n-=(t100*100);
    //int t50=n/50;
   // n-=(t50*50);
    int t20=n/20;
    n-=(t20*20);
    int t10=n/10;
    n-=t10*10;
    int t5=n/5;
    n-=t5*5;
    int t1=n;
    cout<<t1+t5+t10+t20+t100<<endl;
    return 0;
}
