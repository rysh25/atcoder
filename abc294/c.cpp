#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;

    cin >> N >> M;

    int inf = 1e9 + 1;

    vector<int> A(N + 1), B(M + 1), C(N + M);
    A[N] = inf, B[M] = inf;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        C[i] = A[i];
    }
    for (int i = 0; i < M; i++)
    {
        cin >> B[i];
        C[N + i] = B[i];
    }

    sort(C.begin(), C.end());

    // cout << "C: ";
    // for (int i = 0; i < N + M; i++)
    //     cout << i + 1 << "=" << C[i] << " ";
    // cout << endl;

    C.emplace_back(0);

    int ai = 0, bi = 0;
    vector<int> bres;
    while (ai + bi <= N + M)
    {
        // cout << "ai=" << ai << ", bi=" << bi << endl;
        if (C[ai + bi] == A[ai])
        {
            cout << ai + bi + 1 << " ";
            ai++;
        }
        else
        {
            bres.emplace_back(ai + bi + 1);
            bi++;
        }
    }

    cout << endl;
    for (int i = 0; i < M; i++)
        cout << bres[i] << " ";
    cout << endl;

    return 0;
}
