/*
알고리즘 : 세그먼트트리
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#define N 1000001
#define ll long long
using namespace std;

ll date[N*4]={0,};
int n,q,a,b,c;

void update(int dest,ll val,int idx, int left,int right){
    if(dest<left||right<dest)
        return;
    date[idx]+=val; 
    if(left!=right){
        update(dest,val,idx*2,left,(left+right)/2);
        update(dest,val,idx*2+1,(left+right)/2+1,right);
    }
}

ll sum(int st,int fi,int idx,int left,int right){
    if(fi<left||right<st)
        return 0;
    if(st<=left&&right<=fi)
        return date[idx];
    return sum(st,fi,idx*2,left,(left+right)/2)+sum(st,fi,idx*2+1,(left+right)/2+1,right);
}

int main(){

    cin>>n>>q;
    for(int i=0;i<q;i++){
        scanf("%d%d%d",&a,&b,&c);
        if(a==1)
            update(b,(ll)c,1,1,n);
        else
            printf("%lld\n",sum(b,c,1,1,n));
    }

    return 0;
}   
