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

    vector<int> left(N, 1);
    for (int i = 1; i < N; ++i)
    {
        if (A[i] > left[i - 1])
        {
            left[i] = left[i - 1] + 1;
        }
        else
        {
            left[i] = A[i];
        }
    }

    // cout << "left: ";
    // rep(i, N) cout << left[i] << " ";
    // cout << endl;

    vector<int> right(N, 1);
    for (int i = N - 2; i >= 0; --i)
    {
        if (A[i] > right[i + 1])
        {
            right[i] = right[i + 1] + 1;
        }
        else
        {
            right[i] = A[i];
        }
    }

    // cout << "right: ";
    // rep(i, N) cout << right[i] << " ";
    // cout << endl;

    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        int size = min(left[i], right[i]);
        ans = max(ans, size);
    }

    cout << ans << endl;

    return 0;
}
