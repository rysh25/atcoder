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
    string S;
    cin >> S;

    map<char, int> m;
    rep(i, S.size())
    {
        m[S[i]]++;
    }

    for (auto x : m)
    {
        if (x.second == 1)
        {
            rep(i, S.size())
            {
                if (S[i] == x.first)
                {
                    cout << i + 1 << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
