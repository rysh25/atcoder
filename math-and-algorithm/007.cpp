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
    int N, X, Y;
    cin >> N >> X >> Y;

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i % X == 0 || i % Y == 0)
            ans++;
    }

    cout << ans << endl;

    return 0;
}
