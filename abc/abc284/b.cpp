#include <iostream>

using namespace std;

int main()
{
    int T, N;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N;

        int res = 0;
        for (int j = 0; j < N; j++)
        {
            int A;
            cin >> A;

            if (A % 2 == 1)
            {
                res++;
            }
        }
        cout << res << endl;
    }

    return 0;
}
