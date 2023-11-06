#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

int main()
{
    int N, X;
    cin >> N >> X;

    vector<int> A(N - 1);
    rep(i, N - 1) cin >> A[i];

    sort(A.begin(), A.end());
    int sum = 0;
    for (int i = 1; i < N - 1; ++i)
    {
        sum += A[i];
    }

    for (int i = 0; i <= 100; ++i)
    {
        vector<int> B(N - 1);
        rep(j, N - 1) B[j] = A[j];
        B.push_back(i);
        sort(B.begin(), B.end());
        sum = 0;
        for (int i = 1; i < N - 1; ++i)
        {
            sum += B[i];
        }

        if (sum >= X)
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
