#include <iostream>
using namespace std;
int n, dp[1500055];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int day, money;
		scanf("%d%d", &day, &money);
		dp[i + 1] = dp[i + 1] < dp[i] ? dp[i] : dp[i + 1];
		dp[i + day] = dp[i + day] < dp[i] + money ? dp[i] + money : dp[i + day];
	}
	printf("%d", dp[n + 1]);
	return 0;
}
