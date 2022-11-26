#include <iostream>

using namespace std;

int main()
{
    int N, K;

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        int A;
        cin >> A;
        if (i >= K)
        {
            cout << A << " ";
        }
    }

    for (int i = 0; i < K && i < N; i++)
    {
        cout << "0 ";
    }
    cout << endl;

    return 0;
}
