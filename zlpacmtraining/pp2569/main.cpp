#include <cstdio>
#include <cstring>
//#define Min(x , y) ((x) < (y) ? (x) : (y))
//#define Max(x , y) ((x) > (y) ? (x) : (y))
#include<bits/stdc++.h>
using namespace std;
int n , m , ap , bp , as , bs , w , ans = 0 , f[2001][2001] , l , r , q[2001];
// f[i][j] ��ʾ�� i ���ӵ�� j �Ź�Ʊ׬�����Ǯ��
// l , r , q[x] ���ڵ�������

int main(){
    scanf("%d%d%d" , &n , &m , &w);
    memset(f , 128 , sizeof(f)); // 128 ʵ���ϸ� f ���鸳���� -inf���������Կ�
    for(int i = 1 ; i <= n ; i++){
        scanf("%d%d%d%d" , &ap , &bp , &as , &bs);
        for(int j = 0 ; j <= as ; j++)
            f[i][j] = -1 * j * ap; // �� 1 �������ֱ�Ӹ�
        for(int j = 0 ; j <= m ; j++)
            f[i][j] = max(f[i][j] , f[i - 1][j]); // �� 2 �������ת��
        if(i <= w)
            continue; // ��Ϊ�� 3��4 ��������� i - w - 1����� i <= w������ָ��±�
        // �� 3 ���������Сת�Ƶ���
        l = 1 , r = 0; // ��������׼��
        for(int j = 0 ; j <= m ; j++){
            while(l <= r && q[l] < j - as)
                l++; // �ѹ��ڵ�Ԫ���ӵ�
            while(l <= r && f[i - w - 1][q[r]] + q[r] * ap <= f[i - w - 1][j] + j * ap)
                r--; // ���µ�������Ԫ��
            q[++r] = j; // ��������Ԫ��
            if(l <= r)
                f[i][j] = max(f[i][j] , f[i - w - 1][q[l]] + q[l] * ap - j * ap);
            // ���������������Ԫ�أ�����ת��
        }
        // �� 4 ��������Ӵ�ת�Ƶ�С
        l = 1 , r = 0; // ���������ٴ�׼��
        for(int j = m ; j >= 0 ; j--){
            while(l <= r && q[l] > j + bs)
                l++; // �ѹ��ڵ�Ԫ���ӵ�
            while(l <= r && f[i - w - 1][q[r]] + q[r] * bp <= f[i - w - 1][j] + j * bp)
                r--; // ���µ�������Ԫ��
            q[++r] = j; // ��������Ԫ��
            if(l <= r)
                f[i][j] = max(f[i][j] , f[i - w - 1][q[l]] + q[l] * bp - j * bp);
            // ���������������Ԫ�أ�����ת��
        }
    }
    for(int i = 0 ; i <= m ; i++)
        ans =max(ans , f[n][i]); // ��󣬿�������Ʊ��ʵ���ϲ����κι�Ʊ�ľ������Ŵ𰸣����ҳ����Ŵ�
    printf("%d\n" , ans);
    return 0;
}
