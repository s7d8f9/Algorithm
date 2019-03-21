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

int n,m,op[4],mi=INF,mx=-INF;
vector<int> v;

// 백트래킹 이용한 재귀함수
// 전역변수로 쉽게 해결

void fun(int pre,int times)
{
    if(times==n)
    {
        mi=min(mi,pre);
        mx=max(mx,pre);
        return ;
    }
    for(int i=0;i<4;i++)
    {
        int tmp=pre;
        if(op[i]>0)
        {
            // 각 연산자 + - * / 계산하도록 한다.
            if(i==0)
                tmp+=v[times];
            else if(i==1)
                tmp-=v[times];
            else if(i==2)
                tmp*=v[times];
            else
                tmp/=v[times];
            op[i]--;
            fun(tmp,times+1);
            op[i]++;
        }
    }
}

int main() {
    // 입력을 받아온다.
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m);
        v.push_back(m);

    }
    for(int i=0;i<4;i++)
        scanf("%d",&op[i]);

    // 재귀함수 이용
    fun(v[0],1);
    printf("%d\n%d",mx,mi);
    return 0;
}

