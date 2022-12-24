#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N, M;

    cin >> N >> M;

    vector<vector<int>> G(N, vector<int>());

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
        // cout << "G[" << i << "]=" << endl;
    }

    vector<int> color(N, -1);

    for (int v = 0; v < N; v++)
    {
        // cout << "v=" << v << endl;
        if (color[v] != -1)
        {
            continue;
        }

        queue<int> que;
        color[v] = 0; // color[v]：頂点 v の色が黒なら 1, 白なら 0, 未探索なら -1
        que.push(v);

        int ans = 0;
        while (que.size() > 0)
        {
            int qv = que.front();
            que.pop();
            for (auto nv : G[qv])
            {
                if (color[nv] != -1)
                {
                    // 隣り合う頂点どうしが同じ色なら
                    if (color[nv] == color[qv])
                    {
                        cout << 0 << endl;
                        return 0;
                    }
                    continue;
                }
                // そうでなければ、頂点 nv の色を color[qv] と逆にしたうえで、nv も探索候補に入れる
                color[nv] = 1 - color[qv];
                que.push(nv);
            }
        }
    }

    int black = 0;
    int white = 0;
    for (int v = 0; v < N; ++v)
    {
        if (color[v] == 0)
        {
            white++;
        }
        else if (color[v] == 1)
        {
            black++;
        }
    }

    int m = white * black;

    cout << m - M << endl;

    return 0;
}
