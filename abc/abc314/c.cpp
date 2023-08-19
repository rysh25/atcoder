#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;

    cin >> N >> M;

    string S;
    cin >> S;

    vector<int> C(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> C[i];
    }

    vector<vector<int>> positions(M);
    for (int i = 0; i < N; ++i)
    {
        positions[C[i] - 1].push_back(i);
    }

    string ans = S;

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < positions[i].size(); ++j)
        {
            int newPos = positions[i][(j + 1) % positions[i].size()];
            ans[newPos] = S[positions[i][j]];
        }
    }

    cout << ans << endl;

    return 0;
}
