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
// #include <cstdlib>
#include <limits>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
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

int main()
{
    int N, S, M, L;
    cin >> N >> S >> M >> L;

    int ans = 1e9 + 1;

    for (int s = 0; s * 6 <= N + 6; s++)
    {
        for (int m = 0; m * 8 <= (N + 8) - s * 6; m++)
        {
            int l = N - s * 6 - m * 8;
            l = (l + 11) / 12;
            // cout << "s: " << s << ", m: " << m << ", l: " << l << endl;

            if (l < 0)
            {
                continue;
            }

            ans = min(ans, S * s + M * m + L * l);
        }
    }

    cout << ans << endl;

    return 0;
}
