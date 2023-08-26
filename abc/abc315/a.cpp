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
    string S;

    cin >> S;

    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == 'a' ||
            S[i] == 'i' ||
            S[i] == 'u' ||
            S[i] == 'e' ||
            S[i] == 'o')
            continue;
        else
            cout << S[i];
    }

    cout << endl;

    return 0;
}
