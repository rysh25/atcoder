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
    int N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    vector<int> prefix_streak_count(N + 1, 0);

    char prev = ' ';
    for (int i = 0; i < N; i++)
    {
        if (S[i] == prev)
        {
            prefix_streak_count[i + 1] = prefix_streak_count[i] + 1;
        }
        else
        {
            prefix_streak_count[i + 1] = prefix_streak_count[i];
        }
        prev = S[i];
    }

    for (int i = 0; i < Q; i++)
    {
        int l, r;
        cin >> l >> r;

        cout << prefix_streak_count[r] - prefix_streak_count[l] << endl;
    }

    return 0;
}
