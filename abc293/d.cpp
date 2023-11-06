#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N * 2, vector<int>());
    vector<bool> visited(N * 2, false);

    for (int i = 0; i < N; i++)
    {
        G[i * 2].emplace_back(i * 2 + 1);
        G[i * 2 + 1].emplace_back(i * 2);
    }

    for (int i = 0; i < M; i++)
    {
        int a, c;
        char b, d;
        cin >> a >> b >> c >> d;
        a--, c--;

        // cout << "u=" << u << "v=" << v << endl;
        int l = 0, r = 0;
        if (b == 'R')
        {
            l = a * 2;
        }
        else
        {
            l = a * 2 + 1;
        }
        if (d == 'R')
        {
            r = c * 2;
        }
        else
        {
            r = c * 2 + 1;
        }
        G[l].emplace_back(r);
        G[r].emplace_back(l);
    }

    int closed = 0;

    auto dfs = [&](auto dfs, int v, int p, int &n, int &m) -> bool
    {
        visited[v] = true;
        n++;
        m += G[v].size();
        for (int u : G[v])
        {
            // cout << "visited[" << u << "]=" << visited[u] << endl;
            if (u != p)
            {
                if (visited[u])
                {
                    // cout << "visited: " << u + 1 << endl;
                    closed++;
                    return true;
                }
                else
                {
                    // cout << "next: " << u + 1 << endl;
                    if (dfs(dfs, u, v, n, m))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    };

    int count = 0;
    for (int v = 0; v < N * 2; v++)
    {
        if (!visited[v])
        {
            // cout << "v=" << v + 1 << endl;
            count++;
            int vn = 0, vm = 0;
            dfs(dfs, v, -1, vn, vm);
        }
    }

    cout << closed << " " << count - closed << endl;

    return 0;
}
