#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> G(N, vector<int>());

    vector<int> visited(N, 0);

    for (int i = 0; i < N; i++)
    {
        int A;
        cin >> A;
        A--;
        G[i].emplace_back(A);
    }

    auto dfs1 = [&](auto &&dfs, int v) -> int
    {
        // cout << "v = " << v << endl;
        visited[v] = 1;
        for (auto nv : G[v])
        {
            if (visited[nv] == 0)
            {
                // cout << "0: nv = " << nv << endl;
                int ret = dfs(dfs, nv);
                if (ret != -1)
                    return ret;
            }
            else if (visited[nv] == 1)
            {
                // cout << "1: nv = " << nv << endl;
                return nv;
            }
        }
        return -1;
    };

    int loop_v = -1;
    for (int i = 0; i < N; i++)
    {
        if (visited[i] == 0)
        {
            loop_v = dfs1(dfs1, i);
            if (loop_v != -1)
                break;
        }
    }

    // cout << "loop_v = " << loop_v << endl;

    vector<int> path;
    vector<int> visited2(N, 0);
    auto dfs2 = [&](auto &&dfs, int v) -> int
    {
        // cout << "v = " << v << endl;
        visited2[v] = 1;
        path.emplace_back(v);
        for (auto nv : G[v])
        {
            if (visited2[nv] == 0)
            {
                // cout << "0: nv = " << nv << endl;
                if (dfs(dfs, nv))
                    return true;
            }
            else if (visited2[nv] == 1)
            {
                // cout << "1: nv = " << nv << endl;
                return true;
            }
        }
        return -1;
    };

    dfs2(dfs2, loop_v);

    cout << path.size() << endl;

    for (auto v : path)
    {
        cout << v + 1 << " ";
    }
    cout << endl;
    return 0;
}
