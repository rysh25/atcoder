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

    vector<int> A(N);

    rep(i, N)
    {
        cin >> A[i];
    }

    ll a = 0, b = 0, c = 0, d = 0;

    for (int i = 0; i < N; i++)
    {
        if (A[i] == 100)
            a += 1;
        if (A[i] == 200)
            b += 1;
        if (A[i] == 300)
            c += 1;
        if (A[i] == 400)
            d += 1;
    }

    cout << a * d + b * c << endl;

    return 0;
}
