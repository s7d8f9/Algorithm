#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 55
#define INF 2123456789

using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

// p는 좌표값, black은 화이트로 만든 칸의 갯수
struct st{
    pi p;
    int black=0;
};

int n;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
// map은 입력 받아 온것 , visit은 해당 좌표까지 오는데 black의 최소 값
int map[MAX][MAX],visit[MAX][MAX];
char str[MAX];
queue<st> q;

int main() {

    // 초기 map을 모두 -1로 설정한다.
    fill_n(&map[0][0],MAX*MAX,-1);
    fill_n(&visit[0][0],MAX*MAX,INF);

    // 입력받아온다.
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%s",str);
        for (int j = 1;j <=n; j++) {
            map[i][j] = str[j - 1] - '0';
        }
    }

    // 시작지점 넣어준다.
    st s = {{1,1},0};
    q.push(s);

    // bfs를 돌려준다.
    while(!q.empty()){
        s = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int y = s.p.first+dy[i], x =s.p.second+dx[i];

            // 0 or 1만 방문해준다.
            if(map[y][x]==-1)
                continue;

            // 이동하려는 칸이 흰색인 경우.
            if(map[y][x]==1&&visit[y][x]>s.black){
                visit[y][x]=s.black;
                q.push({{y,x},s.black});
            }

            // 이동하려는 칸이 검은색인 경우.
            if(map[y][x]==0&&visit[y][x]>(s.black+1)){
                visit[y][x]=s.black+1;
                q.push({{y,x},s.black+1});
            }
        }
    }

    // 결과값을 출력해준다.
    printf("%d",visit[n][n]);
    return 0;
}