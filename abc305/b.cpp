#include <iostream>

using namespace std;

int main()
{
    char p, q;

    cin >> p >> q;

    int P = p - 'A';
    int Q = q - 'A';

    // cout << (int)p << ", " << (int)q << endl;

    // cout << "P=" << P << ", Q=" << Q << endl;

    int dist[] = {0, 3, 1, 4, 1, 5, 9};

    for (int i = 1; i < 7; i++)
    {
        dist[i] = dist[i - 1] + dist[i];
    }

    // for (int i = 0; i < 7; i++)
    // {
    //     cout << "dist[" << i << "] = " << dist[i] << ", " << endl;
    // }

    if (P > Q)
        swap(P, Q);

    int ans = dist[Q] - dist[P];

    cout << ans << endl;

    return 0;
}
