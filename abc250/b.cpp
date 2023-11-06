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
    int N, A, B;

    cin >> N >> A >> B;

    int s = 0;
    char sqares[] = {'.', '#'};
    for (int i = 0; i < N * A; i++)
    {
        int t = s;
        int j = 0;
        for (; j < N * B; j++)
        {
            cout << sqares[t];
            if (j % B == B - 1)
                ++t %= 2;
        }
        cout << endl;

        if (i % A == A - 1)
            ++s %= 2;
    }

    return 0;
}
