#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N, vector<int>());
    vector<bool> visited(N, false);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        // cout << "u=" << u << "v=" << v << endl;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    // for (int i = 0; i < M; i++)
    // {
    //     cout << "G[" << i + 1 << "]=" << G[i].size() << endl;

    //     for (int u : G[i])
    //     {
    //         cout << "u=" << u << endl;
    //     }
    // }

    auto dfs = [&](auto dfs, int v, int &n, int &m) -> void
    {
        // cout << "G[" << v << "]=" << G[v].size() << endl;
        visited[v] = true;
        n++;
        m += G[v].size();
        for (int u : G[v])
        {
            // cout << "visited[" << u << "]=" << visited[u] << endl;
            if (!visited[u])
            {
                dfs(dfs, u, n, m);
            }
        }
    };

    auto is_valid = [](int n, int m)
    {
        return n * 2 == m;
    };

    bool is_valid_graph = true;
    for (int v = 0; v < N; v++)
    {
        if (!visited[v])
        {
            int vn = 0, vm = 0;
            dfs(dfs, v, vn, vm);

            // cout << "v=" << v + 1 << ", vn=" << vn << ", vm=" << vm << endl;
            if (!is_valid(vn, vm))
            {
                is_valid_graph = false;
                break;
            }
        }
    }

    cout << (is_valid_graph ? "Yes" : "No") << endl;

    return 0;
}
