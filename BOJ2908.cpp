#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
	string str1, str2;
	bool tf;
	cin >> str1 >> str2;
	for (int i = str1.size() - 1; i >= 0; i--) {
		if (str1.at(i) == str2.at(i))
			continue;
		tf = str1.at(i) > str2.at(i) ? true : false;
		break;
	}
	for (int i = str1.size() - 1; i >= 0; i--) {
		if (tf)
			cout << str1.at(i);
		else
			cout << str2.at(i);

	}


}
