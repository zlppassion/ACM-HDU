/*Sample Input
3
BAPC
BAPC
AZA
AZAZAZA
VERDI
AVERDXIVYERDIAN
Sample Output
1
3
0*/
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

char str1[10010],str[1000100];
int next1[10010];
int deal(int len)
{
    next1[0]=-1;
    int j=0;
    int k=-1;
    while(j<len-1)
    {
        if(k==-1||str1[k]==str1[j])
        {
            ++j;
            ++k;
            next1[j]=k;
        }
        else k=next1[k];
    }
    return 0;
}
int main()
{
    int T,i,j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s%s",str1,str);
        int len1=strlen(str1);
        int len2=strlen(str);
        deal(len1);
        i=j=0;
        int k=0;
        while(i<len2)
        {

            if(j==-1||str[i]==str1[j])
            {
                i++;
                j++;
            }
            else j=next1[j];
            if(j==len1)
            {
                k++;
                i--;j--;
                j=next1[j];

            }
        }
        printf("%d\n",k);
    }
    return 0;
}
