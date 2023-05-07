#include <iostream>

using namespace std;

/**
 * @brief 最小公倍数 (Least Common Multiple: LCM) を求めます。
 *
 * @tparam T 数値の型を指定します。
 * @param a 数値1を指定します。
 * @param b 数値2を指定します。
 * @return T a と b の最小公倍数を返します。
 * @example
 *
 * @details
 * 最小公倍数とは、a と b の両方で割り切れる最小の整数のことです。
 * 4 と 6 の最小公倍数は 12 で、4 と 6 の公倍数の中で最小の整数です。
 *
 * 最小公倍数は、最大公約数を用いて求めることができます。
 * a * b = 最大公約数 * 最小公倍数 であるため、
 * a * b ÷ 最大公約数 が最小公倍数になります。
 *
 * Time complexity: O(log min(a, b))
 * Space complexity: O(1)
 */
template <typename T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }

int main()
{
    long long A, B;
    cin >> A >> B;

    cout << lcm(A, B);
}
