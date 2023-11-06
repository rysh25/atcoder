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
    constexpr ll INF = (1LL << 60);

    int N, A, B, C;
    cin >> N >> A >> B >> C;

    vector<vector<int>> D(N, vector<int>(N));

    rep(i, N)
    {
        rep(j, N)
        {
            cin >> D[i][j];
        }
    }

    // cout << "D: " << endl;
    // rep(i, N)
    // {
    //     rep(j, N)
    //     {
    //         cout << D[i][j] << ", ";
    //     }
    //     cout << endl;
    // }

    const auto dijkstra = [&](int sv, ll mul, ll add)
    {
        std::vector<ll> dist(N, INF);
        vector<bool> used(N, false);

        dist[sv] = 0;

        // cout << "dist: ";
        // for (auto d : dist)
        // {
        //     cout << d << ", ";
        // }
        // cout << endl;

        // cout << "used: ";
        // for (auto d : used)
        // {
        //     cout << d << ", ";
        // }
        // cout << endl;

        rep(ne, N)
        {
            // cout << "ne: " << ne << endl;
            pair<ll, int> minv = make_pair(INF, 0);
            rep(i, N)
            {
                if (used[i])
                    continue;
                minv = min(minv, make_pair(dist[i], i));
            }
            used[minv.second] = true;

            // cout << "used: ";
            // for (auto d : used)
            // {
            //     cout << d << ", ";
            // }
            // cout << endl;
            // cout << "minv: " << minv.first << ", " << minv.second << endl;
            rep(i, N)
            {
                dist[i] = min(dist[i], dist[minv.second] + D[minv.second][i] * mul + add);
            }
        }

        return dist;
    };

    auto dist1 = dijkstra(0, A, 0);
    auto dist2 = dijkstra(N - 1, B, C);

    // cout << "dist1: ";
    // for (auto d : dist1)
    // {
    //     cout << d << ", ";
    // }
    // cout << endl;

    // cout << "dist2: ";
    // for (auto d : dist2)
    // {
    //     cout << d << ", ";
    // }
    // cout << endl;

    ll ans = INF;
    rep(i, N)
    {
        ans = min(ans, dist1[i] + dist2[i]);
    }

    cout << ans << endl;

    return 0;
}
