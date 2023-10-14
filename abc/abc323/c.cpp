#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    vector<string> S(N);

    rep(i, M) cin >> A[i];
    rep(i, N) cin >> S[i];

    vector<int> scores(N, 0);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (S[i][j] == 'o')
            {
                scores[i] += A[j];
            }
        }
        scores[i] += i + 1;
    }

    // cout << "scores: " << endl;
    // rep(i, N)
    // {
    //     cout << scores[i] << " ";
    // }
    // cout << endl;

    int max_score = *max_element(scores.begin(), scores.end());
    // cout << "max_score: " << max_score << endl;

    for (int i = 0; i < N; i++)
    {
        vector<int> unsolved;
        for (int j = 0; j < M; j++)
        {
            if (S[i][j] == 'x')
            {
                unsolved.push_back(A[j]);
            }
        }
        sort(unsolved.rbegin(), unsolved.rend());

        int count = 0;
        int current_score = scores[i];
        // cout << "current_score: " << current_score << endl;
        if (current_score == max_score)
        {
            cout << 0 << "\n";
            continue;
        }

        for (int j = 0; current_score <= max_score && j < unsolved.size(); j++)
        {
            current_score += unsolved[j];
            count++;
        }

        // cout << "current_score: " << current_score << endl;

        cout << count << "\n";
    }

    return 0;
}
