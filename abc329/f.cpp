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

struct UnionFind
{
    vector<int> parent;
    vector<set<int>> colors;

    UnionFind(int n) : parent(n), colors(n)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (colors[x].size() < colors[y].size())
            swap(x, y);
        parent[y] = x;
        for (int color : colors[y])
        {
            colors[x].insert(color);
        }
    }

    int countColors(int x)
    {
        return colors[find(x)].size();
    }
};

int main()
{
    int N, Q;
    cin >> N >> Q;

    vector<int> C(N);
    vector<set<int>> boxOfColor(N, set<int>());
    vector<int> countOfColor(N, 0);

    rep(i, N)
    {
        cin >> C[i];
        C[i]--;
        boxOfColor[C[i]].insert(i);
    }

    for (int i = 0; i < Q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        for (int j : boxOfColor[a])
        {
            boxOfColor[b].insert(j);
        }
    }

    return 0;
}
