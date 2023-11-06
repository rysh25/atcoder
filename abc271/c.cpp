// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> a(N);

    for (auto &w : a)
    {
        cin >> w;
    }
    sort(a.begin(), a.end());

    long long res = 0;
    for (long long i = 0; i < N;)
    {
        if (a[i] == res + 1)
        {
            i++;
            res++;
            continue;
        }

        if (N - i < 2)
        {
            break;
        }

        N -= 2;
        res++;
    }

    cout << res << endl;

    return 0;
}
