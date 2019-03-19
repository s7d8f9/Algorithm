#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <string>
#include <sstream>
#define MAX 555
#define INF 2123456789

using namespace std;
typedef long long ll;

int n,m,mx=-1;
int dy[4]={0,1,0,-1},dx[4]={1,0,-1,0}, map[MAX][MAX];
bool visit[MAX][MAX];

int dfs(int cnt,int y,int x)
{
    // 4번째 블럭에서 종료
    if(cnt==4)
        return map[y][x];
    int sum=0;
    // visit을 안해주면 방문한 블럭 또 방문한다.
    visit[y][x]=true;
    for(int i=0;i<4;i++)
    {
        int ny=y+dy[i],nx=x+dx[i];
        if(!visit[ny][nx])
            sum=max(sum,dfs(cnt+1,ny,nx));
    }
    visit[y][x]=false;
    return sum+map[y][x];
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
       for(int j=0;j<m;j++)
           scanf("%d",&map[i+3][j+3]);

    for(int i=3;i<n+3;i++)
        for (int j = 3; j < m + 3; j++) {
            // ㅗ 모양이외의 도형은 dfs를 이용하여 검사한다.
            mx = max(mx, dfs(1, i, j));

            // ㅗ 모양 의 검사 : +에서 4방향의 위치를 빼서 구해준다.
            int sum=map[i][j];
            for(int k=0;k<4;k++)
                sum+=map[i+dy[k]][j+dx[k]];
            for(int k=0;k<4;k++)
                mx = max(mx, sum-map[i+dy[k]][j+dx[k]]);
        }
    printf("%d",mx);

    return 0;
}