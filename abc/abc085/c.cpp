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
    int N, Y;
    cin >> N >> Y;

    for (int a = 0; a <= N; a++)
    {
        for (int b = 0; b <= N - a; b++)
        {
            int c = N - a - b;
            if (10000 * a + 5000 * b + 1000 * c == Y)
            {
                cout << a << " " << b << " " << c << endl;
                return 0;
            }
        }
    }

    cout << "-1 -1 -1" << endl;

    return 0;
}
