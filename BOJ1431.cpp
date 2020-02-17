/*
나는 빠가다 나는 빠가다...
비교식에서 어떻게 저런식으로 짤수 있지;;
1. 비교식 부분에서 잘못 판단한게 크다 ...
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#define N 1000001
using namespace std;

int n;
vector<string> v;

int cmpSum(string s){
    int ret=0;
    for(auto a:s){
        if('0'<=a&&a<='9')
            ret+=a-'0';
    }
    return ret;
}


bool cmp(string s1,string s2){
    if(s1.length()==s2.length())
    {
        if(cmpSum(s1)==cmpSum(s2))
            return s1<s2;
        else
            return cmpSum(s1)<cmpSum(s2);
    }
    else
        return s1.length()<s2.length();
    
    // if(s1.length()<s2.length())
    //     return true;
    // else if(cmpSum(s1)<cmpSum(s2))
    //     return true;
    // else
    //     return s1<s2;
    // return false;
}


int main(){
    
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end(),cmp);
    for(auto a:v)
        cout<<a<<endl;
    return 0;
}   
