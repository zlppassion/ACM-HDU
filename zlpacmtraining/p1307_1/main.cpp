#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        reverse(s.begin(),s.end());
        int len=s.length();
        if(s[len-1]=='-')
        {
            cout<<s[len-1];
            if(len==2)
            {
                cout<<s[0]<<endl;

            }
            else
            {
                 int tot=0;
            for(int i=0; i<len-1; i++)
            {
                if(s[i]=='0'&&i==tot)
                {
                    tot++;
                }
                else
                {
                    s=s.substr(i,len-i-1);
                    break;
                }

            }
            cout<<s<<endl;
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
            cout<<s<<endl;
        }

    }
    //cin>>s;


    return 0;
}
