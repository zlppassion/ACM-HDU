#include <iostream>
#include<bits/stdc++.h>
using namespace std;
char c;
char s1[62505],s2[62505];
int main()
{
    int tot=1;
    while(scanf("%c",&c)!=EOF&&c!='E')
    {
        s1[tot]=c;
        s2[tot]=c;
        tot++;
    }
    int a1=(tot-1)/11,a2=(tot-1)/21;
    int t1=0,t2=0;
    for(int i=1; i<=a1; i++)
    {
        t1=(i-1)*11+1;
        int aa=0,bb=0;
        for(int j=t1; j<t1+11; j++)
        {
            if(s1[i]=='W')
                aa++;
            else
                bb++;
        }
        cout<<aa<<":"<<bb<<endl;

    }
    if(t1!=0)
    {
        t1=tot-1-(t1+11);
    int cc=0,dd=0;
    for(int i=t1;i<tot;i++)
    {
        if(s1[i]=='W')
                cc++;
            else
                dd++;
    }
    if(cc||dd)
    cout<<cc<<":"<<dd<<endl;
    cout<<endl;

    }
    else
    {

    int cc=0,dd=0;
    for(int i=t1;i<tot;i++)
    {
        if(s1[i]=='W')
                cc++;
            else
                dd++;
    }
    if(cc||dd)
    cout<<cc<<":"<<dd<<endl;
    cout<<endl;

    }

    for(int i=1; i<=a2; i++)
    {
        t2=(i-1)*21+1;
        int aa=0,bb=0;
        for(int j=t2; j<t2+21; j++)
        {
            if(s2[i]=='W')
                aa++;
            else
                bb++;
        }
        cout<<aa<<":"<<bb<<endl;

    }
    if(t2!=0)
    {
         t2=tot-1-(t2+21);//代表剩的个数
    int hh=0,tt=0;

    for(int i=t2;i<tot;i++)
    {
        if(s1[i]=='W')
                hh++;
            else
                tt++;
    }
    if(hh||tt)
    cout<<hh<<":"<<tt<<endl;
    }
   else
   {
       int hh=0,tt=0;

    for(int i=0;i<tot;i++)
    {
        if(s1[i]=='W')
                hh++;
            else
                tt++;
    }
    if(hh||tt)
    cout<<hh<<":"<<tt<<endl;
   }
    cout<<endl;
    return 0;
}
