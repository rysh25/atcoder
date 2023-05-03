#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    int K;
    cin >> K;
    vector<int> p(K), d(K);
    for (int i = 0; i < K; i++)
    {
        cin >> p[i] >> d[i];
        p[i]--;
    }

    int INF = 1e9;
    auto bfs = [&](int sv)
    {
        vector<int> dist(N, INF);
        dist[sv] = 0;
        queue<int> q;
        q.push(sv);
        while (q.size())
        {
            int v = q.front();
            q.pop();
            for (int u : G[v])
            {
                if (dist[u] == INF)
                {
                    dist[u] = dist[v] + 1;
                    q.push(u);
                }
            }
        }
        return dist;
    };

    vector<vector<int>> gs(N);

    for (int i = 0; i < N; i++)
    {
        gs[i] = bfs(i);
    }

    string ans(N, '1');

    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (gs[p[i]][j] < d[i])
                ans[j] = '0';
        }
    }

    for (int i = 0; i < K; i++)
    {
        int now = INF;
        for (int j = 0; j < N; j++)
        {
            if (ans[j] == '1')
                now = min(now, gs[p[i]][j]);
        }

        if (now != d[i])
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    cout << ans << endl;

    return 0;
}
