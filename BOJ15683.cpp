#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <string>
#include <sstream>
#define MAX 15
#define INF 2123456789

using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

// cctv y좌표,x좌표,cctv 종류,현재 방향
struct st{
    int y;
    int x;
    int s;
    int d;
};


int n,m,cctvNum=0,ans=INF,arr[MAX][MAX];
int cctv[6][4]={{},{0,1,0,0},{0,1,0,1},{1,1,0,0},{1,1,0,1},{1,1,1,1}};
int dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
vector<st> v;

int find_ans(){

    bool tf[MAX][MAX];
    fill_n(&tf[0][0],MAX*MAX,0);

    for(int i=0;i<cctvNum;i++)
    {
        for(int j=0;j<4;j++) {  // cctv의 4방향 탐색한다.
            int tmp = cctv[v[i].s][(v[i].d+j) % 4]; // 기본 위치로 부터 현재 방향만큼 회전시킨다.
            int ny=v[i].y,nx=v[i].x;

            // j=0,1,2,3 -> 북동남서를 방향을 말하며
            // tmp는 현재 바라보는 방향을 cctv가 관찰하고 있는 여부를 말한다.
            // arr[ny][nx]가 -1이면 갈수 없는 영역을, 6이면 벽을 말한다.
            while(tmp&&arr[ny][nx]!=-1&&arr[ny][nx]!=6)
            {
                // cctv 관찰 가능한 지역인 경우
                tf[ny][nx]=true;
                ny+=dy[j],nx+=dx[j];
            }
        }
    }
    int ret=0;  // 사각 지대를 센다.
    for(int i=1;i<=n;i++)
        for (int j = 1; j <= m; j++)
            if (!tf[i][j]&&arr[i][j]!=6)
                // cctv가 관찰 하지 않는영역이고 벽이 아닌경우 -> 사각지대
                ret++;
    return ret;
}

void fun(int cnt)
// 완전 탐색 시작
{
    if(cnt==cctvNum) {
    // 모든 cctv의 회전 횟수를 정하였다면 사각지대 갯수찾기
        ans = min(ans, find_ans());
        return;
    }
    for(int i=0;i<4;i++)
    // 각 cctv에 회전 횟수 저장하기
    {
        v[cnt].d=i;
        fun(cnt+1);
    }
}


int main(){
    // 배열 전체를 -1로 설정한다.(처리하기 쉬워짐)
    fill_n(&arr[0][0],MAX*MAX,-1);
    // 입력을 받으면서 cctv 갯수를 센다.
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&arr[i][j]);
            if(0<arr[i][j]&&arr[i][j]<=5) {
                cctvNum++;
                // cctv y좌표,x좌표,cctv 종류,현재 방향
                v.push_back({i,j,arr[i][j],0});
            }
        }
    fun(0);
    printf("%d",ans);

    return 0;
}

