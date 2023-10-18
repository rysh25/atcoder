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
    string S;
    cin >> S;
    int l = 0, r = S.size() - 1;

    bool top = true;
    while (l < r)
    {
        // cout << "l=" << l << ", r=" << r << endl;
        if (S[l] == S[r])
        {
            if (S[l] != 'a')
                top = false;
            l++;
            r--;
        }
        else if (S[r] == 'a')
        {
            if (top)
            {
                r--;
            }
            else
            {
                cout << "No" << endl;
                return 0;
            }
        }
        else
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
