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
    string S, T;
    cin >> S;
    cin >> T;

    int sl1 = abs(S[0] - S[1]);
    int sl2 = 5 - sl1;
    int tl1 = abs(T[0] - T[1]);
    int tl2 = 5 - tl1;

    if ((sl1 == tl1 || sl1 == tl2) && (sl2 == tl1 || sl2 == tl2))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
