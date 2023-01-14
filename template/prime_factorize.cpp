#include <iostream>
#include <vector>
#include <utility>

using namespace std;

/// @brief 素因数分解します。
/// @tparam T
/// @param n
/// @return
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

int main()
{
    long long N;
    cin >> N;
    const auto &res = prime_factorize(N);
    cout << N << ":";
    for (auto p : res)
    {
        for (int i = 0; i < p.second; ++i)
            cout << " " << p.first;
    }
    cout << endl;
}
