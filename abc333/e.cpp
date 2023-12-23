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
    int N;
    cin >> N;

    vector<int> ts(N, 0);
    vector<int> xs(N, 0);
    vector<int> positons(N, 0);

    bool failed = false;

    rep(i, N)
    {
        cin >> ts[i] >> xs[i];
        xs[i]--;

        switch (ts[i])
        {
        case 1:
            positons[xs[i]]++;
            break;
        case 2:
            positons[xs[i]]--;
            if (positons[xs[i]] < 0)
            {
                failed = true;
            }
            break;
        }
    }

    if (failed)
    {
        cout << -1 << endl;
        return 0;
    }

    // cout << "postions:" << endl;
    // rep(i, N)
    // {
    //     cout << positons[i] << " ";
    // }
    // cout << endl;

    vector<int> monsters(N, 0);
    int monster_count = 0;
    vector<int> postion_ts;

    int ans = 0;
    rep(i, N)
    {
        int j = N - 1 - i;

        switch (ts[j])
        {
        case 1:
            if (monsters[xs[j]] > 0)
            {
                monsters[xs[j]]--;
                monster_count--;
                postion_ts.push_back(1);
            }
            else
            {
                postion_ts.push_back(0);
            }
            // cout << "monster_count:" << monster_count << endl;
            break;
        case 2:
            monsters[xs[j]]++;
            monster_count++;
            // cout << "monster_count:" << monster_count << endl;
            ans = max(ans, monster_count);
            break;
        }
    }

    cout << ans << endl;

    reverse(postion_ts.begin(), postion_ts.end());

    rep(i, postion_ts.size())
    {
        cout << postion_ts[i] << " ";
    }
    cout << endl;

    return 0;
}
