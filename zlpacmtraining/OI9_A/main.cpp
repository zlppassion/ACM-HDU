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
//vector<char> q;
//map<char,int> vis;
int main()
{
    int n;
    scanf("%d ",&n);
   // getchar();
    for(int i=0;i<n;i++)
    {
        scanf("%s",a[i]);
        //cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        int flag=0,ans=0;
        int len=strlen(a[i]);

        for(int j=0;j<len;j++)
        {
            //cout<<a[i][j]<<" "<<ans<<endl;


            if(a[i][j]=='N'&&!ans)
            {
                ans++;

            }
            else if(a[i][j]=='o'&&ans==1)
            {
                ans++;
            }
            else if(a[i][j]=='w'&&ans==2)
            {
                ans++;

            }
            else if(a[i][j]=='C'&&ans==3)
            {
                ans++;

            }
            else if(a[i][j]=='o'&&ans==4)
            {
               ans++;

            }
            else if(a[i][j]=='d'&&ans==5)
            {
               ans++;

            }
            else if(a[i][j]=='e'&&ans==6)
            {
                ans++;

            }
            else if(a[i][j]=='r'&&ans==7)
            {
                ans++;
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
