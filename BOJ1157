#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
	vector<int> v, cv;
	string str1, buf;
	cin >> str1;
	for (int i = 'A'; i <= 'Z'; i++)
		v.push_back(count(str1.begin(), str1.end(), i));
	for (int i = 'a'; i <= 'z'; i++)
		v[i - 'a'] += count(str1.begin(), str1.end(), i);

	cv = v;
	sort(v.begin(), v.end());
	if (v[v.size() - 1] == v[v.size() - 2])
		cout << "?";
	else {
		for (int i = 0; i < cv.size(); i++)
			if (v[v.size() - 1] == cv[i])
				printf("%c", 'A' + i);
	}
}
