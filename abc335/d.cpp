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
    int N;
    cin >> N;

    vector<vector<int>> grid(N, vector<int>(N, -2));

    int x = N / 2, y = N / 2;
    grid[x][y] = -1;

    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    int dir = 0, steps = 1, part = 0;

    while (part < N * N - 1)
    {
        for (int s = 0; s < 2; ++s)
        {
            for (int i = 0; i < steps; ++i)
            {
                x += dx[dir];
                y += dy[dir];
                if (x >= 0 && x < N && y >= 0 && y < N)
                {
                    grid[x][y] = part++;
                }
            }
            dir = (dir + 1) % 4;
        }
        steps++;
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (grid[i][j] == -1)
                cout << "T ";
            else
                cout << grid[i][j] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
