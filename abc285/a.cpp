#include <iostream>

using namespace std;

int main()
{
    int a, b;

    cin >> a >> b;

    if (a * 2 == b || a * 2 + 1 == b)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
