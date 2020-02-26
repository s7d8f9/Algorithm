/*
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#define N 1000001
#define ll long long
#define pi pair<int,int>
using namespace std;

typedef struct st1{
    int num;
    int order;
    int cnt;
}student;
bool tf[105];

bool compare(student s1,student s2){
    if(s1.cnt==s2.cnt)
        return s1.order>s2.order;
    else
        return s1.cnt>s2.cnt;
}

bool compareAns(student s1,student s2){
    return s1.num<s2.num;
}

int n,q,a;
vector<student> v;

void increase(int n){
    for(int i=0;i<v.size();i++){
        if(v[i].num==n){
            v[i].cnt++;
            return;
        }
    }
}

int main(){
    int ord=0;
    scanf("%d %d",&n,&q);
    while(q--){
        scanf("%d",&a);
        if(tf[a]){
            increase(a);
        }
        else{
            if(v.size()>=n){
                sort(v.begin(),v.end(),compare);
                tf[v.back().num]=false;
                v.pop_back();
            }    
            v.push_back({a,ord++,0});
            tf[a]=true;
        }
    }
    sort(v.begin(),v.end(),compareAns);
    for(auto a:v)
        printf("%d ",a.num);
    return 0;
}   
