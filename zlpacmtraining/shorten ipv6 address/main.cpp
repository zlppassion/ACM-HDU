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
        for(int i = 1; i <= 8; i++)//������תʮ���ƣ�ÿһλ��2��j�η�
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
            if (a[i] == 0) r[i] = r[i+1] + 1;//�����������м���0
            if (r[id] < r[i]) id = i;//�϶��ǿ���ת�����������Ǹ�
            if (r[id] == r[i] && r[id] + id - 1 == 8 && i != 1) id = i;//�ڳ�����ȵ�����£�id��Ϊ�м���Ǹ��������������
            //ps:��r[id]+id-1����������ж�id����Ƿ���β�͵��Ǹ����
        }
        for(int i = 1; i <= 8; i++)
        {
            if(i == id && r[i] >= 2)//��Ϊ����r[i]Ϊ1���������������Ҫ�ж�һ��
            {
                if (id == 1) printf(":");
                printf(":");
                i = i + r[i] - 1;//��һ����Ϊ�������i++
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
