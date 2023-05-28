#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;

    cin >> N >> M;

    vector<vector<int>> A(M, vector<int>(N));

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
            A[i][j]--;
        }
    }

    vector<vector<bool>> friends(N, vector<bool>(N, false));

    for (int i = 0; i < M; i++)
    {
        int prev = A[i][0];
        for (int j = 1; j < N; j++)
        {
            // cout << "prev=" << prev << ", A[" << i << "][" << j << "]=" << A[i][j] << endl;
            friends[prev][A[i][j]] = true;
            friends[A[i][j]][prev] = true;
            prev = A[i][j];
        }
    }
    // vector<pair<int, int>> bad;
    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            // cout << "friends[" << i << "][" << j << "]=" << friends[i][j] << endl;
            if (!friends[i][j])
            {
                // bad.emplace_back(i, j);
                ans++;
            }
        }
    }

    // for (int i = 0; i < bad.size(); i++)
    // {
    //     cout << bad[i].first + 1 << " " << bad[i].second + 1 << endl;
    // }
    cout << ans << endl;

    return 0;
}
