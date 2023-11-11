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

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        int D;
        cin >> D;
        if (D == 0)
        {
            // cout << "D==0, i=" << i << ", D=" << D << endl;
            continue;
        }
        else if (i > 10 && i / 10 != i % 10)
        {
            // cout << "i=" << i << ", i/10=" << i / 10 << ", i%10=" << i % 10 << endl;
            continue;
        }

        int w = i % 10;
        if (D < w)
        {
            // pass
        }
        else if (D < w + w * 10)
        {
            // cout << "D==1, i=" << i << ", D=" << D << endl;
            ans++;
        }
        else if (D < w + w * 10 + w * 100)
        {
            // cout << "D==2, i=" << i << ", D=" << D << endl;
            ans += 2;
        }
    }

    cout << ans << endl;

    return 0;
}
