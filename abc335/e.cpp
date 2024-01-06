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
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }

    vector<vector<int>> G(N, vector<int>());

    rep(i, M)
    {
        int U, V;
        cin >> U >> V;
        U--, V--;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    auto dfs = [&](auto &&f, int v, int p, set<int> &values, vector<bool> &visited) -> int
    {
        if (visited[v])
            return 0;

        visited[v] = true;
        values.insert(A[v]);
        // cout << "v=" << v + 1 << ", A[v]=" << A[v] << ", p=" << p << ", score=" << values.size() << endl;

        if (v + 1 == N)
        {
            // cout << "values:" << endl;
            // for (auto v : values)
            // {
            //     cout << v + 1 << " ";
            // }
            // cout << endl;
            return values.size();
        }

        int score = 0;
        for (auto nv : G[v])
        {
            if (nv == p)
                continue;

            // cout << "nv=" << nv << ", A[nv]=" << A[nv] << endl;

            if (A[v] > A[nv])
                continue;

            set<int> newValues = values;
            vector<bool> newVisited = visited;
            int ret = f(f, nv, v, newValues, newVisited);
            score = max(score, ret);
        }

        return score;
    };

    int ans = 0;
    set<int> values;
    vector<bool> visited(N, false);
    ans = max(ans, dfs(dfs, 0, -1, values, visited));

    // int ans = dfs(dfs, 0, -1, 0);
    cout << ans << endl;

    return 0;
}
