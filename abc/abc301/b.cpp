#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    cout << A[0] << " ";
    int prev = A[0];
    for (int i = 1; i < N; i++)
    {
        if (prev < A[i])
        {
            int j = 1;
            while (prev + j != A[i])
            {
                cout << prev + j << " ";
                j++;
            }
        }
        else
        {
            int j = -1;
            while (prev + j != A[i])
            {
                cout << prev + j << " ";
                j--;
            }
        }

        cout << A[i] << " ";

        prev = A[i];
    }

    cout << endl;

    return 0;
}
