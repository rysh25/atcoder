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
    int N;
    cin >> N;

    int x = 0, y = 0;

    rep(i, N)
    {
        int X, Y;
        cin >> X >> Y;

        x += X;
        y += Y;
    }

    // cout << x << " " << y << endl;

    if (x > y)
        cout << "Takahashi" << endl;
    else if (x < y)
        cout << "Aoki" << endl;
    else
        cout << "Draw" << endl;

    return 0;
}
