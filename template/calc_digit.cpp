#include <iostream>
using namespace std;

/// @brief 与えられた数値の桁数を計算します。
/// @tparam T
/// @param N
/// @return
template <typename T>
int calc_digit(T N)
{
    int res = 0;
    while (N)
    {
        ++res;
        N /= 10;
    }
    return res;
}
