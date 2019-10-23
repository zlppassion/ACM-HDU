#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int a1[maxn],a2[maxn];
stack<int> st1,st2;
void init()
{
    while(!st1.empty())
        st1.pop();
    while(!st2.empty())
        st2.pop();
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        init();
        for(int i=0;i<=n;i++)
        {
            a1[i]=0;
            a2[i]=0;
        }
        for(int i=0;i<n;i++)
            scanf("%d",&a1[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&a2[i]);
        int ans=n;
        for(int i=0;i<n;i++)
        {
            while(!st1.empty()&&a1[st1.top()]>a1[i])
                st1.pop();
            while(!st2.empty()&&a2[st2.top()]>a2[i])
                st2.pop();
            st1.push(i);
            st2.push(i);
            if(st1.size()!=st2.size())
            {
                ans=i;
                break;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
