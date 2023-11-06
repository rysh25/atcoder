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
#include <cstdlib>
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
    string T;
    cin >> T;

    pair<int, int> c = make_pair(0, 0);
    pair<int, int> d = make_pair(1, 0);

    rep(i, N)
    {
        // cout << "c=(" << c.first << ", " << c.second << "), d=(" << d.first << ", " << d.second << ")" << endl;
        if (T[i] == 'S')
        {
            c.first += d.first;
            c.second += d.second;
        }
        else
        {
            int tmp = d.first;
            d.first = d.second;
            d.second = -tmp;
        }
    }
    // cout << "c=(" << c.first << ", " << c.second << "), d=(" << d.first << ", " << d.second << ")" << endl;

    cout << c.first << " " << c.second << endl;

    return 0;
}
