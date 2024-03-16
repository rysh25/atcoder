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

    bool b = false;
    rep(i, S.size())
    {
        if (!b && S[i] == '|')
        {
            b = true;
            continue;
        }
        else if (b && S[i] == '|')
        {
            b = false;
            continue;
        }

        if (!b)
        {
            cout << S[i];
        }
    }

    cout << endl;

    return 0;
}
