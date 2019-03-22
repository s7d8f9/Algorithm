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

int n,m,ans=0,map[MAX][MAX];

// 경사길 확인
int Find(vector<pi> v)
{
    for(int i=1;i<v.size();i++)
    {
        pi &test=v[i-1].first<v[i].first?v[i-1]:v[i];
        // 높이가 1차이 나거나, 낲은 쪽이 L보다 작은경우 못가는 길
        if(test.second<m||abs(v[i-1].first-v[i].first)!=1)
            return 0;
        test.second-=m;
    }
    return 1;
}
// 3 3 2 2 1 1 1 -> {3,2} {2,2} {1,3}으로 변환
vector<pi> Grouping(vector<int> v)
{
    vector<pi> ret;
    int cur=v[0],cnt=1;
    for (int i = 1; i < n; i++)
    {
        if(cur!=v[i]) {
            ret.push_back({cur, cnt});
            cur=v[i],cnt=1;
        }
        else
            cnt++;
    }
    ret.push_back({cur,cnt});
    return ret;
}
int main(){
    // 입력
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &map[i][j]);
    }

    for(int i=0;i<n;i++){
        vector<int> v1,v2;
        for(int j=0;j<n;j++)
        {
            v1.push_back(map[i][j]);
            v2.push_back(map[j][i]);
        }
        ans+=(Find(Grouping(v1))+Find(Grouping(v2)));
    }
    printf("%d",ans);
    return 0;
}

