#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[60];
char s1[]="COFFEE";
char s2[]="CHICKEN";
int main()
{
    a[1]=6; a[2]=7;
    for(int i=3;i<=60;i++)
        a[i]=a[i-1]+a[i-2];
    int n, T; scanf("%d",&T);
    while(T--){
        LL k; scanf("%d%lld",&n,&k);
        LL len=k+9;
        if(n>60) n=60;
        len=min(len,a[n]);
        for(LL i=k;i<=len;i++){
            int tmp=n;
            LL ii=i;
            while(tmp>2){
                if(ii<=a[tmp-2]) tmp-=2;
                else ii-=a[tmp-2],tmp--;
            }
            if(tmp==1) printf("%c",s1[ii-1]);//��һ����Ϊ�����Ǵ�0�±꿪ʼ�ġ�
            else printf("%c",s2[ii-1]);
        }
        //puts("");
        cout<<endl;
    }
    return 0;
}
