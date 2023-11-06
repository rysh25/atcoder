// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;

    cin >> N;
    vector<int> A(N);

    int m = 0;
    for (auto &a : A)
    {
        cin >> a;
        m = max(m, a);
    }

    int max_gdc = 0;
    int max_i = 0;
    for (int i = 2; i < m + 1; i++)
    {
        int gdc = 0;
        for (auto &a : A)
        {
            if (a % i == 0)
            {
                // cout << a << " is divisible by " << i << endl;
                gdc++;
            }
        }
        if (max_gdc < gdc)
        {
            max_gdc = gdc;
            max_i = i;
        }
    }

    cout << max_i << endl;

    return 0;
}
