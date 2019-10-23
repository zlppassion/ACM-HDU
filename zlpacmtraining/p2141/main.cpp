#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int a[105];
set<int> q;//题目中说了集合中的数各不相同
set<int>mp;
int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        q.insert(a[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {

            int temp=a[i]+a[j];
            set<int>::iterator it=q.find(temp);
            if(it!=q.end())
            {
               mp.insert(temp);
            }


        }
    }
    int tt=mp.size();
    cout<<tt<<endl;
    return 0;
}
