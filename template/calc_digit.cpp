#include <iostream>
using namespace std;

/**
 * @brief 与えられた数値の桁数を計算します。
 *
 * @param n 桁数を計算する対象の数値を指定します。
 * @return int n の桁数を返します。
 * @details
 * 桁数は、n が 0 になるまでの割り続け、
 * 割り算を行った回数を数えれば求めることができます。
 *
 * Time complexity: O(log n)
 * Space complexity: O(1)
 */
template <typename T>
int calc_digit(T n)
{
    int res = 0;
    while (n)
    {
        ++res;
        n /= 10;
    }
    return res;
}
