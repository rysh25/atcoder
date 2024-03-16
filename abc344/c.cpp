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
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    int M;
    cin >> M;
    vector<ll> B(M);
    rep(i, M) cin >> B[i];

    int L;
    cin >> L;
    vector<ll> C(L);
    rep(i, L) cin >> C[i];

    int Q;
    cin >> Q;
    vector<ll> X(Q);
    rep(i, Q) cin >> X[i];

    vector<ll> Y(N * M * L, 0);

    unordered_set<ll> sums;
    for (int a : A)
    {
        for (int b : B)
        {
            for (int c : C)
            {
                sums.insert(a + b + c);
            }
        }
    }

    // cout << "Y: ";
    // rep(i, Y.size())
    // {
    //     cout << Y[i] << " ";
    // }
    // cout << endl;

    for (int i = 0; i < Q; ++i)
    {
        if (sums.count(X[i]))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}
