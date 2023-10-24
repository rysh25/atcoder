#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
#include <cmath>
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

int main()
{
    int N, S;
    cin >> N >> S;

    int ans = 0;
    for (int i = 1; i < min(N + 1, S); i++)
    {
        // cout << "i=" << i << ",  min(N, S - i)=" << min(N, S - i) << endl;
        ans += min(N, S - i);
    }

    cout << ans << endl;

    return 0;
}
