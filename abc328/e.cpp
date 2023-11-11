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
#include <stack>
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

using namespace std;

// 辺情報を表す構造体
struct edge
{
    ll from; // 辺の始点
    ll to;   // 辺の終点
    ll leng; // 辺の重み
};

// 構造体 edge の比較関数
bool comp(const edge &e, const edge &f)
{
    return e.leng < f.leng;
}

// Union-Find
struct UnionFind
{
    vector<ll> par, siz;

    // 構造体の初期化
    UnionFind(ll n) : par(n), siz(n, 1)
    {
        for (ll i = 0; i < n; ++i)
        {
            par[i] = i;
        }
    }

    // 根を求める
    ll root(ll x)
    {
        if (par[x] == x)
        {
            return x;
        }
        return par[x] = root(par[x]);
    }

    // x と y が同じグループに属するか (= 根が一致するか)
    bool issame(ll x, ll y)
    {
        return root(x) == root(y);
    }

    // x を含むグループと y を含むグループを併合する
    bool unite(ll x, ll y)
    {
        ll rx = root(x), ry = root(y); // x 側と y 側の根を取得する
        if (rx == ry)
            return false; // すでに同じグループのときは何もしない
        // union by size
        if (siz[rx] < siz[ry])
            swap(rx, ry);   // ry 側の siz が小さくなるようにする
        par[ry] = rx;       // ry を rx の子とする
        siz[rx] += siz[ry]; // rx 側の siz を調整する
        return true;
    }

    // x を含む根付き木のサイズを求める
    ll size(ll x)
    {
        return siz[root(x)];
    }
};

int main()
{
    ll N, M, K;
    cin >> N >> M >> K;

    vector<edge> graph_edges(M);

    for (ll i = 0; i < M; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        // cout << "u=" << u << ", v=" << v << ", w=" << w % K << endl;
        graph_edges[i] = edge{u, v, w % K};
    }

    sort(graph_edges.begin(), graph_edges.end(), comp);
    UnionFind uf(N);

    ll ans = 0;
    for (ll i = 0; i < M; ++i)
    {
        auto [u, v, w] = graph_edges[i];

        if (uf.issame(u, v))
        {
            continue;
        }
        uf.unite(u, v);
        ans += w % K;
    }

    cout << ans % K << endl;

    return 0;
}
