/*Input
The first line of the input is a single integer T ( 0 < T <= 100 ) which means the number of test cases.
Each test case contains only one line describe the original ordinary chain to be remade.
Each character in the string stands for one pearl and there are 26 kinds of pearls being described by 'a' ~'z' characters.
he length of the string Len: ( 3 <= Len <= 100000 ).
Output
For each case, you are required to output the minimum count of pearls added to make a CharmBracelet.
Sample Input
3
aaa
abca
abcde
Sample Output
0
2
5*/

#include <iostream>
#include<cstring>
#include<cstdio>
#include<map>
using namespace std;
const int maxn=100005;
char s1[maxn];
int next1[maxn];
void getnext(char s[])
{
    int len=strlen(s);
    int j=0,k=-1;
    next1[0]=-1;
    while(j<len)
    {
        if(k==-1||s[j]==s[k])
            next1[++j]=++k;
        else
            k=next1[k];
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%s",s1);
        int len=strlen(s1) ;
        getnext(s1);
        int ans=1;
        if(len%(len-next1[len])==0&&len/(len-next1[len])!=1)
        {
            cout<<"0"<<endl;
        }
        else
        {
            int length1=len-next1[len];//循环节长度
        ans=length1-next1[len]%length1;
        cout<<ans<<endl;
        }


       // if(ans==0)
        /*for(int i=0;i<=len;i++)
        {
            if(next1[i]==0)
                k++;
        }
        if(k==len)
            cout<<k<<endl;
        else if(next1[len]!=0)
        cout<<len-next1[len]-1<<endl;
        else
            cout<<len-next1[len]<<endl;*/
            //cout<<len/(len-next1[len])<<endl;


    }

    return 0;
}
