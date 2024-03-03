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

struct edge
{
    ll from;
    ll to;
    ll leng;
};

int main()
{
    int N;

    cin >> N;
    vector<vector<edge>> edges(N);

    rep(i, N - 1)
    {
        ll A, B, X;
        cin >> A >> B >> X;
        X--;
        edge e1 = {i, i + 1, A};
        edge e2 = {i, X, B};

        edges[i].push_back(e1);
        edges[i].push_back(e2);
    }

    // cout << "edges: " << endl;
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < edges[i].size(); j++)
    //     {
    //         cout << edges[i][j].from << " " << edges[i][j].to << " " << edges[i][j].leng << endl;
    //     }
    // }

    auto dijkstra = [&](ll start, vector<vector<edge>> &edges)
    {
        vector<ll> dist(N, LLONG_MAX);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
        que.push({0, start});
        dist[start] = 0;

        while (!que.empty())
        {
            auto p = que.top();
            que.pop();
            ll v = p.second;
            if (dist[v] < p.first)
                continue;
            for (auto e : edges[v])
            {
                if (dist[e.to] > dist[v] + e.leng)
                {
                    dist[e.to] = dist[v] + e.leng;
                    que.push({dist[e.to], e.to});
                }
            }
        }
        return dist;
    };

    vector<ll> dist1 = dijkstra(0, edges);

    cout << dist1[N - 1] << endl;

    return 0;
}
