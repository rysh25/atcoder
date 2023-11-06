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

    string T;
    cin >> T;

    vector<int> ans;
    rep(i, N)
    {
        // cout << "\ni=" << i << endl;
        string S;
        cin >> S;

        // cout << "S=" << S << ", T.size()=" << T.size() << ", S.size()=" << S.size() << endl;
        // cout << "T.size() - S.size()=" << (int)T.size() - (int)S.size() << endl;
        // cout << ((N - S.size()) > 1) << endl;
        // cout << (N - S.size() < -1) << endl;
        if ((int)T.size() - (int)S.size() == 0 ||
            (int)T.size() - (int)S.size() == 1 ||
            (int)T.size() - (int)S.size() == -1)
        {
        }
        else
        {
            // cout << "continue2" << endl;
            continue;
        }

        string s1 = T.size() > S.size() ? S : T;
        string s2 = T.size() > S.size() ? T : S;

        int s1i = 0;
        int s2i = 0;
        // cout << "s1=" << s1 << ", s2=" << s2 << endl;
        bool ok = true;
        if (T.size() == S.size())
        {
            // cout << "T.size() == S.size()" << endl;
            bool skip = false;
            while (s1i < s1.size() && s2i < s1.size())
            {
                if (s1[s1i] != s2[s2i])
                {
                    // cout << "s1[s1i]=" << s1[s1i] << ", s2[s2i]=" << s2[s2i] << endl;
                    if ('a' <= s1[s1i] && s1[s1i] <= 'z' && 'a' <= s2[s2i] && s2[s2i] <= 'z')
                    {
                        if (!skip)
                        {
                            skip = true;
                            s1i++;
                            s2i++;
                            continue;
                        }
                    }
                    ok = false;
                    break;
                }
                s1i++;
                s2i++;
            }
            if (!ok)
                continue;
        }
        else
        {
            // cout << "T.size() != S.size()" << endl;
            while (s1i < s1.size() && s2i < s2.size() && s2i - s1i < 2)
            {
                // cout << "s1[s1i]=" << s1[s1i] << ", s2[s2i]=" << s2[s2i] << endl;
                if (s1[s1i] != s2[s2i])
                {
                    // cout << "skip" << endl;
                    s2i++;
                    continue;
                }
                s1i++;
                s2i++;
            }

            if (s2i - s1i > 1)
            {
                continue;
            }
        }

        ans.push_back(i + 1);
    }

    cout << ans.size() << endl;
    for (auto a : ans)
    {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}
