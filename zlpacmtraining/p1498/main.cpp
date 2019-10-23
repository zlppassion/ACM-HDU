#include<iostream>
using namespace std;
const int maxn=3005;
char a[maxn][maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    for(int i=0; i<maxn; i++)
        for(int j=0; j<maxn; j++)
            a[i][j]=' '; //先全部置为空格,否则空串错误还麻烦要if输出空格

    //1.存基础图形(n=1倒着的)
    a[0][0]='/';
    a[0][1]='_';
    a[0][2]='_';
    a[0][3]='\\';
    a[1][1]='/';
    a[1][2]='\\';

    //2.复制右边和上边
    int len=4,k=1;//len表示当前图腾的宽,len/2是图腾的高;能观察但到基础的规律:宽和高多么重要!
    while(k<n)//不断复制
    {
        for(int i=0; i<len/2; i++)
        {

            for(int j=0; j<len; j++)
            {
                a[i][j+len]=a[i][j];//右边只加宽
                a[i+len/2][j+len/2]=a[i][j];//上边加高加宽
            }
        }

        len*=2;
        k++;
    }
    //3.输出
    for(int i=(len/2)-1; i>=0; i--) //倒序输出
    {
        for(int j=0; j<len; j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }

    return;
}
