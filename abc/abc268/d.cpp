// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N, M;
vector<string> S(N);

void concat(int i, vector<string> s)
{
    if (n >= N)
    {
        return "";
    }

    s.push_back(S[i]);
    concat(i++, s);

    return res;
}

int main()
{
    cin >> N >> M;
    map<string, bool> T;

    for (auto &s : S)
    {
        cin >> s;
    }

    for (int i = 0; i < M; i++)
    {
        string t;
        cin >> t;
        T[t] = 0;
    }

    string res = "";
    string us = "_";
    bool found = false;

    while (!found)
    {
        for (int i = 0; i < N; i++)
        {
            if (i > 0)
            {
                res += us;
            }
            res += S[i];
        }
    }

    if (res == "")
    {
        cout << -1 << endl;
        return 0;
    }

    return 0;
}
