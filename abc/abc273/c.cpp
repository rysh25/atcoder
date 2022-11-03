// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> A(N), B;
    set<int> s;

    for (auto &a : A)
    {
        cin >> a;
        s.insert(a);
    }

    // for (auto &i : s)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    vector<int> ans(N, 0);

    for (int i = 0; i < s.size(); i++)
    {
        ans[s.size() - (i + 1)]++;
    }

    // for (auto &a : A)
    // {
    //     auto iter = s.find(a);
    //     if (iter == s.end())
    //     {
    //         ans[0]++;
    //         // cout << 0 << endl;
    //     }
    //     else
    //     {
    //         int idx = distance(s.begin(), iter);
    //         // cout << s.size() - (idx + 1) << endl;
    //         ans[s.size() - (idx + 1)]++;
    //     }
    // }

    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}
