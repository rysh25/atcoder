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
    int N;
    cin >> N;

    int A;
    int prev;

    for (int i = 0; i < N; i++)
    {
        cin >> A;

        if (i > 0 && A != prev)
        {
            cout << "No" << endl;
            return 0;
        }
        prev = A;
    }

    cout << "Yes" << endl;

    return 0;
}
