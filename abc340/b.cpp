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
    int Q;
    cin >> Q;

    vector<int> a;

    while (Q--)
    {
        int q, x;
        cin >> q >> x;

        if (q == 1)
        {
            a.push_back(x);
        }
        else if (q == 2)
        {
            cout << a[a.size() - x] << endl;
        }
    }

    return 0;
}
