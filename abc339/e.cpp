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

struct SegmentTree
{
    int n;
    vector<int> tree;

    SegmentTree(int size)
    {
        n = 1;
        while (n < size)
            n *= 2;
        tree.assign(2 * n - 1, 0);
    }

    void update(int x, int val)
    {
        x += n - 1;
        tree[x] = max(tree[x], val);
        while (x > 0)
        {
            x = (x - 1) / 2;
            tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
        }
    }

    int query(int a, int b, int k, int l, int r)
    {
        if (r <= a || b <= l)
            return 0;
        if (a <= l && r <= b)
            return tree[k];
        else
        {
            int vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
            int vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
            return max(vl, vr);
        }
    }

    int query(int a, int b)
    {
        return query(a, b, 0, 0, n);
    }
};

int main()
{
    int N, D;
    cin >> N >> D;

    vector<int> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }

    const int MAX_A = 5 * 1e5;
    SegmentTree seg(MAX_A + 1);
    int ans = 0;

    rep(i, N)
    {
        int l = max(0, A[i] - D);
        int r = A[i] + D + 1;
        int max_length = seg.query(l, r) + 1;
        ans = max(ans, max_length);
        seg.update(A[i], max_length);
    }

    cout << ans << endl;
    return 0;
}
