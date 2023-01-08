#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

// n以下の整数について最小の素因数を求めた結果の配列を返す
// min_factor[i]はiを割り切る最小の数（iの素因数のうち最小のもの）
// min_factor[i] == iならiは素数（i=0, 1のときを除く）
std::vector<long long> sieve(long long n)
{
    // 素数候補を管理する配列
    std::vector<long long> min_factor(n + 1);
    // 2以上の数を一度素数候補に入れる
    for (long long i = 0; i <= n; i++)
        min_factor[i] = i;
    // それぞれの数について最小の素因数を求める
    for (long long i = 2; i * i <= n; i++)
    {
        if (min_factor[i] == i)
        {
            for (long long j = 2; i * j <= n; j++)
            {
                if (min_factor[i * j] > i)
                {
                    min_factor[i * j] = i;
                }
            }
        }
    }
    return min_factor;
}

// 配列min_factorを使ってmを素因数分解する
// 配列ansにはmの素因数が小さい順に格納される
map<long long, long long> factor(std::vector<long long> &min_factor, long long m)
{
    map<long long, long long> ans;
    while (m > 1)
    {
        auto p = min_factor[m];
        if (ans.count(p))
        {
            ans[p]++;
        }
        else
        {
            ans[p] = 1;
        }
        m /= min_factor[m];
    }
    return ans;
}

int main()
{
    int T;
    cin >> T;
    vector<long long> N(T);

    for (int i = 0; i < T; i++)
    {
        cin >> N[i];
    }

    int m = *max_element(N.begin(), N.end());

    vector<long long> min_factor = sieve(sqrt(m));

    for (int i = 0; i < T; i++)
    {
        auto pf = factor(min_factor, N[i]);

        vector<long long> ans(2);
        for (const auto &[k, v] : pf)
        {
            if (v == 2)
            {
                ans[0] = k;
            }
            else
            {
                ans[1] = k;
            }
        }

        cout << ans[0] << " " << pf[1] << endl;
    }

    return 0;
}
