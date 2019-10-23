#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//NowCoder
#define ll long long
const ll mod=1000000007;
char a[100005][102];
/*
5
​Nowcoder
​nowcoder
​NowCoder
​NowoowCoder
​NOI2019NowCoder

QIE
QIE
QAK
QAK
QAK
*/
string pp="NowCoder";
int main()
{
    int n;
    scanf("%d",&n);
    int len=pp.length(),k=0;
   // string s;

    for(int i=0; i<n; i++)
    {
        scanf("%s",a[i]);
       // cin>>s;
       //if(s==pp)
        //{
        //    printf("QAK\n");
         //   continue;
        //}
        k=0;
        int flag=0;
        int len1=strlen(a[i]);
        //int len1=s.length();
        for(int j=0; j<len1; j++)
        {

           if(a[i][j]==pp[k])
            //if(s[j]==pp[k])
                k++;
            if(k==len)
            {
                flag=1;
                printf("QAK\n");
                break;
            }
        }
        if(!flag)
        {
            printf("QIE\n");
        }

    }
    return 0;
}
