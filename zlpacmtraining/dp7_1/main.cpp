/*7-1 jmu-ds-������Ӵ� ��8 �֣�
����2���ַ��������2�ַ�����������Ӵ���

�����ʽ:

����2���ַ��������ɰ����ո�

�����ʽ:

���2���ַ�����������Ӵ�����û�й����Ӵ����������NULL��

��������1:

abcding
sbcdiofng
�������1:

bcdi
��������2:

understanding
fw
�������2:

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
       strncpy(C,&A[end_pos-length+1],length);//��A��ָ����ַ�������A��ַ��ʼ��ǰlength���ֽڸ��Ƶ�C��ָ�������У������ر����ƺ��dest��

       cout<<C<<endl;
   }
    return 0;
}
