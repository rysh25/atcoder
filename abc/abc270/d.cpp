// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    int N, K;

    cin >> N >> K;
    vector<int> A(K);

    for (int i = 0; i < K; i++)
    {
        cin >> A[i];
    }

    int j = K - 1;
    int res = 0;
    for (int i = 0; N >= 0; i++)
    {
        // cout << "N=" << N << endl;
    L1:
        if (j < 0)
        {
            break;
        }

        if (A[j] <= N)
        {
            // cout << "A[j]=" << A[j] << endl;
            N -= A[j];

            if (i % 2 == 0)
            {
                res += A[j];
            }
        }
        else
        {
            j--;
            goto L1;
        }
    }

    cout << res << endl;

    return 0;
}
