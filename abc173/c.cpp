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
    int H, W, K;
    cin >> H >> W >> K;

    vector<int> C(W);
    vector<int> R(H);

    vector<string> S(H);
    for (int r = 0; r < H; r++)
    {
        cin >> S[r];
    }

    int ans = 0;
    for (int h_bit = 0; h_bit < (1 << H); h_bit++)
    {
        for (int w_bit = 0; w_bit < (1 << W); w_bit++)
        {
            int count = 0;
            for (int h = 0; h < H; h++)
            {
                for (int w = 0; w < W; w++)
                {
                    if (h_bit & (1 << h))
                    {
                        continue;
                    }
                    if (w_bit & (1 << w))
                    {
                        continue;
                    }

                    count += S[h][w] == '#' ? 1 : 0;
                }
            }

            if (count == K)
            {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
