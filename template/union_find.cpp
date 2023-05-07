#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Union-Find 木を構築します。
 *
 * @tparam T Union-Find 木の要素の型を指定します。
 */
template <typename T>
struct UnionFind
{
    vector<T> par, rank, siz;

    // 構造体の初期化
    UnionFind(T n) : par(n, -1), rank(n, 0), siz(n, 1) {}

    /**
     * @brief x を含むグループの根を求めます。
     *
     * @param x　根を求める要素を指定します。
     * @return T　x を含むグループの根を返します。
     * @details
     * x を含むグループの根を求めるには、
     * x から根までの経路に含まれる頂点を順番に調べていき、
     * 根を見つける必要があります。
     *
     * このとき、根を見つけたら、根から x までの経路に含まれる頂点すべての親を根に変更します。
     * これにより、同じグループに属する頂点が同じ根を共有するようになります。
     * この処理を行うことで、根を見つける際に経路を圧縮することができます。
     * この処理を経路圧縮と呼びます。
     *
     * Time complexity: O(α(n)) (α(n) はアッカーマン関数の逆関数)
     * Space complexity: O(1)
     */
    T root(T x)
    {
        if (par[x] == -1)
            return x; // x が根の場合は x を返す
        else
            return par[x] = root(par[x]); // 経路圧縮
    }

    /**
     * @brief x と y が同じグループに属するかどうかを判定します。
     *
     * @param x
     * @param y
     * @return true
     * @return false
     * @details
     * x と y が同じグループに属するかどうかを判定するには、
     * x と y の根が同じかどうかを調べます。
     *
     * Time complexity: O(α(n)) (α(n) はアッカーマン関数の逆関数)
     * Space complexity: O(1)
     */
    bool is_same(T x, T y)
    {
        return root(x) == root(y);
    }

    /**
     * @brief x を含むグループと y を含むグループを併合します。
     *
     * @param x
     * @param y
     * @return true
     * @return false
     * @details
     * x を含むグループと y を含むグループを併合するには、
     * x と y の根を調べ、異なる場合は、x の根を y の根の子として結合します。
     * このとき、x の根が y の根の子となるか、
     * y の根が x の根の子となるかは、
     * 併合前の x と y を含むグループのサイズによって決まります。
     * より具体的には、x を含むグループのサイズが y を含むグループのサイズ以上の場合は、
     * x の根を y の根の子として結合します。
     *
     * これにより木の高さを log n 以下に抑えることができます。
     *
     * Time complexity: O(α(n)) (α(n) はアッカーマン関数の逆関数)
     * Space complexity: O(1)
     */
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
