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
    int N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    vector<int> diff(N, 0);
    for (int i = 1; i < N; ++i)
    {
        diff[i] = (S[i] != S[i - 1]);
    }

    while (Q--)
    {
        int q, L, R;
        cin >> q >> L >> R;

        --L;

        if (q == 1)
        {
        }
        else
        {
            bool isGood = true;
            for (int i = L + 1; i < R; ++i)
            {
                if (!diff[i])
                {
                    isGood = false;
                    break;
                }
            }
            cout << (isGood ? "Yes" : "No") << endl;
        }
    }

    return 0;
}
