#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, L, K;

    cin >> N >> L >> K;

    vector<int> A(N);

    for (auto &a : A)
    {
        cin >> a;
    }

    int l = -1;
    int r = 1e9 + 1;

    int min_l = K + 1;
    while (r - l > 1)
    {
        int mid = l + (r - l) / 2;
        // cout << "l=" << l << ", r=" << r << ", r - l=" << r - l << ", mid=" << mid << endl;

        int k = 0;
        int prev = 0;
        for (int i = 0; i < N; i++)
        {
            if (A[i] - prev >= mid && L - A[i] >= mid)
            {
                prev = A[i];
                k++;
            }
        }
        // cout << "k=" << k << ", K+1=" << K + 1 << endl;

        if (k >= K)
            l = mid;
        else
            r = mid;
    }

    cout << l << endl;

    return 0;
}
