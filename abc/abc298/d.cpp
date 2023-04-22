#include <iostream>
#include <queue>

using namespace std;

constexpr int MOD = 998244353;

template <typename T>
T fpow(int x, T n, int m)
{
    T ret = 1;
    x %= m;
    while (n > 0)
    {
        if (n & 1)
            ret = (ret * x) % m;
        x = (x * x) % m;
        n >>= 1;
    }
    return ret;
}

int main()
{
    int Q;

    cin >> Q;

    deque<int> S = {1};

    long long sum = 1;

    for (int i = 0; i < Q; i++)
    {
        int q, x;
        cin >> q;

        if (q == 1)
        {
            cin >> x;
            S.push_back(x);

            sum = ((sum * 10) + x) % MOD;
            // cout << "q=" << q << ", sum: " << sum << endl;
        }
        else if (q == 2)
        {
            sum = ((sum - ((S.front() * fpow(10, (int)S.size() - 1, MOD)) % MOD)) % MOD + MOD) % MOD;
            // sum = (sum - (S.front() * fpow(10, S.size() - 1, MOD)) % MOD + MOD) % MOD;
            // cout << "q=" << q << ", sum: " << sum << endl;

            S.pop_front();
        }
        else
        {
            cout << sum % MOD << endl;
        }
    }

    return 0;
}
