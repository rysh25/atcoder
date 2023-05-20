#include <iostream>
#include <vector>

using namespace std;

long long pow(long long a, long long n)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
            res *= a;
        a *= a;
        n >>= 1; // n を1bit 左にずらす
    }
    return res;
}

int main()
{
    string S;
    long long N;
    cin >> S >> N;

    long long a = pow(2, S.size() - 1);
    long long ans = 0;

    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '1')
        {
            // cout << "a=" << a << ", ans=" << ans << endl;
            ans += a;
        }

        a >>= 1;
    }

    a = pow(2, S.size() - 1);

    for (int i = 0; i < S.size(); i++)
    {
        // cout << "a=" << a << ", ans=" << ans << endl;
        if (S[i] == '?')
        {
            if (N >= ans + a)
            {
                ans += a;
            }
        }

        a >>= 1;
    }

    if (ans > N)
    {
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;

    return 0;
}
