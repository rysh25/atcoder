#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    int N, M;

    cin >> N >> M;

    vector<vector<int>> g(N, vector<int>());

    for (int i = 0; i < M; i++)
    {
        int U, V;

        cin >> U >> V;

        U--;
        V--;

        g[U].emplace_back(V);
        g[V].emplace_back(U);
    }

    vector<bool> visited(N, false);

    int res = 0;

    function<void(int)> dfs = [&](int v)
    {
        visited[v] = true;
        for (auto e : g[v])
        {
            if (!visited[e])
            {
                dfs(e);
            }
        }
    };

    for (int i = 0; i < N; i++)
    {
        // cout << "i=" << i << endl;
        if (!visited[i])
        {
            dfs(i);
            res++;
        }
    };

    cout << res++ << endl;

    return 0;
}
