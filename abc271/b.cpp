// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> a(N);

    for (int i = 0; i < N; i++)
    {
        int L;
        cin >> L;
        a[i].resize(L);

        for (auto &l : a[i])
        {
            cin >> l;
        }
    }

    for (int i = 0; i < Q; i++)
    {
        int s, t;
        cin >> s >> t;

        cout << a[s - 1][t - 1] << endl;
    }

    return 0;
}
