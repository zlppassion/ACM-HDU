#include <iostream>
#include<bits/stdc++.h>
using namespace std;
char a[100];
int main()
{
    cin>>a;
    int len=strlen(a);
    int pos=-1;
    for(int i=0;i<len;i++)
    {
        if(a[i]-'0'>=0&&a[i]-'0'<=9)
            continue;
        else
        {
            pos=i;
            break;
        }
    }
    if(pos==-1)
    {
        int flag=0;
        for(int i=len-1;i>=0;i--)
        {
            if(flag==1||a[i]-'0'>0)
            {
                cout<<a[i];
                flag=1;
            }
        }
    }
    else
    {
        int flag1=0,flag2=0;
        if(pos==1)
        {
            if(a[0]=='0')
                cout<<a[0];
        }
        else
        for(int i=pos-1;i>=0;i--)
        {
            if(flag1==1||a[i]-'0'>0)
            {
                cout<<a[i];
                flag1=1;
            }
        }
        cout<<a[pos];
        if(len-pos-1==1)
        {
            if(a[len-1]=='0')
                cout<<'0';
        }
        else
         for(int i=len-1;i>pos;i--)
        {
            if(flag2==1||a[i]-'0'>0)
            {
                cout<<a[i];
                flag2=1;
            }
        }

    }
    return 0;
}
