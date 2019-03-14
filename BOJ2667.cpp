#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 30
#define INF 2123456789

using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

// map[0][][]에는 이전에 방문 여부를 저장하고
// map[1][][]에는 집의 유무를 저장한다.
int n, map[2][MAX][MAX];

// 4방향에 대해서 탐색한다.
int dy[4]={0,1,0,-1},dx[4]={1,0,-1,0};
vector<int> ans;
char str[MAX];

// bfs 알고리즘
void bfs(int y,int x)
{
    int cnt=1;
    queue<pi> q;
    q.push({y,x});
    while(!q.empty())
    {
        pi tmp = q.front();
        q.pop();

        // 4방향에 대해 탐색한다.
        for(int i=0;i<4;i++)
        {
            y=tmp.first+dy[i],x=tmp.second+dx[i];
            // 이전에 방문하지 않았고, 집이있다면
            if(map[0][y][x]==0&&map[1][y][x]==1)
            {
                // 방문표시를 해준다.
                map[0][y][x]=1;
                // 큐에 넣어준다.
                q.push({y,x});
                cnt++;
            }
        }
    }
    // 벡터에 집의 갯수를 넣어준다.
    ans.push_back(cnt);
}

int main() {
    // 초기화 및 입력
    fill_n(&map[0][0][0],2*MAX*MAX,0);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",str);
        for(int j=0;j<n;j++)
            map[1][i+1][j+1]=str[j]-'0';
    }

    // 각 좌표에 방문한다.
    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= n; j++) {
            // 이전에 방문하지 않았고, 집이있다면
            if (map[0][i][j] == 0 && map[1][i][j] == 1) {
                map[0][i][j] = 1;
                bfs(i, j);
            }
        }
    }

    // 정렬 하여준다.
    sort(ans.begin(),ans.end());
    // 전체 단지수를 출력하여준다.
    printf("%d\n",ans.size());
    // 집의 갯수를 출력하여준다.
    for(int i=0;i<ans.size();i++)
        printf("%d\n",ans[i]);
    return 0;
}