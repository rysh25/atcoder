
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int res = 1e9 + 1;
    for (int k = 0; k < 2e5; k++)
    {
        int a = (2 * C * k) + (max(X - k, 0) * A) + (max(Y - k, 0) * B);
        res = min(res, a);
    }

    cout << res << endl;

    return 0;
}
