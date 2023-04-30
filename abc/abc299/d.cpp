#include <iostream>

using namespace std;

int main()
{
    int N;

    cin >> N;

    int l = 1;
    int r = N;

    while (r - l > 1)
    {
        int m = l + (r - l) / 2;
        cout << "? " << m << endl;

        int p;
        cin >> p;

        if (p == 0)
            l = m;
        else
            r = m;
    }

    cout << "! " << l << endl;

    return 0;
}
