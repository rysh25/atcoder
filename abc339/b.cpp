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

    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};

    int di = 0;
    pair<int, int> pos = make_pair(0, 0);

    vector<string> S(H, string(W, '.'));

    // cout << "S:" << endl;
    // for (int i = 0; i < H; i++)
    // {
    //     cout << S[i] << endl;
    // }

    for (int i = 0; i < N; i++)
    {
        if (S[pos.second][pos.first] == '.')
        {
            S[pos.second][pos.first] = '#';
            di = (di + 1) % 4;
            pos = make_pair((pos.first + dx[di] + W) % W, (pos.second + dy[di] + H) % H);
        }
        else
        {
            S[pos.second][pos.first] = '.';
            di = (di + 3) % 4;
            pos = make_pair((pos.first + dx[di] + W) % W, (pos.second + dy[di] + H) % H);
        }

        // cout << "pos: " << pos.first << ", " << pos.second << endl;
        // cout << "S:" << endl;
        // for (int i = 0; i < H; i++)
        // {
        //     cout << S[i] << endl;
        // }
        // cout << endl;
    }

    for (int i = 0; i < H; i++)
    {
        cout << S[i] << endl;
    }

    return 0;
}
