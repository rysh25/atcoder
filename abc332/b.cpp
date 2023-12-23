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
    int K, G, M;
    cin >> K >> G >> M;

    int glass = 0;
    int mug = 0;
    int op = 0;

    rep(op, K)
    {
        if (glass == G)
        {
            // cout << "1: glass == G" << endl;
            glass = 0;
        }
        else if (mug == 0)
        {
            // cout << "2: mug == 0" << endl;
            mug = M;
        }
        else
        {
            // cout << "3: else" << endl;
            int ab_glass = G - glass;
            int move = min(mug, ab_glass);
            glass += move;
            mug -= move;
        }

        // cout << "op: " << op << ", glass: " << glass << ", mug: " << mug << endl;
    }

    cout << glass << " " << mug << endl;

    return 0;
}
