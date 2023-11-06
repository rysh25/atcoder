#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;

    cin >> N;

    int P[8];
    int Q[8];

    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> Q[i];
    }

    int o[8];

    copy(P, P + 8, o);
    sort(o, o + N);

    int count = 1;

    int a = 0, b = 0;
    do
    {
        if (equal(o, o + N, P))
        {
            a = count;
        }

        if (equal(o, o + N, Q))
        {
            b = count;
        }

        count++;
    } while (next_permutation(o, o + N));

    cout << abs(a - b) << endl;

    return 0;
}
