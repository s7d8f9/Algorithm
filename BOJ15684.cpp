#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <string>
#include <sstream>
#define MAX 35
#define INF 2123456789

using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

int n,m,h,a,b,ans=INF;
// arr[0][][]은 왼쪽노드에서 오른쪽으로 뻗은경우
// arr[1][][]은 오른쪽노드에서 왼쪽으로 뻗은경
// 나중에 생각해보니 그냥 arr[][]로도 해결 가능하다.^^ 바보....
int arr[2][MAX][MAX];

// 현재 사다리 상태 검사 (번 세로선의 결과가 i번이 나오는경우)
bool fun(){
    for(int i=1;i<=n;i++)
    {
        int ny=0,nx=i;
        while(ny!=(h+1))
        {
            if(arr[1][ny][nx-1]&&arr[0][ny][nx])
                nx-=1;
            else if(arr[1][ny][nx]&&arr[0][ny][nx+1])
                nx+=1;
            ny+=1;
        }
        if(nx!=i)
            return false;
    }
    return true;
}

void dfs(int cnt,int cur) {
    if (fun())
        ans = min(cnt, ans);
    if (cnt >= 3)
        return;
    // 가지치기 1 ( cnt가 4인 노드를 만들지 않는다.)

    int tmp=cur;
    while(tmp<n*h-h)
    // 가지치기 2 ( 순열이 아닌 조합으로 조작해야한다.)
    {
        int i=tmp/h+1,j=tmp%h+1;
        // 높이가 h로 나눈 몫을 세로 선, 나머지를 가로 선으로 한다.
        if (!(arr[1][j][i] * arr[0][j][i + 1]) && !(arr[1][j][i - 1] * arr[0][j][i]) &&!(arr[1][j][i + 1] * arr[0][j][i + 2])) {
            arr[1][j][i] = arr[0][j][i + 1] = 1;
            dfs(cnt + 1, tmp+1);
            arr[1][j][i] = arr[0][j][i + 1] = 0;
        }
        tmp++;
    }
}


int main() {
    // 입력을 받아온다.
    scanf("%d%d%d",&n,&m,&h);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        arr[1][a][b]=arr[0][a][b+1]=1;
    }
    // dfs를 시작한다.
    dfs(0,0);

    if(ans>3)
        printf("-1");
    else
        printf("%d",ans);

    return 0;
}