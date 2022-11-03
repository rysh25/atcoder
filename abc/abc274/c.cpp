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

    vector<int> res(2 * N + 1);

    for (int i = 0; i < N; i++)
    {
        int A;
        cin >> A;
        A--;
        res[2 * (i + 1) - 1] = res[A] + 1;
        res[2 * (i + 1)] = res[A] + 1;
    }

    for (auto &r : res)
    {
        cout << r << endl;
    }

    return 0;
}
