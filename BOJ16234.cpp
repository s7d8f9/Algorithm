#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, low, high, map[55][55];
int dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 };

int sum, num;
bool changed = true, tf[55][55];
vector<pair<int, int>> v;


int bfs() {
	int ret = -1;
	while (changed) {
		ret++;
		changed = false;
		fill_n(&tf[0][0], 55 * 55, false);

		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++) {
				if (tf[i][j])
					continue;

				v.clear();
				sum = 0, num=0;

				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k], nx = j + dx[k];
					int interval = abs(map[i][j] - map[ny][nx]);
					if (low <= interval && interval <= high) {
						num++;
						tf[i][j] = true;
						sum += map[i][j];
						v.push_back({ i,j });
						break;
					}
			
				}


				for (int vi = 0; vi < v.size(); vi++) {
					pair<int, int> cur = v[vi];

					for (int k = 0; k < 4; k++) {
						int ny = cur.first + dy[k], nx = cur.second + dx[k];
						int interval = abs(map[cur.first][cur.second] - map[ny][nx]);
						if (low <= interval && interval <= high) {
							if (!tf[ny][nx]) {
								num++;
								tf[ny][nx] = true;
								sum += map[ny][nx];
								v.push_back({ ny,nx });
							}
						}
					}
				}

				if (sum == 0)
					continue;
				else {
					changed = true;
					for (int i = 0; i < v.size(); i++)
						map[v[i].first][v[i].second] = sum / num;
				}
			}
	}
	return ret;
}

int main()
{
	fill_n(&map[0][0], 55 * 55, 999);
	scanf("%d %d %d", &n, &low, &high);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &map[i][j]);
	printf("%d",bfs());
	return 0;
}
