#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> A(N, 0);

    int parity = 0;

    for (int i = 0; i < N; i++)
    {
        cout << "?";
        for (int j = 0; j < K - 1; j++)
        {
            cout << " " << ((i + j) % N) + 1;
        }
        cout << " " << (i + K - 1) % N + 1 << endl;
        cout.flush();

        int T;
        cin >> T;
        if (T == -1)
        {
            return 0;
        }

        if (i == 0)
        {
            parity = T;
            continue;
        }

        if (parity == T)
        {
            A[(i + K - 1) % N] = 0;
        }
        else
        {
            A[(i + K - 1) % N] = 1;
        }

        parity = T;
    }

    A[(N + K - 1) % N] = parity;

    cout << "!";
    for (int i = 0; i < N; ++i)
    {
        cout << " " << A[i];
    }
    cout << endl;
    cout.flush();

    return 0;
}
