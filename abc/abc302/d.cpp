#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long N, M, D;

    cin >> N >> M >> D;

    vector<long long> A(N);
    vector<long long> B(M);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < M; i++)
    {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    auto bin_search = [&](long long h)
    {
        int ok = M;
        int ng = -1;

        while (abs(ok - ng) > 1)
        {
            int mid = ng + (ok - ng) / 2;
            if (B[mid] > h)
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }

        return ok;
    };

    long long ans = -1;
    for (int i = 0; i < N; i++)
    {
        // cout << "A[" << i << "]=" << A[i] << endl;

        int idx = bin_search(A[i] + D);
        // cout << "idx=" << idx << endl;
        if (idx < 1)
        {
            continue;
        }
        // cout << "B[" << idx - 1 << "]=" << B[idx - 1] << ", abs(B[idx] - A[i])=" << abs(B[idx - 1] - A[i]) << ",  A[i] + B[idx]=" << A[i] + B[idx - 1] << endl;
        if (abs(B[idx - 1] - A[i]) <= D)
        {
            ans = max(ans, A[i] + B[idx - 1]);
        }
    }

    cout << ans << endl;

    return 0;
}
