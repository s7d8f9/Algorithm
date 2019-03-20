#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <string>
#include <sstream>
#define MAX 55
#define INF 2123456789

using namespace std;
typedef long long ll;

int n,m,y,x,d;
// 북,동,남,서(시계방향)
int dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
int map[MAX][MAX];


int main() {

    // 입력을 받아온다.
    scanf("%d%d",&n,&m);
    scanf("%d%d%d",&y,&x,&d);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&map[i][j]);

    int tf=1,cnt=0;
    while(tf)
    {
        if(!map[y][x])
            cnt++;
        map[y][x]=2;

        for(int i=0;i<5;i++)
        {
            // 4방향 모두 탐색하였을 때,
            if(i==4)
            {
                int ny = y+dy[(d+2)%4], nx = x+dx[(d+2)%4];
                // 뒤로 이동 가능 한 경우
                if (map[ny][nx] != 1) {
                    y = ny,x = nx;
                }
                // 뒤가 벽인 경우
                else
                    tf = 0;
                break;
            }
            // 회전 하면서 확인한다.
            d=(d+3)%4;
            int ny=y+dy[d],nx=x+dx[d];
            if(!map[ny][nx]) {
                y = ny, x = nx;
                break;
            }

        }
    }
    printf("%d",cnt);
    return 0;
}

