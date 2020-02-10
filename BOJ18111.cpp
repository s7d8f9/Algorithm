#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 2123456789
using namespace std;

int n, m, b;
int arr[505][505];

int main()
{
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);
	int ans = INF,height=-1;
	for (int h = 0; h <= 256; h++) {
		int minus = 0, plus = 0;
		for(int i=0;i<n;i++)
			for (int j = 0; j < m; j++) {
				if (arr[i][j] > h)
					plus += arr[i][j] - h;
				else
					minus += h - arr[i][j];
			}
		if (plus + b >= minus){
			int tmp = plus * 2 + minus;
			if (tmp <= ans) {
				ans = tmp;
				height = h;
			}
		}
		else
			continue;
	}
	cout << ans<<' '<<height;
	return 0;
}
