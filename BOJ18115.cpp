#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int n,op;
vector<int> ops;
deque<int> dq;

int main(){
    cin>> n;
    for(int i=1;i<=n;i++)
    {
        cin>>op;
        ops.push_back(op);    
    }
    for(int i=1;i<=n;i++)
    {
        switch (ops.back())
        {
            case 1:{
                dq.push_back(i);
                break;
            }
            case 2:{
                int tp=dq.back();
                dq.pop_back();
                dq.push_back(i);
                dq.push_back(tp);
                break;
            }
            case 3:{
                dq.push_front(i);
                break;
            }
        }
        ops.pop_back();
    }
    while(!dq.empty()){
        cout<<dq.back()<<' ';
        dq.pop_back();
    }
    
}   
