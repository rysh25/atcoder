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
    int N, M;
    cin >> N >> M;

    string S;
    cin >> S;

    int ans = 0;
    int logo = 0;
    int m = M;
    rep(i, N)
    {
        if (S[i] == '1')
        {
            if (m == 0 && logo == 0)
            {
                ans++;
            }
            else
            {
                if (m > 0)
                {
                    m--;
                }
                else if (logo > 0)
                {
                    logo--;
                }
            }
        }
        else if (S[i] == '2')
        {
            if (logo == 0)
            {
                ans++;
            }
            else
            {
                logo--;
            }
        }
        else
        {
            m = M;
            logo = ans;
        }
    }

    cout << ans << endl;

    return 0;
}
