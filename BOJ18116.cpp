/*
UNION-FIND 문제
마지막에 cout부분에서 <<endl 대신에 <<'\n'해야 통과가 가능
*/
#include <iostream>
#define N 1000001
using namespace std;

int p[N],cnt[N];
int n,a,b;
char op;

int find(int child){
    if(p[child]==child)
        return p[child];
    return p[child]=find(p[child]);
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i=0;i<N;i++){
        p[i]=i;
        cnt[i]=1;
    }
    cin>>n;
    for(int i=0;i<n;i++){
        cin>> op;
        if(op=='I'){
            cin>>a>>b;
            int ra=find(a);
            int rb=find(b);
            if(ra!=rb){
                p[ra]=rb;
                cnt[rb]+=cnt[ra];
                cnt[ra]=0;
            }
        }
        else{
            cin>>a;
            cout<<cnt[find(a)]<<endl;
        }
    }
    return 0;
}   
