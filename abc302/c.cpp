#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<string> S(N);

    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }

    sort(S.begin(), S.end());

    do
    {
        string prev = S[0];
        // cout << "prev=" << prev << endl;
        bool found = true;
        for (int i = 1; i < N; i++)
        {
            int unmatch = 0;
            for (int j = 0; j < M; j++)
            {
                if (prev[j] != S[i][j])
                {
                    unmatch++;
                }
            }

            if (unmatch > 1)
            {
                found = false;
                break;
            }

            prev = S[i];
            // cout << "prev=" << prev << endl;
        }

        if (found)
        {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(S.begin(), S.end()));

    cout << "No" << endl;

    return 0;
}
