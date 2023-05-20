#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> G(N);

    for (int i = 0; i < Q; i++)
    {
        int q;
        cin >> q;

        if (q == 1)
        {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        else
        {
            int v;
            cin >> v;
            G[v].clear();
        }
    }

    return 0;
}
