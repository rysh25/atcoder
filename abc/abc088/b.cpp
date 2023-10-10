#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &a : A)
    {
        cin >> a;
    }

    sort(A.rbegin(), A.rend());

    int alice = 0;
    int bob = 0;

    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
            alice += A[i];
        else
            bob += A[i];
    }

    cout << alice - bob << endl;

    return 0;
}
