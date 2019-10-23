/*HDU2087
花纹条和小饰条不会超过1000个字符长。如果遇见#字符，则不再进行工作。
Sample Input
abcde a3
aaaaaa  aa
#
Sample Output
0
3*/
#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=1005;
int next1[maxn];
char text1[maxn],pattern[maxn];
void getnext(char s[])
{
    next1[0]=-1;
    int j=0,k=-1;
    int len=strlen(s);
    while(j<len-1)
    {
        if(k==-1||s[j]==s[k])
            next1[++j]=++k;
        else
            k=next1[k];
    }
}
int main()
{
    while(scanf("%s",text1)&&text1[0]!='#')
    {
        scanf("%s",pattern);
        getnext(pattern);
        int len1=strlen(pattern),len2=strlen(text1);
        int i=0,j=0;
        int k=0;
        while(i<len2)
        {
            if(j==-1||text1[i]==pattern[j])
            {
                i++;
                j++;
            }
            else
                j=next1[j];
            if(j==len1)
            {
                k++;
                j=0;
            }
        }
        cout<<k<<endl;

    }
    return 0;
}
