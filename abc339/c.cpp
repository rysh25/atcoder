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

    vector<int> A(N);
    rep(i, N) cin >> A[i];

    ll count = 0;
    ll INF = 1e18 + 1;
    ll mn = INF;
    rep(i, N)
    {
        count += (ll)A[i];
        mn = min(mn, count);
    }

    // cout << "count: " << count << endl; // debug
    // cout << "mn: " << mn << endl;       // debug

    if (mn < 0)
    {
        cout << count - mn << endl;
    }
    else
    {
        cout << count << endl;
    }

    return 0;
}
