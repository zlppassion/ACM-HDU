/*Sample Input
2
13 5
1 2 1 2 3 1 2 3 1 3 2 1 2
1 2 3 1 3
13 5
1 2 1 2 3 1 2 3 1 3 2 1 2
1 2 3 2 1
Sample Output
6
-1*/
//All integers are in the range of [-1000000, 1000000].
#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1000005;
int next1[maxn];
int text[maxn],pattern[maxn];
int ans;
void getnext(int s[],int len)
{
    int j=-1;
    next1[0]=-1;
    for(int i=1;i<len;i++)
    {

        while(j!=-1&&s[i]!=s[j+1])
            j=next1[j];//����ִ�д�ѭ����֪��j���˵�-1������s[i]==s[j+1]
        if(s[i]==s[j+1])
            j++;
        next1[i]=j;
    }
}
//kmp�㷨���ж�pattern�Ƿ���text���Ӵ�
bool kmp(int text1[],int pattern1[],int n,int m)
{
   // int n=strlen(text),m=strlen(pattern);
    getnext(pattern1,m);//����pattern��next����
    int j=-1;//��ʼ��Ϊ-1����ʾ��ǰ��û��һλ��ƥ��

    for(int i=0;i<n;i++)
    {
        while(j!=-1&&text1[i]!=pattern1[j+1])
        {
            j=next1[j];
        }

        if(text1[i]==pattern1[j+1])//����һ��ִ�и�ѭ�������������ģ�������ܲ�ƥ��
        {
            ans=i;
            j++;
        }


        if(j==m-1)
            return true;


    }
    return false;
}
int main()
{
    int T;
    scanf("%d",&T);
    int m,n;

    while(T--)
    {

       scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",&text[i]);
        for(int i=0;i<m;i++)
           scanf("%d",&pattern[i]);
        if(kmp(text,pattern,n,m))
            cout<<ans-m+2<<endl;

        else
             cout<<"-1"<<endl;
        ans=0;

    }

    return 0;
}
