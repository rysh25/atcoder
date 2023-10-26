#include <iostream>
#include <iomanip>
#include <sstream>
#include <list>
#include <utility>
#include <string>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <limits>
#include <algorithm>
#include <functional>
#include <vector>
#include <tuple>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

int get_digit(int num)
{
    int digit = 0;
    while (num != 0)
    {
        num /= 10;
        digit++;
    }
    return digit;
}

int main()
{
    int N;
    cin >> N;

    ll ans = 0;
    int digit = get_digit(N);
    for (int bit = 0; bit < (1 << digit); bit++)
    {
        vector<int> a;
        vector<int> b;

        int divisor = 1;
        for (int i = 0; i < digit; i++)
        {
            if (bit & (1 << i))
            {
                a.emplace_back((N / divisor) % 10);
            }
            else
            {
                b.emplace_back((N / divisor) % 10);
            }
            divisor *= 10;
        }

        if (a.empty() || b.empty())
            continue;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (a[a.size() - 1] == 0 || b[b.size() - 1] == 0)
            continue;

        ll a_num = 0;
        divisor = 1;
        for (auto x : a)
        {
            a_num += x * divisor;
            divisor *= 10;
        }

        ll b_num = 0;
        divisor = 1;
        for (auto x : b)
        {
            b_num += x * divisor;
            divisor *= 10;
        }

        ans = max(ans, a_num * b_num);

        // cout << "a: ";
        // for (auto x : a)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;

        // cout << "b: ";
        // for (auto x : b)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
    }

    cout << ans << endl;

    return 0;
}
