#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
#define pi pair<int,int>
bool cmp(pi a, pi b) {    return a.first > b.first;}    // 비교 함수
struct st {    // is는 현재 이기고, 무승부, 진것에 대한 offset
    int a[2];
    double b[3];
    int is;
};
char str[4][15], input[15];
double ans[4];
st v[10];
void dfs(int sz)
{
    if (sz == 6)
    {
        // 각 국의 승점 및 확률 계산
        int s[4] = { 0, };
        double ret = 1;
        for (int i = 0; i < 6; i++)
        {
            int cur = v[i].is;
            ret *= v[i].b[cur];
            if (cur == 0)
                s[v[i].a[0]] += 3;
            else if (cur == 2)
                s[v[i].a[1]] += 3;
            else
            {
                s[v[i].a[0]] += 1;
                s[v[i].a[1]] += 1;
            }
        }
        
        // 동점자 계산 및 각 국에 확률 더해주기
        vector<pi> vp;
        for (int i = 0; i < 4; i++)
            vp.push_back({ s[i],i });
        int cnt = 2;
        while (cnt > 0)
        {
            int num = 0,mx;
            sort(vp.begin(), vp.end(), cmp);
            mx = vp.front().first;
            for (int i = 0; i < 4; i++)
                if (vp[i].first == mx)
                    num++;
            for (int i = 0; i < num; i++)
            {
                double add = cnt > num ? ret : ret * ((float)cnt / num);
                ans[vp[i].second] += add;
                vp[i].first = -1;
            }
            cnt -= cnt > num ? num : cnt;
        }
        return;
    }
    // 완탐 검색
    for (int i = 0; i < 3; i++)
    {
        v[sz].is = i;
        dfs(sz+1);
    }
}
int main()
{
    for (int i = 0; i < 4; i++)
        scanf("%s", str[i]);
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%s", input);
            for (int p = 0; p < 4; p++)
                if (strcmp(str[p], input) == 0)
                    v[i].a[j] = p;
        }
        for (int j = 0; j < 3; j++)
            scanf("%lf", &v[i].b[j]);
    }
    dfs(0);
    for (int i = 0; i < 4; i++)
        printf("%.10lf\n", ans[i]);
    return 0;
}
