#include <iostream>
#include<bits/stdc++.h>
using namespace std;
map<char,char> qq;
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1; i<=T; i++)
    {
        double numd=0.0,numw=0.0,numh=0.0;
        string s;
        cin>>s;
        string a;
        cin>>a;
        for(int j=0; j<26; j++)
        {
            if(a[j]=='d')
            {
               qq[char('a'+j)]='d';
            }
            else if(a[j]=='w')
            {
               qq[char('a'+j)]='w';
            }
            else
            {
               qq[char('a'+j)]='h';
            }
        }
        int len=s.length();
        for(int j=0;j<len;j++)
        {
            if(qq[s[j]]=='d')
                numd++;
            else if(qq[s[j]]=='w')
                numw++;
            else
                numh++;
        }
        //cout<<"numd :"<<numd<<endl;
       // cout<<"numw :"<<numw<<endl;
       //cout<<"numh :"<<numh<<endl;

        cout<<"Case #"<<i<<": ";
        if(numh>=0.25*len)
            cout<<"Harmful"<<endl;
        else if(numh<=0.1*len)
            cout<<"Recyclable"<<endl;
        else if(numd>=numw*2.0)
            cout<<"Dry"<<endl;
        else
            cout<<"Wet"<<endl;
    }
    return 0;
}
