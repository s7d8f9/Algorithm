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

int n,m,a,b;
vector<int> v;
ll ans=0;
/*
 * 0. 한 응시장에는 최소 한명의 총감독관이 있어야한다.
 * 1. Aj(응시자 수)보다 a(총감독관의 감시 가능 한 응시자 수)가 큰 경우.
 * 2. 출력이 int형을 벋어 날 수 있다.
 */

int main() {

    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d", &m);
        v.push_back(m);
    }
    scanf("%d%d",&a,&b);

    for(int i=0;i<v.size();i++)
    {
        // 총시동관의 수가 전체 응사지보다 큰 경우
        if(v[i]<a)
            ans++;
        // 남은 응시자 수가 부감독관의 수로 나누어 떨어지는 경우
        else if((v[i]-a)%b==0)
            ans+=((v[i]-a)/b)+1;
            // 남은 응시자 수가 부감독관의 수로 나누어 떨어지는 경우 (+1)
        else
            ans+=((v[i]-a)/b)+2;
    }
    printf("%lld",ans);
    return 0;
}