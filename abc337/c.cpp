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

    // vector<int> A(N);
    stack<int> st;

    int top = -1;
    map<int, int> mp;

    rep(i, N)
    {
        int A;
        cin >> A;
        mp[A] = i + 1;
    }

    // cout << "top: " << top << endl;

    int i = -1;
    rep(j, N)
    {
        i = mp[i];
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
