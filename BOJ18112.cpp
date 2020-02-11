#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define INF 2123456789
using namespace std;

bool tf[1025];

struct nn {
	int dex;
	int cnt = 0;
	string bin;
	nn() {}
	nn(int c,int input) {
		dex = input;
		dtob();
		cnt = c;
	}
	nn(int c, string input) {
		bin = input;
		btod();
		cnt = c;
	}
	void btod() {
		int ret = 0, cur = 1;
		for (int i = bin.length() - 1; i >= 0; i--) {
			ret += (bin[i] - '0') * cur;
			cur *= 2;
		}
		dex = ret;
	}
	void dtob() {
		vector<string> v;
		int tmp = dex;
		while (tmp != 1) {
			v.push_back(to_string(tmp % 2));
			tmp /= 2;
		}
		v.push_back(to_string(1));
		bin.clear();
		while (!v.empty()) {
			bin.append(v.back());
			v.pop_back();
		}
	}
}typedef num;

queue<num> q;

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	num n1(0,str1), n2(0,str2);

	q.push(n1);
	while (!q.empty()) {
		num tmp = q.front();
		q.pop();

		if (tmp.dex == n2.dex) {
			cout << tmp.cnt;
			return 0;
		}

		int nxt = tmp.dex + 1;
		if (nxt<= 1024 && !tf[nxt]) {
			num n3(tmp.cnt+1,nxt);
			tf[nxt] = true;
			q.push(n3);
		}
		nxt = tmp.dex - 1;
		if (1 <= nxt && !tf[nxt]) {
			num n3(tmp.cnt+1,nxt);
			tf[nxt] = true;
			q.push(n3);
		}

		for (int i = 1; i < tmp.bin.size(); i++) {
			string str3 = tmp.bin;
			str3.at(i) = str3.at(i) == '0' ? '1' : '0';
			num n3(tmp.cnt + 1, str3);
			if (1 <= n3.dex && n3.dex <= 1024 && !tf[n3.dex]) {
				tf[n3.dex] = true;
				q.push(n3);
			}
		}

	}
	return 0;
}
