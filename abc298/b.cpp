#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<char>> A(N, vector<char>(N)), B(N, vector<char>(N));
    vector<vector<char>> C(N, vector<char>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
            C[i][j] = A[i][j];
            // cout << A[i][j];
        }
        // cout << endl;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> B[i][j];
            // cout << B[i][j];
        }
        // cout << endl;
    }

    for (int count = 0; count < 4; count++)
    {

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                C[i][j] = A[i][j];
                // cout << C[i][j];
            }
            // cout << endl;
        }

        bool eq = true;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                // cout << A[i][j];
                if (C[i][j] == '1' && C[i][j] != B[i][j])
                {
                    eq = false;
                    break;
                }
            }
            // cout << endl;
        }

        // cout << endl;

        if (eq)
        {
            std::cout << "Yes" << endl;
            return 0;
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                A[N - 1 - j][i] = C[i][j];
            }
        }
    }

    std::cout << "No" << endl;

    return 0;
}
