#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);
    vector<long long> T(N, 0);

    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if (i > 0 && i % 2 == 0)
        {
            sum += A[i] - A[i - 1];
        }
        T[i] = sum;
    }

    // for (int i = 0; i < N; i++)
    // {
    //     cout << "T[" << i << "]=" << T[i] << ", ";
    // }
    // cout << endl;

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        int l, r;
        cin >> l >> r;

        long long ans = 0;

        auto li = lower_bound(A.begin(), A.end(), l);
        auto ri = lower_bound(A.begin(), A.end(), r);

        int lidx = li - A.begin();
        int ridx = ri - A.begin();
        // cout << "lidx=" << lidx << ", ridx=" << ridx << endl;
        if (lidx % 2 == 0)
        {
            // 寝た
            ans = (A[lidx] - l) + (T[ridx - 1] - T[lidx]);
            // cout << "0: ans=" << ans << endl;
            if (ridx % 2 == 0)
            {
                // 寝た
                ans += (r - A[ridx - 1]);
            }
        }
        else
        {
            // 起きた
            ans = T[ridx - 1] - T[lidx];
            // cout << "1: ans=" << ans << endl;
            if (ridx % 2 == 0)
            {
                // 寝た
                ans += (r - A[ridx - 1]);
            }
        }

        cout << ans << endl;
    }

    return 0;
}
