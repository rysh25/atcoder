#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

int main()
{
    int N, A, B;

    cin >> N >> A >> B;

    int ans = 0;
    int n = 0;
    for (int i = 1; i < N + 1; i++)
    {
        int m = i;
        // cout << "m: " << m << endl;

        int sum = 0;
        while (m > 0)
        {
            int mod = m % 10;
            // cout << "m: " << m << ", mod: " << mod << endl;
            sum += mod;
            m /= 10;
        }

        if (A <= sum && sum <= B)
        {
            ans += i;
            // cout << "sum: " << sum << ", ans=" << ans << endl;
        }
    }

    cout << ans << endl;
}
