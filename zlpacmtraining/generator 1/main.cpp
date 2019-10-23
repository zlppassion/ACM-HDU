#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll x0, x1, a, b, mod;
string ss;

struct Matrix
{
    ll t[2][2];
    Matrix()
    {
        memset(t, 0, sizeof(t));//初始化都为0
    }
} mat;

Matrix operator * (Matrix aa, Matrix bb)   //定义矩阵相乘
{
    Matrix cc = mat;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            ll ans = 0;
            for(int k = 0; k < 2; k++)
            {
                cc.t[i][j] = (cc.t[i][j] + aa.t[i][k]*bb.t[k][j]) % mod;
            }
        }
    }
    return cc;
}

Matrix QuickPow2(Matrix aa, int b)   //2进制快速幂
{
    Matrix cc = mat;
    cc.t[0][0] = cc.t[1][1] = 1;
    while(b)
    {
        if(b & 1)
        {
            cc = cc * aa;
        }
        aa = aa * aa;
        b >>= 1;
    }
    return cc;
}
Matrix QuickPow10(Matrix aa, string s)   //10进制快速幂
{
    Matrix cc = mat;
    cc.t[0][0] = cc.t[1][1] = 1;
    int len = s.size();
    for(int i = len-1; i >= 0; i--)
    {
        int num = s[i]-'0';
        cc = cc * QuickPow2(aa, num);
        aa = QuickPow2(aa, 10);

    }
    return cc;
}

int main()
{
    cin>>x0>>x1>>a>>b>>ss>>mod;
    Matrix ans, cnt;
    cnt.t[0][0] = a, cnt.t[0][1] = b;
    cnt.t[1][0] = 1, cnt.t[1][1] = 0;
    ans.t[0][0] = x1;
    ans.t[1][0] = x0;
    /*
    |a b|  *  |x1 0|  =  |a*x1+b*x0 0|  =  |x2 0|
    |1 0|     |x0 0|     |x1        0|     |x1 0|
    */
    cnt = QuickPow10(cnt, ss);
    ans = cnt * ans;
    cout<<ans.t[1][0]<<endl;
    return 0;
}
