#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

vector<int> bfs(const vector<vector<int>> &graph, int start)
{
    vector<int> dist(graph.size(), -1);
    dist[start] = 0;
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : graph[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int K;
    cin >> K;
    vector<pair<int, int>> pd_list(K);
    for (int i = 0; i < K; i++)
    {
        cin >> pd_list[i].first >> pd_list[i].second;
        pd_list[i].first--;
    }

    string ans(N, '0');
    for (const auto &pd : pd_list)
    {
        ans[pd.first] = '1';
    }

    for (const auto &pd : pd_list)
    {
        int p = pd.first, d = pd.second;
        vector<int> dist = bfs(graph, p);
        bool flag = false;
        for (int u = 0; u < N; u++)
        {
            if (ans[u] == '1' && dist[u] == d)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    cout << ans << endl;

    return 0;
}
