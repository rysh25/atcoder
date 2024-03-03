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

struct Node
{
    int max1, max2;
    int count1, count2;

    Node() : max1(INT_MIN), max2(INT_MIN), count1(0), count2(0) {}

    void set(int val)
    {
        max1 = val;
        count1 = 1;
    }

    void merge(const Node &left, const Node &right)
    {
        vector<int> values = {left.max1, right.max1};
        sort(values.begin(), values.end(), greater<int>());
        max1 = values[0];
        max2 = INT_MIN;
        count1 = count2 = 0;

        if (left.max1 == max1)
            count1 += left.count1;
        if (right.max1 == max1)
            count1 += right.count1;

        vector<pair<int, int>> candidates = {{left.max1, left.count1}, {left.max2, left.count2}, {right.max1, right.count1}, {right.max2, right.count2}};
        for (auto &candidate : candidates)
        {
            if (candidate.first > max2 && candidate.first < max1)
            {
                max2 = candidate.first;
                count2 = candidate.second;
            }
            else if (candidate.first == max2)
            {
                count2 += candidate.second;
            }
        }
    }
};

class SegmentTree
{
private:
    vector<Node> tree;
    int n;

    void build(const vector<int> &arr, int node, int start, int end)
    {
        if (start == end)
        {
            tree[node].set(arr[start]);
        }
        else
        {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node].merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int start, int end, int idx, int val)
    {
        if (start == end)
        {
            tree[node].set(val);
        }
        else
        {
            int mid = (start + end) / 2;
            if (idx <= mid)
            {
                update(2 * node, start, mid, idx, val);
            }
            else
            {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node].merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    Node query(int node, int start, int end, int l, int r)
    {
        if (r < start || end < l)
        {
            return Node();
        }
        if (l <= start && end <= r)
        {
            return tree[node];
        }
        int mid = (start + end) / 2;
        Node left = query(2 * node, start, mid, l, r);
        Node right = query(2 * node + 1, mid + 1, end, l, r);
        Node result;
        result.merge(left, right);
        return result;
    }

public:
    SegmentTree(const vector<int> &arr)
    {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void update(int idx, int val)
    {
        update(1, 0, n - 1, idx, val);
    }

    Node query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
};

int main()
{
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    SegmentTree seg(A);

    rep(i, N)
    {
        cin >> A[i];
        seg.update(i, A[i]);
    }

    while (Q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int p, x;
            cin >> p >> x;
            p--;
            seg.update(p, x);
        }
        else if (type == 2)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;

            Node node = seg.query(l, r);
            int count = 0;

            cout << node.count2 << endl;
        }
    }

    return 0;
}
