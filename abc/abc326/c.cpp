#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
#include <cmath>
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

    map<int, ll> m;
    set<int> s;
    rep(i, N)
    {
        int A;
        cin >> A;
        m[A]++;
        s.insert(A);
    }

    // sort(A.begin(), A.end());

    vector<int> s_vec;
    for (auto p : s)
    {
        s_vec.push_back(p);
    }

    // cout << "m:";
    // for (auto p : m)
    // {
    //     cout << "(" << p.first << ", " << p.second << "), ";
    // }

    // cout << endl;

    // cout << "s_vec:";
    // for (auto p : s_vec)
    // {
    //     cout << p << ", ";
    // }
    // cout << endl;

    int l = 0, r = 0;
    int len = 0;
    ll count = m[s_vec[0]];
    ll ans = count;
    while (r < s_vec.size() - 1)
    {
        // cout << "l=" << l << ", r=" << r << ", len=" << len << ", count=" << count << ", ans=" << ans << endl;
        if (s_vec[r + 1] - s_vec[l] < M)
        {
            r++;
            len = s_vec[r] - s_vec[l];
            count += m[s_vec[r]];
            ans = max(ans, count);
        }
        else
        {
            count -= m[s_vec[l]];
            l++;
            len = s_vec[r] - s_vec[l];
        }
    }

    cout << ans << endl;

    return 0;
}
