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
    int N;
    cin >> N;

    set<int> st;
    int mx = 0;
    rep(i, N)
    {
        int A;
        cin >> A;
        mx = max(mx, A);
        st.insert(A);
    }

    int mx2 = 0;
    for (int s : st)
    {
        if (s < mx)
        {
            mx2 = max(mx2, s);
        }
    }

    cout << mx2 << endl;

    return 0;
}
