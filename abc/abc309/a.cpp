#include <iostream>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    if (A + 1 == B &&
        A % 3 != 0)
    {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;

    return 0;
}
