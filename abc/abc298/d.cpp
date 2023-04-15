#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int Q;

    cin >> Q;

    int MOD = 998244353;
    deque<int> S = {1};

    long long current_sum = 1;
    long long base = 1;

    for (int i = 0; i < Q; i++)
    {
        int q, x;
        cin >> q;

        if (q == 1)
        {
            cin >> x;
            S.push_back(x);
            base = (base * 10) % MOD;
            current_sum = (current_sum * 10 + x * base) % MOD;
        }
        else if (q == 2)
        {
            int removed = S.front();
            S.pop_front();
            current_sum = (current_sum - removed * base + MOD) % MOD;
            base = (base * (MOD + 1) / 10) % MOD;
        }
        else
        {
            cout << current_sum << endl;
        }
    }

    return 0;
}
