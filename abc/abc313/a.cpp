#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;

    cin >> N;

    int P1 = 0;
    cin >> P1;

    int m = 0;

    for (int i = 1; i < N; i++)
    {
        int P;
        cin >> P;

        m = max(m, P);
    }

    if (m < P1)
        cout << 0 << endl;
    else
        cout << m - P1 + 1 << endl;

    return 0;
}
