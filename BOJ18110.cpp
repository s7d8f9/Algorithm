#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

float n;
vector<float> v;

int main()
{
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		float a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());	
	float sum = 0, sz=v.size(), mi= round(n * 0.15);
	for (int i = mi; i < sz - mi; i++)
		sum += v[i];
	cout << round(sum/(sz-mi*2));
	return 0;
}
