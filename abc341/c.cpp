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
    int H, W, N;
    cin >> H >> W >> N;

    string T;
    cin >> T;

    vector<string> S(H);
    rep(i, H)
    {
        cin >> S[i];
    }

    vector<vector<bool>> possible(H, vector<bool>(W, false));
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (S[i][j] == '.')
            {
                possible[i][j] = true;
            }
        }
    }
    for (int step = N - 1; step >= 0; --step)
    {
        vector<vector<bool>> next_possible(H, vector<bool>(W, false));
        for (int i = 0; i < H; ++i)
        {
            for (int j = 0; j < W; ++j)
            {
                if (!possible[i][j])
                    continue;
                if (T[step] == 'L' && j + 1 < W && S[i][j + 1] == '.')
                    next_possible[i][j + 1] = true;
                if (T[step] == 'R' && j - 1 >= 0 && S[i][j - 1] == '.')
                    next_possible[i][j - 1] = true;
                if (T[step] == 'U' && i + 1 < H && S[i + 1][j] == '.')
                    next_possible[i + 1][j] = true;
                if (T[step] == 'D' && i - 1 >= 0 && S[i - 1][j] == '.')
                    next_possible[i - 1][j] = true;
            }
        }
        possible = next_possible;
    }

    int count = 0;
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (possible[i][j])
                ++count;
        }
    }

    cout << count << endl;

    return 0;
}
