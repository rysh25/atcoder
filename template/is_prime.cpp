#include <iostream>

using namespace std;

/**
 * @brief 与えられた数値が素数かどうかを判定します。
 *
 * @tparam T 判定する数値の型を指定します。
 * @param n 判定する対象の数値を指定します。
 * @return true n が素数の場合
 * @return false n が素数でない場合
 * @details
 * n が素数であるための必要十分条件は、n が 1 でない自然数であり、
 * n を割り切る最小の素数が n そのものであることです。
 * この関数は、この条件を満たすかどうかを判定します。
 *
 * n で素数であるかどうかは、n が √n 以下の素数で割り切れるかどうかを調べることで判定できます。
 * なぜ √n 以下であるかというと、n が √n より大きい素数で割り切れる場合、
 * その商は √n より小さい素数ですでに割り切れていることになるからです。
 *
 * Time complexity: O(√n)
 * Space complexity: O(1)
 */
template <typename T>
bool is_prime(T n)
{
    if (n == 1)
        return false;
    for (T i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    long long N;
    cin >> N;
    if (is_prime(N))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
