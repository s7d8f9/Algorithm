#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <string>
#include <sstream>
#define MAX 105
#define INF 2123456789

using namespace std;
typedef long long ll;

int n;
char str[205];
vector<vector<char>> v;

int main() {
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%s", str);
        queue<char> tmp;
        for(int j=0;j<strlen(str);j++)
        {
            // 0~9 사이의 값인 경우
            if('0'<=str[j]&&str[j]<='9')
                tmp.push(str[j]);

            // 0~9 사이의 값이아니거나 마지막이고 큐의 원소가 한개이상인 경우
            if((!('0'<=str[j]&&str[j]<='9')||j==(strlen(str)-1))&&tmp.size()!=0)
            {
                // 앞에 나온 0을 모두 제거하여준다.
                while(!tmp.empty()&&tmp.front()=='0')
                    tmp.pop();

                vector<char> vv;
                while(!tmp.empty()) {
                    vv.push_back(tmp.front());
                    tmp.pop();
                }
                // 0인 경우
                if(vv.size()==0)
                    vv.push_back('0');
                v.push_back(vv);
            }
        }
    }

    // 문자열 비교한다.
    sort(v.begin(),v.end());
    // 문자열 길이순으로 출력해준다.
    for(int k=1;k<=100;k++)
    {
        for(int i=0;i<v.size();i++)
        {
            if(v[i].size()==k) {
                for (int j = 0; j < v[i].size(); j++)
                    printf("%c", v[i][j]);
                printf("\n");
            }
        }
    }

    return 0;
}