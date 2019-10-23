#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
char num[1005];
stack<ll> s;
int main()
{
    char c;
    int pos=0;
    ll ans=0;
    ll now=0;
    while(cin>>c&&c!='@')
    {
        if((c>='0'&&c<='9'))
        {
            now*=10;
            now+=(c-'0');
            //num[pos++]=c;
        }
        else if (c=='.')
        {



            s.push(now);
            now=0;


        }
        else
        {
            if(!s.empty())
            {
                ll t2=s.top();
                s.pop();
                ll t1=s.top();
                s.pop();
                if(c=='+')
                {
                    ans=t1+t2;
                }
                else if(c=='-')
                {
                    ans=t1-t2;
                }
                else if(c=='*')
                {
                    ans=t1*t2;
                }
                else
                {
                    ans=t1*1.0/t2;
                }
                s.push(ans);
            }


        }

    }
    cout<<ans<<endl;
    return 0;
}
