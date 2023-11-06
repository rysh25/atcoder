#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;

    vector<unordered_set<int>> G(N);

    int ans = N;

    for (int i = 0; i < Q; i++)
    {
        int q;
        cin >> q;

        if (q == 1)
        {
            int u, v;
            cin >> u >> v;

            u--, v--;

            // cout << "u=" << u << ", v=" << v << endl;

            if (G[u].size() == 0)
                ans--;
            if (G[v].size() == 0)
                ans--;

            G[u].insert(v);
            G[v].insert(u);
        }
        else
        {
            int v;
            cin >> v;

            v--;

            if (G[v].size() != 0)
            {
                for (int u : G[v])
                {
                    G[u].erase(v);
                    if (G[u].size() == 0)
                        ans++;
                }
                G[v].clear();
                ans++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
