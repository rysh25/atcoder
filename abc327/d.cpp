#include <iostream>
#include <iomanip>
#include <sstream>
#include <list>
#include <utility>
#include <string>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <climits>
#include <cstring>
// #include <cstdlib>
#include <limits>
#include <algorithm>
#include <functional>
#include <vector>
#include <tuple>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> A(M), B(M);
    rep(i, M)
    {
        cin >> A[i];
        A[i]--;
    }
    rep(i, M)
    {
        cin >> B[i];
        B[i]--;
    }

    vector<vector<int>> G(N, vector<int>());

    for (int i = 0; i < M; i++)
    {
        // cout << "A[i]=" << A[i] << ", B[i]=" << B[i] << endl;
        G[A[i]].emplace_back(B[i]);
        G[B[i]].emplace_back(A[i]);
    }

    // cout << "G:" << endl;
    // rep(i, N)
    // {
    //     cout << i + 1 << ": ";
    //     for (auto v : G[i])
    //     {
    //         cout << v + 1 << " ";
    //     }
    //     cout << endl;
    // }

    vector<int> color(N, -1); // color[v]：頂点 v の色が黒なら 1, 白なら 0, 未探索なら -1
    string ans = "Yes";
    for (int v = 0; v < N; ++v)
    {
        if (color[v] != -1)
        {
            continue;
        }
        queue<int> que;
        color[v] = 0;
        que.push(v);
        while (que.size() > 0)
        {
            int qv = que.front();
            que.pop();
            for (auto nv : G[qv])
            {
                if (color[nv] != -1)
                {
                    if (color[nv] == color[qv])
                    {
                        ans = "No";
                    }
                    continue;
                }
                color[nv] = 1 - color[qv];
                que.push(nv);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
