#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

bool is_palindrome(const string &s)
{
    int left = 0, right = s.size() - 1;
    while (left < right)
    {
        if (s[left] != s[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main()
{
    string S;
    cin >> S;

    int ans = 1;
    for (int i = 0; i < S.size(); i++)
    {
        for (int j = S.size(); j >= 0; j--)
        {
            if (j - i <= ans)
                continue;
            string sub = S.substr(i, j - i);
            if (is_palindrome(sub))
            {
                ans = j - i;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
