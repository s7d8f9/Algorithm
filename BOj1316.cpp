#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, cnt = 0;
string str;
bool tf[50];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		fill_n(&tf[0], 50, false);
		cin >> str;

		char cur = -1;

		for (int j = 0; j < str.length(); j++) {
			if (cur != str[j])
			{
				if (tf[str[j] - 'a'])
					break;
				else {
					cur = str[j];
					tf[str[j] - 'a'] = true;
				}
			}
			if (j == str.length() - 1)
				cnt++;
		}
	}
	cout << cnt;
	   
}
