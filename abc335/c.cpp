#include <iostream>
#include <iomanip>
#include <sstream>
#include <list>
#include <utility>
#include <string>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <climits>
#include <cstring>
// #include <cstdlib>
#include <limits>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <tuple>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

int main()
{
    int N, Q;
    cin >> N >> Q;

    deque<pair<int, int>> que;

    rep(i, N)
    {
        que.emplace_back(i + 1, 0);
    }

    while (Q--)
    {
        int i;
        cin >> i;

        // cout << "i=" << i;

        if (i == 1)
        {
            char c;
            cin >> c;

            // cout << ", c:" << c << endl;

            if (c == 'U')
            {
                que.emplace_front(que.front().first, que.front().second + 1);
                que.pop_back();
            }
            else if (c == 'D')
            {
                que.emplace_front(que.front().first, que.front().second - 1);
                que.pop_back();
            }
            else if (c == 'L')
            {
                que.emplace_front(que.front().first - 1, que.front().second);
                que.pop_back();
            }
            else if (c == 'R')
            {
                que.emplace_front(que.front().first + 1, que.front().second);
                que.pop_back();
            }

            // cout << c << endl;
            // cout << "que:";
            // for (auto x : que)
            // {
            //     cout << "(" << x.first << "," << x.second << ") ";
            // }
        }
        else
        {
            int p;
            cin >> p;

            cout << que[p - 1].first << " " << que[p - 1].second << endl;
        }
    }
    return 0;
}
