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
    int N, L, R;
    cin >> N >> L >> R;
    vector<int> A(N), X(N);

    rep(i, N)
    {
        cin >> A[i];
    }

    rep(i, N)
    {
        X[i] = min(max(A[i], L), R);
    }

    for (int i = 0; i < N; ++i)
    {
        cout << X[i] << " ";
    }
    cout << endl;

    return 0;
}
