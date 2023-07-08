#include <iostream>

using namespace std;

int main()
{
    int prev = 0;
    for (int i = 0; i < 8; i++)
    {
        int S;
        cin >> S;

        if (prev <= S &&
            S >= 100 && S <= 675 &&
            S % 25 == 0)
        {
            // Do nothing
        }
        else
        {
            cout << "No" << endl;
            return 0;
        }

        prev = S;
    }

    cout << "Yes" << endl;

    return 0;
}
