/*7-1 jmu-ds-最长公共子串 （8 分）
给出2个字符串，输出2字符串的最长公共子串。

输入格式:

输入2个字符串，不可包含空格。

输出格式:

输出2个字符串的最长公共子串。若没有公共子串，则输出“NULL”

输入样例1:

abcding
sbcdiofng
输出样例1:

bcdi
输入样例2:

understanding
fw
输出样例2:

NULL*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int dp[maxn][maxn];
int main()
{
    char A[maxn],B[maxn],C[maxn];
    cin>>A;
    cin>>B;
    if(strcmp(A,B)==0)
    {
        cout<<A<<endl;
        return 0;
    }
    int lena=strlen(A),lenb=strlen(B);
    int length=0,end_pos=0;
    if(A[0]==B[0])
    dp[0][0]=1;
    else
        dp[0][0]=0;
     memset(C,'\0',sizeof(C));
    for(int i=1;i<lena;i++)
    {

        for(int j=1;j<lenb;j++)
        {
            if(A[i]==B[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=0;
            if(dp[i][j]>length)
            {
                length=dp[i][j];
                end_pos=i;
            }
        }
    }
    if(length==0)
    {
        cout<<"NULL"<<endl;
    }
   else
   {
       strncpy(C,&A[end_pos-length+1],length);//把A所指向的字符串中以A地址开始的前length个字节复制到C所指的数组中，并返回被复制后的dest。

       cout<<C<<endl;
   }
    return 0;
}
