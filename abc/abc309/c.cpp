#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
    int N, K;

    cin >> N >> K;

    vector<int> a(N), b(N);

    for (int i = 0; i < N; i++)
    {
        cin >> a[i] >> b[i];
    }

    int l = -1, r = 1e9 + 1;
    while (abs(r - l) > 1)
    {
        int mid = l + (r - l) / 2;

        ll k = 0;
        // cout << "mid=" << mid << endl;
        for (int i = 0; i < N; i++)
        {
            if (a[i] >= mid)
            {
                k += b[i];
            }
        }

        // cout << "k=" << k << endl;

        if (k <= K)
            r = mid;
        else
            l = mid;
    }

    cout << (r == 0 ? 1 : r) << endl;

    return 0;
}
