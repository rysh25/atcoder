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

    vector<ll> A(N);

    rep(i, N)
    {
        cin >> A[i];
    }

    vector<ll> S(N - 1), T(N - 1);

    rep(i, N - 1)
    {
        cin >> S[i] >> T[i];
    }

    rep(i, N - 1)
    {
        if (A[i] >= S[i])
        {
            ll x = A[i] / S[i];
            // cout << "i=" << i << " x=" << x << endl;
            A[i] -= S[i] * x;
            A[i + 1] += T[i] * x;
        }
    }

    cout << A[N - 1] << endl;

    return 0;
}
