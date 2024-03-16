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
    string T;
    cin >> T;
    int N;
    cin >> N;
    vector<vector<string>> bags(N);
    for (int i = 0; i < N; ++i)
    {
        int A;
        cin >> A;
        bags[i].resize(A);
        for (int j = 0; j < A; ++j)
        {
            cin >> bags[i][j];
        }
    }

    vector<int> dp(T.length() + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < N; ++i)
    {
        vector<int> new_dp = dp;
        for (auto &str : bags[i])
        {
            for (int j = 0; j <= T.length(); ++j)
            {
                if (dp[j] != INT_MAX && j + str.length() <= T.length() && T.substr(j, str.length()) == str)
                {
                    new_dp[j + str.length()] = min(new_dp[j + str.length()], dp[j] + 1);
                }
            }
        }
        dp = move(new_dp);
    }

    cout << (dp[T.length()] != INT_MAX ? dp[T.length()] : -1) << endl;

    return 0;
}
