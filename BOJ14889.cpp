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

int n,mi=INF,val[MAX][MAX];
bool a[MAX];

// dfs를 이용하여 팀의 조합을 탐색한다.
void dfs(int cur,int cnt){
    if(cnt==n/2)
    {
        int suma=0,sumb=0;
        // 팀이 완성되었을때 a팀과 b팀의 합을 구해 차이를 구해준다.
        for(int i=1;i<=20;i++){
            for(int j=1;j<=20;j++) {
                if (a[i] && a[j])
                    suma += val[i][j];
                if(!a[i]&&!a[j])
                    sumb += val[i][j];
            }
        }
        mi=min(mi,abs(suma-sumb));
        return;
    }
    for(int i=cur;i<=n;i++) {
        a[i]=true;
        dfs(i + 1, cnt + 1);
        a[i]=false;
    }
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            scanf("%d",&val[i][j]);
    }
    dfs(1,0);
    printf("%d",mi);
    return 0;
}

