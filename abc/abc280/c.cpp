#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

int main()
{
    string S, T;
    cin >> S >> T;

    int N = S.size();

    for (int i = 0; i < N; i++)
    {
        if (S[i] != T[i])
        {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << N + 1 << endl;

    return 0;
}
