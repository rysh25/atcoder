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

int main()
{
    int N;
    cin >> N;

    vector<ll> A;
    ll a = 1;
    int X = 12;
    rep1(i, X + 1)
    {
        A.push_back(a);
        a = a * 10 + 1;
    }

    // cout << "A:" << endl;
    // rep(i, A.size())
    // {
    //     cout << A[i] << " ";
    // }
    // cout << endl;

    set<ll> s;
    rep(i, X) rep(j, X) rep(k, X)
    {
        // cout << "i:" << i << " j:" << j << " k:" << k << endl;
        ll n = A[i] + A[j] + A[k];
        s.insert(n);
    }

    vector<ll> ans;
    for (auto itr = s.begin(); itr != s.end(); ++itr)
    {
        ans.push_back(*itr);
    }

    sort(ans.begin(), ans.end());

    // cout << "ans:" << endl;
    // rep(i, ans.size())
    // {
    //     cout << ans[i] << endl;
    // }
    // cout << endl;

    cout << ans[N - 1] << endl;

    return 0;
}
