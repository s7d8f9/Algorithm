#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <limits.h>
#define MAX 55
#define INF 2123456789

using namespace std;

typedef long long ll;
typedef pair<int,int> pi;

int n,m,a,mi=INF;
vector<pi> chi,hou,cho;

void dfs(int cnt)
// 브루트 포스 치킨 집을 조합으로 cho에 넣어준다.
{
    if(cho.size()==m)
    // 선택된 치킨집이 m일 때 종료
    {
        int sum=0;  // 선택된 치킨 집과 각 집들간의 최단거리 합
        for(int i=0;i<hou.size();i++)
        // 집과 선택된 치킨집의 거리가 가장 짧은 곳의 거리 측정한다.
        {
            int tmp=INF,y=hou[i].first,x=hou[i].second;
            for(int j=0;j<cho.size();j++)
                tmp=min(tmp,abs(y-cho[j].first)+abs(x-cho[j].second));
            sum+=tmp;
        }
        mi=min(mi,sum);
        return;
    }
    for(int i=cnt;i<chi.size();i++)
    {
        cho.push_back(chi[i]);
        dfs(i+1);
        cho.pop_back();
    }
}

int main() {
    // 입력을 받아온다.
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            scanf("%d",&a);
            if(a==1)
                hou.push_back({i,j});
            if(a==2)
                chi.push_back({i,j});
        }
    // 브루트 포스
    dfs(0);
    // 정답 출력
    printf("%d",mi);
    return 0;
}