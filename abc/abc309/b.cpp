#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    // cout << "N = " << N << endl;

    vector<string> S(N);
    vector<string> T(N);

    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }

    for (int i = 0; i < N; i++)
    {
        T[i] = S[i];
    }

    // for (int i = 0; i < N; i++)
    // {
    //     cout << S[i] << endl;
    // }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == 0 && j > 0)
            {
                T[i][j] = S[i][j - 1];
            }
            else if (i == N - 1 && j < N - 1)
            {
                T[i][j] = S[i][j + 1];
            }
            else if (j == 0)
            {
                T[i][j] = S[i + 1][j];
            }
            else if (j == N - 1)
            {
                T[i][j] = S[i - 1][j];
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << T[i] << endl;
    }
}
