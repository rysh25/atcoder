#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N, P, Q;
    cin >> N >> P >> Q;

    int min_D = 1e9 + 1;
    for (int i = 0; i < N; i++)
    {
        int D;
        cin >> D;
        min_D = min(min_D, D);
    }

    if (P > Q + min_D)
    {
        cout << Q + min_D << endl;
    }
    else
    {
        cout << P << endl;
    }

    return 0;
}
