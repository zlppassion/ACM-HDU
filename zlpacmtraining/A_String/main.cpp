/*举个栗子：对于01101111这个串，按题目要求拆开所得的串
就只有01101111，而按我自己的理解，就会拆成011和01111；
这是两个的不同之处。
所以就只能按最大长度的最小表示法的方法做，上代码：*/
#include <bits/stdc++.h>
using namespace std;
const int maxn=2001;
int t;
string str;
bool judge(string s)
{
    int i=0,j=1,k=0,ll=s.length();
    while (i<ll && j<ll && k<ll)
    {
        int com=s[(i+k)%ll]-s[(j+k)%ll];
        if(com==0)//两位相等的情况
            k++;
        else
        {
            if(com>0)//起点为i的轮回字符串比较大的时候
                i+=(k+1);
            else
                j+=(k+1);//起点为j的轮回字符串比较大的时候
            if(i==j)
                j++;//避免相等的情况
            k=0;
        }
    }
    if(min(i,j)==0)
        return 1;
    else
        return 0;
}//检测是否为最小表示
int main()
{
    scanf("%d",&t);
    while (t--)
    {
        cin>>str;
        int len=str.length();
        int l=0;
        while(1)
        {
            for(int i=len; i>=0; i--) //枚举的i-l的长度，从大的开始枚举，因为要拆成最少部分,(i-l)即代表剩下的长度
            {
                string s=str.substr(l,i-l);//取子串的方式，前面时初始位置，后面时所取长度
                if(judge(s))
                {
                    cout<<s;
                    l=i;
                    break;
                }
            }
            if(l!=len)
                cout<<' ';
            else
                break;
        }
        cout<<endl;
    }
    return 0;
}
