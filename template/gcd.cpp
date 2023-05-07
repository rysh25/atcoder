#include <iostream>

using namespace std;

/**
 * @brief 最大公約数 (Greatest Common Divisor: GCD) を求めます。
 *
 * @tparam T 数値の型を指定します。
 * @param a 数値1を指定します。
 * @param b 数値2を指定します。
 * @return T a と b の最大公約数を返します。
 * @details
 * 最大公約数とは a と b の両方を割り切る最大の整数のことです。
 * たとえば 12 と 18 の最大公約数は 4 になります。
 *
 * ユークリッドの互除法を用いて、最大公約数を求めます。
 *
 * ユークリッドの互除法とは、次のようなアルゴリズムです。
 * 1. a と b のうち、大きい方を a、小さい方を b とする。
 * 2. a を b で割った余りを r とする。
 * 3. r が 0 ならば、b が最大公約数である。
 * 4. r が 0 でないならば、a に b を代入し、b に r を代入して 2. に戻る。
 *
 * Time complexity: O(log min(a, b))
 * Space complexity: O(1)
 */
template <typename T>
T gcd(T a, T b)
{
    if (a < b)
        return gcd(b, a);

    if (b == 0)
        return a;

    T r;
    while ((r = a % b))
    {
        a = b;
        b = r;
    }
    return b;
}

int main()
{
    long long A, B;
    cin >> A >> B;

    cout << gcd(A, B);
}
