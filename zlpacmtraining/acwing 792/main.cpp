#include<iostream>
#include<vector>
using namespace std;
bool cmp(vector<int> &A,vector<int> &B){//�ж϶������ֵĴ�С
    if(A.size() !=B.size()) return A.size()>B.size();//λ����ͬ��λ���ߵĴ�

    // for(int i=0;i<A.size();i++){//�͵��߱Ƚ�
    //     if(A[i]!=B[i])
    //         return A[i]>B[i];//λ����ͬ����
    // }����д�����Ƚ�˳����
     for(int i=A.size()-1;i>=0;i--){//�ߵ��ͱȽ�
        if(A[i]!=B[i])
            return A[i]>B[i];//λ����ͬ����
    }
    return true;
}
vector<int> sub(vector<int> A,vector<int> B){
    vector<int> C;
    int t = 0;//����ȷ���Ƿ��λ
    for(int i=0;i<A.size();i++){
        t=A[i]-t;
        if(i<B.size()) {
            t-=B[i];//��ͬλ�����
            }
            C.push_back((t+10)%10);//��һд���ǳ����룬���c>0���ֲ��仹��c,c<0����ǰ���λc+10
        if(t<0) t=1;
        else t=0;
    }

    //Ŀǰ�������C��λ����A��ͬ������Cʵ��λ����С����������Ҫȥ��ǰ����
    while(C.size()>1&&C.back()==0) C.pop_back();
    return C;
}
int main(){
    string a,b;
    cin>>a>>b;
    vector<int> A,B;
    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--) B.push_back(b[i]-'0');
    vector<int> C;
    if(cmp(A,B)) C=sub(A,B);
    else C = sub(B,A),cout<<'-';
    for(int i=C.size()-1;i>=0;i--) cout<<C[i];
    cout<<endl;
    return 0;
}
