// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> res(N, 0);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        res[a - 1]++;
        res[b - 1]++;
    }

    for (auto &r : res)
    {
        cout << r << endl;
    }

    return 0;
}
