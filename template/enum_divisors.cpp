#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief 約数を列挙数します。
 *
 * @tparam T
 * @param n　約数を列挙したい整数を指定します。
 * @return 約数の vector を返します。
 * @details
 * n の約数とは、n を割り切ることのできる整数のことです。
 * たとえば 12 の約数は 1,2,3,4,6,12 の 6 個になります。
 * 5 は、12÷5 が割り切れないので、12 の約数ではありません。
 *
 * Time complexity: O(√n)
 * Space complexity: O(√n)
 */
template <typename T>
vector<T> enum_divisors(T n)
{
    vector<T> res;
    for (T i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (n / i != i)
                res.push_back(n / i);
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    long long N;
    cin >> N;
    const auto &res = enum_divisors(N);
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << " ";
    cout << endl;
}
