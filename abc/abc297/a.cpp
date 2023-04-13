#include <iostream>

using namespace std;

int main()
{
    int N, D;
    cin >> N >> D;

    int t;
    cin >> t;
    int prev = t;
    for (int i = 1; i < N; i++)
    {
        cin >> t;

        if (t - prev <= D)
        {
            cout << t << endl;
            return 0;
        }

        prev = t;
    }

    cout << -1 << endl;

    return 0;
}
