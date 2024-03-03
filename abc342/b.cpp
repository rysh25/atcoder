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
    vector<int> p(N);
    rep(i, N)
    {
        int P;
        cin >> P;
        P--;

        p[i] = P;
    }
    int Q;
    cin >> Q;

    while (Q--)
    {
        int A, B;
        cin >> A >> B;
        A--, B--;

        if (p[A] > p[B])
        {
            cout << B + 1 << endl;
        }
        else
        {
            cout << A + 1 << endl;
        }
    }

    return 0;
}
