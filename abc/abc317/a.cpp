#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

int main()
{
    int N, H, X;
    cin >> N >> H >> X;

    for (int i = 0; i < N; i++)
    {
        int P;
        cin >> P;
        if (H + P >= X)
        {
            cout << (i + 1) << endl;
            return 0;
        }
    }

    return 0;
}
