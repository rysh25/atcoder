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
    unsigned long long N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }

    // cout << (1UL + K) / 2UL << endl;
    unsigned long long ans = (1UL + K) * K / 2UL;

    // cout << "ans: " << ans << endl;

    int prev = -1;
    sort(A.begin(), A.end());

    rep(i, N)
    {
        // cout << "i: " << i << ", A[i]: " << A[i] << endl;
        if (A[i] > K)
        {
            // cout << "over A[i]: " << A[i] << endl;
            break;
            // continue;
        }
        if (A[i] == prev)
        {
            continue;
        }

        // cout << "A[i]: " << A[i] << endl;

        ans -= (ll)A[i];

        prev = A[i];
    }

    cout << ans << endl;

    return 0;
}
