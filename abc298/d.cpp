#include <iostream>
#include <queue>

using namespace std;

constexpr int MOD = 998244353;

long long fpow(long long x, long long n, long long m)
{
    long long ret = 1;
    x = x % m;
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

    bool debug = false;
    for (int i = 0; i < Q; i++)
    {
        int q, x;
        cin >> q;

        if (q == 1)
        {
            cin >> x;

            S.push_back(x);

            sum = (((sum * 10) + x) % MOD + MOD) % MOD;
            // cout << "q=" << q << ", sum: " << sum << endl;
        }
        else if (q == 2)
        {
            int x = S.front();
            S.pop_front();
            int size = S.size();
            sum = ((sum - (fpow(10, size, MOD) * x % MOD)) % MOD + MOD) % MOD;
            // sum = (sum - (S.front() * fpow(10, S.size() - 1, MOD)) % MOD + MOD) % MOD;
            // cout << "q=" << q << ", sum: " << sum << endl;
        }
        else
        {
            cout << sum % MOD << endl;
        }
    }

    return 0;
}
