#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

vector<ll> calc_a(int N)
{
    vector<ll> a(N, 0);
    for (int i = 1; i < N; ++i)
    {
        a[i] = 1LL * N * i / (N - i);
    }
    return a;
}

int count_pairs(int N)
{
    int count = 0;
    auto a = calc_a(N);
    for (int D = 1; D < N; ++D)
    {
        for (int C = D + 1; C < N; ++C)
        {
            ll minB = max((ll)N - C * D - 1, (ll)1);
            ll maxB = (ll)C - 1;
            if (minB <= maxB)
            {
                auto it1 = lower_bound(a.begin(), a.end(), minB);
                auto it2 = upper_bound(a.begin(), a.end(), maxB);
                count += distance(it1, it2);
            }
        }
    }
    return count;
}

int main()
{
    int N;

    cin >> N;

    cout << count_pairs(N) << endl;

    return 0;
}
