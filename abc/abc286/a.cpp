#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, P, Q, R, S;

    cin >> N >> P >> Q >> R >> S;
    P--, Q--, R--, S--;

    vector<int> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++)
    {
        int o = A[i];
        // cout << "i=" << i << endl;
        if (i >= P && i <= Q)
        {
            // cout << "A[" << R + i - P << "]" << endl;
            o = A[R + i - P];
        }

        if (i >= R && i <= S)
        {
            // cout << "A[" << P + i - R << "]" << endl;
            o = A[P + i - R];
        }

        cout << o << " ";
    }

    cout << endl;

    return 0;
}
