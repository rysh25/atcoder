#include <iostream>

using namespace std;

/**
 * @brief 累乗をを求めます。
 *
 * @param a 累乗の底となる数値を指定します。
 * @param n 累乗の指数となる数値を指定します。
 * @return T 累乗をを返します。
 * @details
 * 繰り返し二乗法によって、累乗を計算します。
 *
 * 繰り返し二乗法とは、累乗を計算する際に、
 * 指数を2の累乗の和で表現することで、
 * 累乗の計算を高速化する手法です。
 *
 * 例えば、x^11 を計算する場合、
 * 11 = 2^3 + 2^1 + 2^0 であるため、
 * x^11 = x^(2^3) * x^(2^1) * x^(2^0) と表現できます。
 * このように、指数を2の累乗の和で表現することで、
 * 累乗の計算を高速化することができます。
 *
 * Time complexity: O(log n)
 * Space complexity: O(1)
 */
long long pow(long long a, long long n)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
            res *= a; // 最下位ビットが 1 ならば (2で割り切れなければ) a^(2^i) を掛ける
        a *= a;
        n >>= 1; // n を1bit 左にずらす
    }
    return res;
}

int main()
{
    long long N;
    cin >> N;

    if (pow(2LL, N) == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    if (pow(2LL, N) == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
