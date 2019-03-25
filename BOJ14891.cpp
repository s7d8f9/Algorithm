#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <string>
#include <sstream>
#define MAX 105
#define INF 2123456789

using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

int n,a,b,d[2]={1,-1};
char str[MAX];
deque<int> dq[5];

void rotate(int num,int r)
{
    if(r==1) {
        dq[num].push_front(dq[num].back());
        dq[num].pop_back();
    } else if(r==-1){
        dq[num].push_back(dq[num].front());
        dq[num].pop_front();
    }
}


int main(){
    for(int i=1;i<=4;i++)
    {
        scanf("%s",str);
        for(int j=0;j<8;j++)
            dq[i].push_back(str[j]-'0');
    }

    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d%d", &a, &b);

        int tf[5]={0,};
        queue<pi> q;

        tf[a]=b;
        q.push({a,b});

        while (!q.empty())
        {
            pi cur=q.front();
            q.pop();

            int na=cur.first-1;
            if(1<=na&&tf[na]==0)
            {
                if(cur.second==3||dq[cur.first].at(6)==dq[na].at(2)) {
                    tf[na]=3;
                    q.push({na, 3});
                }
                else if(dq[cur.first].at(6)!=dq[na].at(2)) {
                    tf[na]=-1 * cur.second;
                    q.push({na, -1 * cur.second});
                }
            }

            na=cur.first+1;
            if(na<=4&&tf[na]==0)
            {
                if(cur.second==3||dq[cur.first].at(2)==dq[na].at(6)){
                    tf[na]=3;
                    q.push({na, 3});
                }
                else if(dq[cur.first].at(2)!=dq[na].at(6)) {
                    tf[na]=-1 * cur.second;
                    q.push({na, -1 * cur.second});
                }
            }
        }
        for(int i=1;i<=4;i++)
            rotate(i,tf[i]);
    }
    int num=1,ans=0;
    for(int i=1;i<=4;i++) {
        if (dq[i].front()==1)
            ans+=num;
        num*=2;
    }
    printf("%d",ans);
    return 0;
}

