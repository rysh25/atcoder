#include <iostream>

using namespace std;

/**
 * @brief 組み合わせの数 (Combination) （nCr) を計算します。
 *
 * @tparam T 組み合わせの対象となる数値の型を指定します。
 * @param n 組み合わせの対象となる数値を指定します。
 * @param r 組み合わせの選択数を指定します。
 * @return T 組み合わせの数を返します。
 * @details
 * 組み合わせの数は、nCr = n! / (r! * (n - r)!) で求めることができます。
 * この式は、n! がオーバーフローする可能性があるため、
 * 以下のように式変形して計算します。
 * nCr = n * (n - 1) * ... * (n - r + 1) / r!
 * この式変形により、オーバーフローを軽減することができます。
 *
 *  Time complexity: O(r)
 *  Space complexity: O(1)
 */
template <typename T>
T combination(T n, T r)
{
    T res = 1;
    r = min(n - r, r);
    for (T i = 1; i <= r; ++i)
    {
        res *= n - i + 1;
        res /= i;
    }
    return res;
}

/**
 * @brief 組み合わせの数 (Combination) （nCr) の mod p を計算します。
 *
 * @tparam T 組み合わせの対象となる数値の型を指定します。
 * @param n 組み合わせの対象となる数値を指定します。
 * @param r 組み合わせの選択数を指定します。
 * @param p 組み合わせの計算に使用する素数を指定します。
 * @return T 組み合わせの数を返します。
 * @details
 * 組み合わせの数は、nCr = n! / (r! * (n - r)!) で求めることができます。
 * この式は、n! がオーバーフローする可能性があるため、
 * 以下のように式変形して計算します。
 * nCr = n * (n - 1) * ... * (n - r + 1) / r!
 * この式変形により、オーバーフローを軽減することができます。
 *
 * また、計算途中で剰余を取ることで、オーバーフローを防ぐことができます。
 */
template <typename T>
T mod_combination(T n, T r, const T &p)
{
    T res = 1;
    r = min(n - r, r);
    for (T i = 1; i <= r; ++i)
    {
        res *= n - i + 1;
        res %= p;
        res *= mod_pow(i, p - 2, p);
        res %= p;
    }
    return res;
}

int main()
{
    int n, r;
    cin >> n >> r;

    cout << combination(n, r) << endl;

    return 0;
}
