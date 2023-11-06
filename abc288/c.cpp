#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;

    cin >> N >> M;
    vector<vector<int>> G(N, vector<int>());

    vector<bool> visited(N, false);
    vector<int> visited_timer(N, 0);

    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        A--, B--;
        // cout << "i=" << i << ", A=" << A << ", B=" << B << endl;
        G[A].emplace_back(B);
        G[B].emplace_back(A);
    }

    int count = 0;
    int timer = 1;
    auto dfs = [&](auto dfs, int u, int par) -> void
    {
        visited_timer[u] = timer;
        timer++;
        visited[u] = true;

        for (auto v : G[u])
        {
            if (v == par)
                continue;

            if (visited[v] && visited_timer[v] < visited_timer[u])
            {
                count++;
            }

            if (!visited[v])
            {
                dfs(dfs, v, u);
            }
        }
    };

    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
            dfs(dfs, i, -1);
    }

    // dfs(dfs, 0, -1);

    cout << count << endl;

    return 0;
}
