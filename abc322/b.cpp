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
    int N, M;
    cin >> N >> M;

    string S, T;
    cin >> S >> T;

    bool is_prefix = true, is_suffix = true;

    for (int i = 0; i < N; ++i)
    {
        // cout << "i=" << i << endl;
        // cout << "S[i]=" << S[i] << ", T[i]=" << T[i] << endl;
        // cout << "S[i]=" << S[i] << ", T[M-N+1]=" << T[M - N + 1] << endl;
        if (S[i] != T[i])
            is_prefix = false;
        if (S[i] != T[M - N + i])
            is_suffix = false;
    }

    if (is_prefix && is_suffix)
        cout << 0 << endl;
    else if (is_prefix)
        cout << 1 << endl;
    else if (is_suffix)
        cout << 2 << endl;
    else
        cout << 3 << endl;

    return 0;
}
