#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Union-Find
template <typename T>
struct UnionFind
{
    vector<T> par, rank, siz;

    // 構造体の初期化
    UnionFind(T n) : par(n, -1), rank(n, 0), siz(n, 1) {}

    // 根を求める
    T root(T x)
    {
        if (par[x] == -1)
            return x; // x が根の場合は x を返す
        else
            return par[x] = root(par[x]); // 経路圧縮
    }

    // x と y が同じグループに属するか (= 根が一致するか)
    bool issame(T x, T y)
    {
        return root(x) == root(y);
    }

    // x を含むグループと y を含むグループを併合する
    bool unite(T x, T y)
    {
        T rx = root(x), ry = root(y); // x 側と y 側の根を取得する
        if (rx == ry)
            return false; // すでに同じグループのときは何もしない
        // union by rank
        if (rank[rx] < rank[ry])
            swap(rx, ry); // ry 側の rank が小さくなるようにする
        par[ry] = rx;     // ry を rx の子とする
        if (rank[rx] == rank[ry])
            rank[rx]++;     // rx 側の rank を調整する
        siz[rx] += siz[ry]; // rx 側の siz を調整する
        return true;
    }

    // x を含む根付き木のサイズを求める
    T size(T x)
    {
        return siz[root(x)];
    }
};

int main()
{
    int N;
    cin >> N;

    unordered_map<string, string> name;

    for (int i = 0; i < N; i++)
    {
        string s, t;
        cin >> s >> t;
        name[s] = t;
    }

    unordered_map<string, bool> used;

    auto iter = name.begin();
    while (iter != name.end())
    {
        cout << "[" << iter->first << ","
             << iter->second << "]\n";

        if (used[iter->first])
        {
            ++iter;
            continue;
        }

        string next = iter->second;
        while (true)
        {
            auto i = name.find(next);
            if (i == name.end())
            {
                used[iter->first] = true;
                continue;
            }

            next = i->second;
        }

        ++iter;
    }

    return 0;
}
