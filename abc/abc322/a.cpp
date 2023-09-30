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
    string S;
    cin >> S;

    for (int i = 2; i < N; ++i)
    {
        if (S[i - 2] == 'A' && S[i - 1] == 'B' && S[i] == 'C')
        {
            cout << i - 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
