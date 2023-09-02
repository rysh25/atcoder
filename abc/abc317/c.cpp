#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

struct Edge
{
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

bool compareEdge(const Edge &e1, const Edge &e2)
{
    return e1.weight < e2.weight;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<Edge>> G(N);
    vector<bool> visited(N, false);

    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        A--, B--;

        G[A].push_back(Edge(B, C));
        G[B].push_back(Edge(A, C));
    }

    auto dfs = [&](auto &&dfs, int v, int sum) -> int
    {
        visited[v] = true;
        int max_sum = sum;
        for (auto e : G[v])
        {
            if (e.to == v)
                continue;
            if (!visited[e.to])
            {
                max_sum = max(max_sum, dfs(dfs, e.to, sum + e.weight));
            }
        }

        visited[v] = false;
        return max_sum;
    };

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans = max(ans, dfs(dfs, i, 0));
    }

    cout << ans << endl;

    return 0;
}
