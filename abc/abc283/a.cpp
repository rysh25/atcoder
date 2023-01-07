#include <iostream>

using namespace std;

int main()
{
    int A, B;

    cin >> A >> B;

    int res = A;

    for (int i = 0; i < B - 1; i++)
    {
        res *= A;
    }

    cout << res << endl;

    return 0;
}
