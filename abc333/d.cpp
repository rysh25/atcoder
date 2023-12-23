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

    vector<vector<int>> G(N, vector<int>());
    rep(i, N - 1)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<bool> seen(N, 0);

    auto dfs = [&](auto &&f, int v, int p) -> int
    {
        // cout << "v=" << v << ", p=" << p << endl;
        seen[v] = true;
        int res = 0;
        for (auto nv : G[v])
        {
            if (nv == p)
                continue;
            if (seen[nv])
                continue;
            res += f(f, nv, v);
        }

        return res + 1;
    };

    if (G[0].size() == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    vector<int> order;

    for (auto nv : G[0])
    {
        // cout << "nv: " << nv << endl;
        seen.assign(N, 0);
        int a = dfs(dfs, nv, 0);

        order.push_back(a);
    }

    sort(order.begin(), order.end());

    int ans = 1;

    rep(i, order.size() - 1)
    {
        // cout << "order[" << i << "]=" << order[i] << endl;
        ans += order[i];
    }

    cout << ans << endl;

    return 0;
}
