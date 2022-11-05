#include <iostream>
#include <vector>

using namespace std;

template <typename T>
vector<pair<T, T>> prime_factorize(T n)
{
    vector<pair<T, T>> ret;
    for (T i = 2; i * i <= n; i++)
    {
        if (n % i != 0)
            continue;
        T tmp = 0;
        while (n % i == 0)
        {
            tmp++;
            n /= i;
        }
        ret.emplace_back(i, tmp);
    }
    if (n != 1)
        ret.emplace_back(n, 1);
    return ret;
}

template <typename T>
T gcd(T x, T y) { return (x % y) ? gcd(y, x % y) : y; }

int main()
{
    int N;

    cin >> N;

    vector<int> a(N);

    int x;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        int b = a[i];
        x = gcd(x, b);
    }

    // cout << x << endl;

    if (x > 1)
    {
        for (int i = 0; i < N; i++)
        {
            a[i] = a[i] / x;
        }
    }

    int res = 0;
    for (int i = 0; i < N; i++)
    {
        // cout << a[i] << ": ";
        const auto &pf = prime_factorize(a[i]);

        for (auto &p : pf)
        {
            // cout << p.first << "^" << p.second << " ";

            if (p.first != 2 && p.first != 3)
            {
                cout << -1 << endl;
                return 0;
            }

            res += p.second;
        }

        // cout << endl;
    }

    cout << res << endl;

    return 0;
}
