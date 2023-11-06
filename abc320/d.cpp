#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

struct Edge
{
    int to;
    pair<ll, ll> pos;
};

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<Edge>> G(N);

    for (int i = 0; i < M; i++)
    {
        int A, B, X, Y;

        cin >> A >> B >> X >> Y;
        A--, B--;

        G[A].push_back({B, {X, Y}});
        G[B].push_back({A, {-X, -Y}});
    }

    ll INF = 1e18 + 7;

    vector<pair<ll, ll>> pos(N, {-INF, -INF});

    vector<bool> visited(N, 0);

    auto dfs = [&](auto &&f, int v) -> void
    {
        // cout << "v: " << v << endl;
        visited[v] = true;
        for (auto e : G[v])
        {
            // cout << "e.to: " << e.to << endl;
            if (visited[e.to])
                continue;

            pos[e.to] = make_pair(pos[v].first + e.pos.first, pos[v].second + e.pos.second);
            // cout << "pos[v]: " << pos[v].first << " " << pos[v].second << endl;
            f(f, e.to);
        }
    };

    pos[0] = {0, 0};
    dfs(dfs, 0);

    for (int i = 0; i < N; i++)
    {
        // cout << "i: " << i << " ";

        if (pos[i].first == -INF || pos[i].second == -INF)
            cout << "undecidable" << endl;
        else
            cout << pos[i].first << " " << pos[i].second << '\n';
    }

    return 0;
}
