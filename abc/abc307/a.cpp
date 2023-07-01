#include <iostream>

using namespace std;

int main()
{
    int N;

    cin >> N;

    int sum = 0;
    for (int i = 0; i < N * 7; i++)
    {
        int A;
        cin >> A;

        // cout << "A=" << A << " ";

        sum += A;
        if ((i + 1) % 7 == 0)
        {
            cout << sum << " ";
            sum = 0;
        }
    }

    cout << endl;
    return 0;
}
