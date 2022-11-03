// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int N, x, y;

    cin >> N >> x >> y;

    // vector<vector<int>, int> memoX(N, vector<int>(20000));
    // vector<vector<int>, int> memoY(N, vector<int>(20000));

    map<vector<int>, bool> memo;

    vector<int> A(N);

    for (auto &a : A)
    {
        cin >> a;
    }

    auto dfs = [&](auto dfs, int i, int cx, int cy) -> bool
    {
        // cout << "i=" << i << ", X=" << cx << ", Y=" << cy << endl;
        if (i == N - 1)
        {
            if (cx == x && cy == y)
            {
                return true;
            }
            else
            {
                // cout << "--------" << endl;
                return false;
            }
        }

        vector<int> key;
        key.push_back(i);
        key.push_back(cx);
        key.push_back(cy);

        if (memo.count(key) != 0)
        {
            // cout << "find key in memo" << endl;
            return memo[key];
        }

        if (i % 2 == 0)
        {
            if (dfs(dfs, i + 1, cx, cy + A[i + 1]))
            {
                return true;
            }
            else if (dfs(dfs, i + 1, cx, cy - A[i + 1]))
            {
                return true;
            }
            else
            {
                memo[key] = false;
                return false;
            }
        }
        else
        {
            if (dfs(dfs, i + 1, cx + A[i + 1], cy))
            {
                return true;
            }
            else if (dfs(dfs, i + 1, cx - A[i + 1], cy))
            {
                return true;
            }
            else
            {
                memo[key] = false;
                return false;
            }
        }
    };

    if (dfs(dfs, 0, A[0], 0))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
