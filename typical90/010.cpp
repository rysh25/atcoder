// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main()
{
    int N;

    cin >> N;
    // N = 7;

    vector<vector<int>> sum(2, vector<int>(N + 1, 0));
    for (int i = 1; i < N + 1; i++)
    {
        int C, P;
        cin >> C >> P;

        sum[0][i] = sum[0][i - 1];
        sum[1][i] = sum[1][i - 1];
        sum[C - 1][i] += P;
    }

    int Q;
    cin >> Q;

    vector<string> res(Q);

    for (int j = 0; j < Q; j++)
    {
        int L, R;
        cin >> L >> R;

        int A = sum[0][R] - sum[0][L - 1];
        int B = sum[1][R] - sum[1][L - 1];

        res.push_back(to_string(A) + " " + to_string(B));
    }

    for (size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }

    return 0;
}
