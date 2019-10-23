输入中第一行有两个数m,n表示有m(m<=100000)笔账,n表示有n个问题，n<=100000。
后面n行分别是n个问题,每行有2个数字说明开始结束的账目编号。
问在a到b号账中最少的一笔是多少？
输入样例#1：
10 3
1 2 3 4 5 6 7 8 9 10
2 7
3 9
1 10
输出样例#1：

2 3 1
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int size =1e5+10;
int a[size];
int f[size][40];

void init_rmq(int m) {
    for(int i=1;i<=m;i++)
        f[i][0]=a[i];
    for(int j=1;(1<<j)<m;j++) {
        for(int i=1;i<=m;i++) {
            if(i+(1<<j)-1 <= m) {
                f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
            }
        }
    }
}

int query_rmq(int l,int r) {
    int i=0;
    for(;(1<<i)+l-1<=r;i++){};
    i--;
    return min(f[l][i],f[r-(1<<i)+1][i]);
}

int main() {
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    init_rmq(m);
    for(int i=1,l,r;i<=n;i++) {
        scanf("%d%d",&l,&r);
        printf("%d ",query_rmq(l,r));
    }
    return 0;
}
