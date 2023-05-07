#include <iostream>
#include <vector>
#include <utility>

using namespace std;

/**
 * @brief 試しわり法を用いて、素因数分解します。
 *
 * @param n 素因数分解する数値を指定します。
 * @return vector<pair<T, T>> pair (素因子, 指数) の vector として素因数分解の結果を返します。
 * @details
 * 試しわり法を用いて、n に指定された数値を素因数分解します。
 *
 * 例えば 12 が指定された場合、 12 = 2^2 * 3^1
 * となるように、pair (素因子, 指数) の vector を返します。
 *
 *　2 から √n までの数で割っていき、割り切れたら素因数として追加します。
 * √n 以上の素因数は存在しないため、素因数が √n 以上になったら終了します。
 *
 * Time complexity: O(√n)
 * Space complexity: O(√n)
 */
template <typename T>
vector<pair<T, T>> prime_factorize(T n)
{
    vector<pair<T, T>> ret;
    for (T i = 2; i * i <= n; i++)
    {
        if (n % i != 0)
            continue;
        T count = 0;
        while (n % i == 0)
        {
            count++;
            n /= i;
        }
        ret.emplace_back(i, count);
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
    cout << N << ": ";
    for (auto p : res)
    {
        for (int i = 0; i < p.second; ++i)
            cout << " " << p.first;
    }
    cout << endl;
}
