#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    int len=s.length();
    if(s[0]=='-')
    {
        int tot=1;
        for(int i=1; i<len; i++)
        {
            if(s[i]=='0'&&i==tot)
            {
                tot++;
            }
            else
            {
                s=s.substr(i,len-i);
                break;
            }

        }

    }
    else
    {
         int tot=0;
        for(int i=0; i<len; i++)
        {
            if(s[i]=='0'&&i==tot)
            {
                tot++;
            }
            else
            {
                s=s.substr(i,len-i);
                break;
            }

        }
    }
    cout<<s<<endl;

    return 0;
}
