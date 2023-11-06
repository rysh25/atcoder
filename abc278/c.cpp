#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int N, Q;

    cin >> N >> Q;

    vector<set<int>> Twidai(N);

    vector<int> T(Q), A(Q), B(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> T[i] >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }

    for (int i = 0; i < Q; i++)
    {

        switch (T[i])
        {
        case 1:
            Twidai[A[i]].insert(B[i]);
            // cout << A[i] << " Follow " << B[i] << endl;
            break;
        case 2:
            if (Twidai[A[i]].find(B[i]) != Twidai[A[i]].end())
            {
                Twidai[A[i]].erase(B[i]);
            }
            // cout << A[i] << " Unfolow " << B[i] << endl;
            break;
        case 3:
            if (Twidai[A[i]].find(B[i]) == Twidai[A[i]].end() ||
                Twidai[B[i]].find(A[i]) == Twidai[B[i]].end())
            {
                cout << "No" << endl;
            }
            else
            {
                cout << "Yes" << endl;
            }
            break;
        }
    }

    return 0;
}
