#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define INF 2123456789
#define MOD 1000000007
#define N  191300
using namespace std;

int n,q,dp[N];

int main()
{
	scanf("%d", &n);
	dp[0] = 1, dp[1] = 2;
	for (int i = 2; i < N; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	while(n--) {
		scanf("%d", &q);
		printf("%d\n", dp[q - 1]);
	}
	return 0;
}
