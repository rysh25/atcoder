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
    int X, Y;
    cin >> X >> Y;

    int ans = Y - X;
    // cout << ans << endl;
    if (ans <= 2 && ans >= -3)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
