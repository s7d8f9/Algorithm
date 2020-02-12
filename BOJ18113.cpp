/*
제길.... 
1. 길이 16짜리 김밥을 꼬다리 8로 자르면 김밥 길이가 0으로 계산해야 했다^^;;
-> 그냥 한 쪽만 잘라서 8로 계산해서 틀렸다...
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define INF 2123456789
using namespace std;

int n, k, m, a;
vector<int> v;

bool test(int input) {
	int cnt = 0;
	for (auto a : v)
		cnt += a / input;
	return cnt >= m;
}

int main()
{
	cin >> n >> k >> m;
	while (n--) {
		cin >> a;
		if (a - 2 * k >= 0) {
			v.push_back(a - 2 * k);
			continue;
		}
		else if (a - k > 0) {
			v.push_back(a - k);
			continue;
		}
	}
	int low = 1, high = 1000000000,ans=-1;
	while (low <= high) {
		int mid = (low + high) / 2;	
		if (test(mid)) {
			ans = max(mid, ans);
			low = mid + 1;
		}
		else
			high = mid-1;
	}
	cout << ans;
	return 0;
}
