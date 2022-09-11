// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> p(N);

    vector<vector<int>> foods(N);

    for (auto &pi : p)
    {
        cin >> pi;
    }

    for (int i = 0; i < N; i++)
    {
        int a = ((i - 1) % N + N) % N;
        int b = ((i + 1) % N + N) % N;
        int c = i;

        vector<int> f(3);
        f[0] = a;
        f[1] = b;
        f[2] = c;

        foods[i] = f;
    }

    map<int, int> res;

    for (int i = 0; i < N; i++)
    {
        // cout << "food: " << p[i] << endl;
        int a = ((foods[p[i]][0] - i) % N + N) % N;
        int b = ((foods[p[i]][1] - i) % N + N) % N;
        int c = ((foods[p[i]][2] - i) % N + N) % N;

        // cout << "a=" << a << endl;
        // cout << "b=" << b << endl;
        // cout << "c=" << c << endl;
        if (res.find(a) == res.end())
        {
            res[a] = 1;
        }
        else
        {
            res[a]++;
        }

        if (res.find(b) == res.end())
        {
            res[b] = 1;
        }
        else
        {
            res[b]++;
        }

        if (res.find(c) == res.end())
        {
            res[c] = 1;
        }
        else
        {
            res[c]++;
        }
    }

    for (int i = 0; i < res.size(); i++)
    {
        // cout << "res[" << i << "]=" << res[i] << endl;
    }

    int max_i = 0;
    int max_v = 0;
    for (auto iter = res.begin(); iter != res.end(); iter++)
    {
        if (max_v < iter->second)
        {
            max_v = iter->second;
            max_i = iter->first;
        }
    }

    cout << max_v << endl;

    return 0;
}
