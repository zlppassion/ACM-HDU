#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int a[10], r[10];
char s[N];
int main ()
{
    int Case;
    scanf("%d", &Case);
    for(int cas = 1; cas <= Case; cas++)
    {
        scanf("%s", s + 1);
        for(int i = 1; i <= 8; i++)//二进制转十进制，每一位乘2的j次方
        {
            a[i] = 0;
          //  for(int j = 1; j <= 16; j++)
           //     a[i] = a[i] * 2 + s[(i - 1) * 16 + j] - '0';

            for(int j=16;j>=1;j--)
            {
               if(s[(i-1)*16+j]-'0'==0)
                continue;
               else
               a[i]+=1<<(16-j);
            }

        }
       // for(int i=1;i<=8;i++)
          //  cout<<a[i]<<endl;

        printf("Case #%d: ", cas);
        memset(r, 0, sizeof(r));
        int id = 0;
        for(int i = 8; i >= 1; i--)
        {
            if (a[i] == 0) r[i] = r[i+1] + 1;//代表连续的有几个0
            if (r[id] < r[i]) id = i;//肯定是考虑转换长度最大的那个
            if (r[id] == r[i] && r[id] + id - 1 == 8 && i != 1) id = i;//在长度相等的情况下，id换为中间的那个，这样距离更短
            //ps:（r[id]+id-1）这个就是判断id这个是否在尾巴的那个组别
        }
        for(int i = 1; i <= 8; i++)
        {
            if(i == id && r[i] >= 2)//因为存在r[i]为1的情况，所以这里要判断一下
            {
                if (id == 1) printf(":");
                printf(":");
                i = i + r[i] - 1;//减一是因为待会儿有i++
            }
            else
            {
                printf("%x", a[i]);
                if (i != 8) printf(":");
            }
        }
        puts("");
    }
    return 0;
}
