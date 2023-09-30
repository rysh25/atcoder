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
    long long N, M, P;
    cin >> N >> M >> P;

    vector<long long> A(N), B(M), SUMB(M + 1);

    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    // cout << "A: ";
    // rep(i, N) cout << A[i] << " ";
    // cout << endl;
    // cout << "B: ";
    // rep(i, M) cout << B[i] << " ";
    // cout << endl;

    SUMB[0] = 0;
    for (int i = 0; i < M; ++i)
    {
        SUMB[i + 1] = B[i] + SUMB[i];
    }

    // rep(i, M + 1) cout << SUMB[i] << " ";
    // cout << endl;

    long long ans = 0;
    for (int i = 0; i < N; ++i)
    {
        // cout << "i=" << i << ", A[i]=" << A[i] << ", P-A[i]=" << P - A[i] << endl;
        auto it = upper_bound(B.begin(), B.end(), P - A[i]);
        int j = it - B.begin();
        if (j < M)
        {
            // cout << "j=" << j << ", B[j]=" << B[j] << ", SUMB=" << SUMB[j] << endl;
            ans += (A[i] * j) + SUMB[j];
            // cout << "(M - j) * P=" << (M - j) * P << endl;
            ans += (M - j) * P;
        }
        else
        {
            ans += (A[i] * j) + SUMB[j];
        }
    }

    cout << ans << endl;

    return 0;
}
