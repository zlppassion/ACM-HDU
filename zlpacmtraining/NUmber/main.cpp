#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string p;
    cin>>n>>p;
    int len=p.length();
    if(len>n)
    {
        cout<<"T_T"<<endl;
    }
    else
    {
        //n-len即代表多了几位数
        for(int i=1;i<=n-len;i++)
        {
            p+='0';
        }
        cout<<p<<endl;



    }
    return 0;
}
