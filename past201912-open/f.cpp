#include <iostream>
#include <iomanip>
#include <sstream>
#include <list>
#include <utility>
#include <string>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <climits>
#include <cstring>
// #include <cstdlib>
#include <limits>
#include <algorithm>
#include <functional>
#include <vector>
#include <tuple>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

int main()
{
    string S;
    cin >> S;

    int l = 0, r = 0;
    vector<string> words;
    while (l < S.size())
    {
        if (l == r)
        {
            r++;
            while (!isupper(S[r]))
            {
                r++;
            }
        }
        // cout << "l=" << l << ", r=" << r << endl; // debug
        string word = S.substr(l, r - l + 1);
        word[0] = tolower(word[0]);
        word.back() = tolower(word.back());
        // cout << "word=" << word << endl; // debug
        words.emplace_back(word);
        r++;
        l = r;
    }

    sort(words.begin(), words.end());
    string ans = "";
    for (auto word : words)
    {
        word[0] = toupper(word[0]);
        word.back() = toupper(word.back());
        ans += word;
    }

    cout << ans << endl;

    return 0;
}
