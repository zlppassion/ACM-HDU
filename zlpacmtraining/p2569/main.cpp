#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,ap,bp,as,bs,ans=0,w;
int f[2002][2002],l,r,q[2001];
//f[i][j]��ʾ��i���ӵ��j�Ź�Ʊ׬�����Ǯ��
//l,r,q[x]���ڵ�������
int main()
{
    scanf("%d%d%d",&n,&m,&w);//n�죬m�����ͷ������w��������
    memset(f,128,sizeof(f));//128ʵ���ϸ�f���鸳����-inf,��-2139062144
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&ap,&bp,&as,&bs);
        for(int j=0;j<=as;j++)
            f[i][j]=-1*j*ap;//��һ�������ֱ�Ӹ�ֵ��
        for(int j=0;j<=m;j++)
            f[i][j]=max(f[i][j],f[i-1][j]);//ת�ƣ�������첻���Ʊ
        if(i<=w)//��Ϊ��3��4���������i-w-1,���i<=w,����ָ��±�
            continue;
        //��3���������֮ǰ�Ļ��������Ʊ��f[i,j]=max(f[i,j],f[i-w-1,k]-(j-k)*api];
        //���Խ�һ��ת��Ϊf[i,j]=max(f[i,j],f[i-w-1,k]+k*api]-j*api;
        l=1,r=0;//��������׼��,��Сת�Ƶ�����Ϊ�����Ʊ��jӦ����Խ��Խ��
        for(int j=0;j<=m;j++)
        {
            while(l<=r&&q[l]<j-as)
                l++;//�ѹ��ڵ�Ԫ���ӵ�
            while(l<=r&&f[i-w-1][q[r]]+q[r]*ap<=f[i-w-1][j]+j*ap)//���ֵ�ڿ�ͷ����������
                r--;
            q[++r]=j;//���µ�������Ԫ��
            if(l<=r)//�����������������Ԫ�أ�������ת��,��Ϊ����Ҫ�������ֵ��������l
                f[i][j]=max(f[i][j],f[i-w-1][q[l]]+q[l]*ap-j*ap);


        }
        //��4���������֮ǰ�Ļ���������Ʊ��f[i,j]=max(f[i,j],f[i-w-1,k]+(k-j)*bpi];
        //���Խ�һ��ת��Ϊf[i][j]=max(f[i][j],f[i-w-1,k]+k*bp)-j*bp;
        l=1,r=0;//��������׼�����Ӵ�ת�Ƶ�С����Ϊ������Ʊ��jӦ����Խ��ԽС
        for(int j=m;j>=0;j--)
        {
            while(l<=r&&q[l]>j+bs)
                l++;//�ѹ��ڵ�Ԫ���ӵ�
            while(l<=r&&f[i-w-1][q[r]]+q[r]*bp<=f[i-w-1][j]+j*bp)//���ֵ�ڿ�ͷ����������
                r--;
            q[++r]=j;
            if(l<=r)//���������������Ԫ�أ�����ת��
                f[i][j]=max(f[i][j],f[i-w-1][q[l]]+q[l]*bp-j*bp);
        }
    }
    for(int i=0;i<=m;i++)
    {
        ans=max(ans,f[n][i]);
    }
    cout<<ans<<endl;
    return 0;
}
