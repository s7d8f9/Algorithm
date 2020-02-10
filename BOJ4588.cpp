#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int arr[150][150];
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };

struct st {
	int value;
	pair<int, int> pos;
};
struct cmp {
	bool operator()(st& u, st& v) {
		return u.value > v.value;
	}
};

priority_queue<st, vector<st>, cmp> pq;

int main()
{
	int cur = 0;
	scanf("%d", &n);
	while (n != 0) {
		cur++;
		fill_n(&arr[0][0], 150 * 150, -1);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &arr[i][j]);

		st s = { arr[1][1],{1,1 } };
		pq.push(s);
		arr[1][1] = -1;

		while (!pq.empty())
		{
			st p = pq.top();
			if (p.pos.first == n && p.pos.second == n) {
				printf("Problem %d: %d\n", cur, p.value);
			}
			//printf("%d\n", p.value);
			for (int i = 0; i < 4; i++)
			{
				int ny = p.pos.first + dy[i], nx = p.pos.second + dx[i];
				if (arr[ny][nx] == -1)
					continue;
				pq.push({ p.value + arr[ny][nx], { ny,nx } });
				arr[ny][nx] = -1;

			}
			pq.pop();
		}
		scanf("%d", &n);
	}


}
